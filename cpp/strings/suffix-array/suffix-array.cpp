// Suffix array construction in O(L logˆ2 L) time.  Routine for
// computing the length of the longest common prefix of any two
// suffixes in O(log L) time.
//
// INPUT:   string s
//
// OUTPUT:  array suffix[] such that suffix[i] = index (from 0 to L-1)
//          of substring s[i...L-1] in the list of sorted suffixes.
//          That is, if we take the inverse of the permutation suffix[],
//          we get the actual suffix array.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct SuffixArray {
  const int L;
  string s;
  vector<vector<int>> P;
  vector<pair<pair<int, int>, int>> M;

  SuffixArray(const string &s)
      : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
    for (int i = 0; i < L; i++)
      P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {

      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++)
        M[i] =
            make_pair(make_pair(P[level - 1][i],
                                i + skip < L ? P[level - 1][i + skip] : -1000),
                      i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
        P[level][M[i].second] = (i > 0 && M[i].first == M[i - 1].first)
                                    ? P[level][M[i - 1].second]
                                    : i;
    }
  };

  vector<int> getSuffixArray() { return P.back(); }

  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j)
      return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
        i += 1 << k;
        j += 1 << k;
        len += 1 << k;
      }
    }
    return len;
  };
  void printSuffixArray() {
    vector<int> v = getSuffixArray();
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << '\t';
    }
    cout << endl;
  }
};
int main(int argc, char const *argv[]) {
  /* code */
  SuffixArray suffix("banana");
  suffix.printSuffixArray();
  cout<< "Longest common prefix " << suffix.LongestCommonPrefix(2, 4);
  return 0;
};
