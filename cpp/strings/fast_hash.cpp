#include <iostream>
#include <string>

using namespace std;
const int p = 31;
const int m = 1e9 + 9;

long long compute_hash(string const &s) {

  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

long long calculatefashHash(string s, int i, int j) {
  long long hash_value = 0;
  hash_value = (compute_hash(s.substr(0, j)) - compute_hash(s.substr(0, i - 1))) % m;
  return hash_value;
}


int main(int argc, char const *argv[]) {
  int i = 1, j = 5;
  string s = "Henloworld";
  std::cout << s << '\t'<< calculatefashHash(s, i, j) << std::endl;
  for (int k=0; k < s.size(); k+=(j-i)) {
   std::cout << s.substr(k,k+(j-i)) <<std::endl;
  }
  // for (char c:s){
  //   std::cout << s.substr(c,j) << '\t'<< compute_hash(s.substr(i,j)) << std::endl;
  // }
  
  return 0;
}
