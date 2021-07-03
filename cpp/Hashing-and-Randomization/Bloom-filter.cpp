#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define ll long long
using namespace std;

class BloomFilter {
public:
  vector<bool> bitarray;
  int size;
  BloomFilter(int m) {
    bitarray.resize(m,false);
    size = m;
  }
  void insert(string s) {
    // check if the element in already present or not
    if (lookup(s))
      cout << (string)s << " is Probably already present" << endl;
    else {
      int a = hash1(s);
      int b = hash2(s);
      int c = hash3(s);
      int d = hash4(s);

      bitarray[a] = true;
      bitarray[b] = true;
      bitarray[c] = true;
      bitarray[d] = true;

      //   cout << s << " inserted" << endl;
    }
  }
  bool lookup(string s) {
    int a = hash1(s);
    int b = hash2(s);
    int c = hash3(s);
    int d = hash4(s);

    if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
      return true;
    else
      return false;
  }

protected:
  // hash 1
  int hash1(string s) {
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++) {
      hash = (hash + ((int)s[i]));
      hash = hash % size;
    }
    return hash;
  }

  // hash 2
  int hash2(string s) {
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++) {
      hash = hash + pow(19, i) * s[i];
      hash = hash % size;
    }
    return hash % size;
  }

  // hash 3
  int hash3(string s) {
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++) {
      hash = (hash * 31 + s[i]) % size;
    }
    return hash % size;
  }

  // hash 4
  int hash4(string s) {
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
      hash += hash * 7 + s[0] * pow(p, i);
      hash = hash % size;
    }
    return hash;
  }
};
int main() {
  BloomFilter bm(100);

  string sarray[33] = {
      "abound",   "abounds",       "abundance",  "abundant", "accessable",
      "bloom",    "blossom",       "bolster",    "bonny",    "bonus",
      "bonuses",  "coherent",      "cohesive",   "colorful", "comely",
      "comfort",  "gems",          "generosity", "generous", "generously",
      "genial",   "bluff",         "cheater",    "hate",     "war",
      "humanity", "racism",        "hurt",       "nuke",     "gloomy",
      "facebook", "geeksforgeeks", "twitter"};
  for (int i = 0; i < 33; i++) {
    // insert(bitarray, arrSize, sarray[i]);
    bm.insert(sarray[i]);
  }
  std::cout << bm.lookup("twitter") << std::endl;
  std::cout << bm.lookup("Henlo") << std::endl;
  return 0;
}
