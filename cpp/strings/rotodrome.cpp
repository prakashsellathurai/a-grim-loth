#include <iostream>
#include <string>

bool rotodrome_match(std::string a,
                std::string b)
{
  int n = a.length();
  int m = b.length();
  if (n != m)
    return false;
 
  // create lps[] that
  // will hold the longest
  // prefix suffix values
  // for pattern
  int lps[n];
 
  // length of the previous
  // longest prefix suffix
  int len = 0;
  int i = 1;
   
  // lps[0] is always 0
  lps[0] = 0;
 
  // the loop calculates
  // lps[i] for i = 1 to n-1
  while (i < n)
  {
    if (a[i] == b[len])
    {
      lps[i] = ++len;
      ++i;
    }
    else
    {
      if (len == 0)
      {
        lps[i] = 0;
        ++i;
      }
      else
      {
        len = lps[len - 1];
      }
    }
  }
 
  i = 0;
 
  // Match from that rotating
  // point
  for (int k = lps[n - 1];
           k < m; ++k)
  {
    if (b[k] != a[i++])
      return false;
  }
  return true;
}
 
int main(int argc, const char **argv) {
  std::string w1 = "upwind";
  std::string w2 = "windup";

  std::cout << rotodrome_match(w1, w2) << std::endl; 
  std::cout << rotodrome_match(w1, "w2w2w2w") << std::endl;
  ;
  return 0;
}
