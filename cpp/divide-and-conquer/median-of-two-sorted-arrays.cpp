#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Median of two sorted subarrays using divide and conquer in O(log(m+n))
 *
 * @param a
 * @param b
 * @return double
 */
double Median_of_two_sorted_arrays(vector<int> &a, vector<int> &b) {
  int m = a.size();
  int n = b.size();
  if (m > n)
    return Median_of_two_sorted_arrays(b, a);
  int l = 0, r = m;
  while (l <= r) {
    int partx = l + (r - l) / 2;
    int party = (m + n + 1) / 2 - partx;

    int maxlx = (partx == 0) ? INT_MIN : a[partx - 1];
    int minrx = (partx == m) ? INT_MAX : a[partx];
    
    int maxly = (party == 0) ? INT_MIN : b[party - 1];
    int minry = (party == n) ? INT_MAX : b[party];



    if (maxlx <= minry && maxly <= minrx) {
      if ((m + n) % 2 == 0)
        return (double)(max(maxlx, maxly) + min(minrx, minry)) / 2;
      else
        return (double)(max(maxlx, maxly));
    } else if (maxlx > minry)
      r = partx - 1;
    else
      l = partx + 1;
  }
  return -1.0;
}
int main(int argc, const char **argv) {
  vector<int> A = {900, 11};
  vector<int> B = {5, 8, 10, 20};
  std::cout << "Median_of_two_sorted_arrays "
            << Median_of_two_sorted_arrays(A, B) << std::endl;
  return 0;
}