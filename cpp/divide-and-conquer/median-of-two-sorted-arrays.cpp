#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief get median_of_four_integers
 *
 * @param a
 * @param b
 * @param c
 * @param d
 * @return float
 */
double median_of_four_integers(int a, int b, int c, int d) {
  return (a + b + c + d - max(a, max(b, max(c, d))) -
          min(a, min(b, min(c, d)))) /
         2.0;
}
/**
 * @brief Get median of three integers
 *
 * @param a
 * @param b
 * @param c
 * @return float
 */
double median_of_three_integers(int a, int b, int c) {
  return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

/**
 * @brief Get median of two integers
 *
 * @param a
 * @param b
 * @return float
 */
double median_of_two_integers(int a, int b) { return (a + b) / 2.0; }

/**
 * @brief Get median of a vector
 *
 * @param arr
 * @param n
 * @return float
 */
double median_of_a_array(vector<int> arr, int n) {
  if (n == 0)
    return -1;
  if (n % 2 == 0)
    return (double)(arr[n / 2] + arr[(n / 2) - 1]) / 2.0;
  else
    return arr[n / 2];
  ;
}

/**
 * @brief find median from two different vectors
 *
 * @param smaller_array
 * @param N
 * @param Bigger_array
 * @param M
 * @return double
 */
double find_median(vector<int> smaller_array, int N_start, int N,
                   vector<int> Bigger_array, int M_start, int M) {
  // if smaller array is empty then return median of second array
  if (N == 0) {
    return median_of_a_array(Bigger_array, M);
  }

  // If the smaller array has only one element
  if (N == 1) {
    // Case 1: If the larger array also has one element,
    if (M == 1) {
      return median_of_two_integers(smaller_array[0], Bigger_array[0]);
    }
    // Case 2: If the larger array has odd number of elements,
    // then consider the middle 3 elements of larger array and
    // the only element of smaller array.
    if (M & 1) {
      return median_of_two_integers(
          Bigger_array[M / 2],
          median_of_three_integers(smaller_array[0], Bigger_array[(M / 2) - 1],
                                   Bigger_array[(M / 2) + 1]));
    }
    // Case 3: If the larger array has even number of element,
    // then median will be one of the following 3 elements
    // ... The middle two elements of larger array
    // ... The only element of smaller array
    return median_of_three_integers(
        Bigger_array[M / 2], Bigger_array[(M / 2) - 1], smaller_array[0]);
  }
  // If the smaller array has two elements
  else if (N == 2) {
    // Case 4: If the larger array also has two elements,
    if (M == 2) {
      return median_of_four_integers(smaller_array[0], smaller_array[1],
                                     Bigger_array[0], Bigger_array[1]);
    } // Case 5: If the larger array has odd number of elements,
      // then median will be one of the following 3 elements
      // 1. Middle element of larger array
      // 2. Max of first element of smaller array and element
      //    just before the middle in bigger array
      // 3. Min of second element of smaller array and element
      //    just after the middle in bigger array
    if (M & 1)
      return median_of_three_integers(
          Bigger_array[M / 2], max(smaller_array[0], Bigger_array[(M / 2) - 1]),
          min(smaller_array[1], Bigger_array[(M / 2) + 1]));

    // Case 6: If the larger array has even number of elements,
    // then median will be one of the following 4 elements
    // 1) & 2) The middle two elements of larger array
    // 3) Max of first element of smaller array and element
    //    just before the first middle element in bigger array
    // 4. Min of second element of smaller array and element
    //    just after the second middle in bigger array
    return median_of_four_integers(
        Bigger_array[M / 2], Bigger_array[(M / 2) - 1],
        max(smaller_array[0], Bigger_array[(M / 2) - 2]),
        min(smaller_array[1], Bigger_array[(M / 2) + 1]));
  }
  int index_of_median_smaller_array = (N - 1) / 2;
  int index_of_median_bigger_array = (M - 1) / 2;

  if (smaller_array[index_of_median_smaller_array] <=
      Bigger_array[index_of_median_bigger_array])
    return find_median(smaller_array, index_of_median_smaller_array, N / 2 + 1,
                       Bigger_array, 0, M - index_of_median_smaller_array);

  return find_median(smaller_array, 0, (N / 2) + 1, Bigger_array,
                     index_of_median_bigger_array,
                     M - index_of_median_smaller_array);
}

/**
 * @brief Find median of two sorted arrays
 *
 * @param nums1
 * @param nums2
 * @return double
 */
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int N = nums1.size();
  int M = nums2.size();

  if (M < N)
    return find_median(nums2, 0, M, nums1, 0, N);
  else
    return find_median(nums1, 0, N, nums2, 0, M);
  ;
}

int main(int argc, const char **argv) {
  vector<int> A = {900};
  vector<int> B = {5, 8, 10, 20};
  std::cout << "Median " << (double)findMedianSortedArrays(A, B) << std::endl;
  return 0;
}