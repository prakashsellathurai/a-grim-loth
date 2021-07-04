#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stdint.h>
#include <vector>

using namespace std;

/**
 * @brief Min hash implementation for document lookup in O(n*k)
 *
 */
class MinHash {
public:
  int k = 2; // number of hash functions
  vector<vector<uint64_t>> MinHashindex;

  MinHash(set<set<string>> docs) {
    MinHashindex.resize(k);
    for (auto doc : docs) {

      for (int i = 0; i < k; i++) {
        priority_queue<uint64_t> pq;
        for (auto str : doc) {
          pq.push(Hash_generator(i, str));
        }
        MinHashindex[i].push_back(pq.top());
      }
    }
  }
  /**
   * @brief look up hashes the new doc and checks with minhashtable with time
   * complexity : O(k*n)
   *
   * @param doc
   */
  bool lookup(set<string> doc) {
    vector<uint64_t> new_doc;
    for (int i = 0; i < k; i++) {
      priority_queue<uint64_t> new_doc_pq;
      for (auto str : doc) {
        new_doc_pq.push(Hash_generator(i, str));
      }
      new_doc.push_back(new_doc_pq.top());
    }

    bool isMatch_Found = false;

    for (int i = 0; i < k; i++) {

      for (int j = 0; j < MinHashindex[i].size(); j++) {
        if (hash_compare_in_probability(MinHashindex[i][j], new_doc.at(i)) ==
            1) {
          std::cout << "Match Found" << std::endl;
          std::cout << std::endl;
          isMatch_Found = true;
          return true;
        }
      }
    }
    std::cout << "Match  Not Found" << std::endl;
    std::cout << std::endl;
    return isMatch_Found;
    
  }

protected:
  uint64_t Hash_generator(int code, string s) {
    switch (code) {
    case 0:
      return CalculateHash_1(s);
    case 1:
      return CalculateHash_2(s);
    }
    return 0;
  }

  float hash_compare_in_probability(uint64_t hash1, uint64_t hash2) {
    return (float)((float)min(hash1, hash2) / (float)max(hash1, hash2));
  }

  uint64_t CalculateHash_1(string s) {
    uint64_t hash;
    uint64_t p = 26, m = 1e9 + 9, p_pow = 1;
    for (int i = 0; i < s.length(); i++) {
      hash = (hash + (s[i] - 'a' + 1) * p_pow) % m;
      p_pow = (p_pow * p) % m;
    }
    return hash;
  }
  uint64_t CalculateHash_2(string s) {
    uint64_t hash;
    uint64_t p = 26, m = 1e9 + 9, p_pow = 1;
    for (int i = 0; i < s.length(); i++) {
      hash = (hash + (s[i] - 'a' + 1) * p_pow * p_pow) % m;
      p_pow = (p_pow * p) % m;
    }
    return hash;
  }
  double jaccard_similarity_on_sets(set<uint64_t> set1, set<uint64_t> set2) {
    double n = set1.size(), m = set2.size();

    set<uint64_t> intersect;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     inserter(intersect, intersect.begin()));
    double size_in = intersect.size();

    return (double)(1 - (size_in / (size_in + m - n)));
  }
};
int main(int argc, const char **argv) {
  set<set<string>> Docs = {
      {"the", "cat", "is", "grumpy"},
      {"the", "dog", "is", "coufy"},
      {"gwalihir", "gandalf", "islidur", "frodo", "aragorn"}};

  MinHash mh(Docs);

  std::cout << "Look up doc { the, cat, is, grumpy} " << std::endl;
  mh.lookup({"the", "cat", "is", "grumpy"});
  std::cout << "Look up doc {make, love, n0t, war} " << std::endl;
  mh.lookup({"make", "love", "n0t", "war"});

  return 0;
}