// CPP program to find k-th smallest sum
#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

int CalculateRank(vector<int> prefix, int n, int x) {
  

  // Initially rank is 0.
  int rank = 0;
  int sumBeforeIthindex = 0;
  for (int i = 0; i < n; ++i) {

    // Calculating the count the subarray with
    // starting at ith index
    int cnt = upper_bound(prefix.begin(), prefix.end(), sumBeforeIthindex + x) -
          prefix.begin();

    // Subtracting the subarrays before ith index.
    cnt -= i;

    // Adding the count to rank.
    rank += cnt;
    sumBeforeIthindex = prefix[i];
  }
  return rank;
}

int findKthSmallestSum(int a[], int n, int k) {
  // PrefixSum array.
  vector<int> prefix;

  // Total Sum initially 0.
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum |= a[i];
    prefix.push_back(sum);
  }

  // Binary search on possible
  // range i.e [0, total sum]
  int ans = 0;
  int start = 0, end = sum;
  while (start <= end) {

    int mid = (start + end) >> 1;

    // Calculating rank of the mid and
    // comparing with K
    if (CalculateRank(prefix, n, mid) >= k) {

      // If greater or equal store the answer
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return ans;
}
int naive(int a[], int n, int k) {

  vector<int> b;

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      int val = 0;
      for (int k = i; k <= j; ++k) {
        std::cout << a[k] << '\t';
        val |= a[k];
      }

      if (i <= j) {

        for (int m = 0; m < n - j + i; m++) {
          std::cout << '\t';
        }
        std::cout << '-' << '\t' << val << '\n';
        b.push_back(val);
      }
    }
  }
  std::cout << '\n';
  for (int i = 0; i < (int)b.size(); ++i) {
    std::cout << b[i] << '\t';
  }
  std::cout << '\n';
  sort(b.begin(), b.end());
  return b[k - 1];
}

int main() {
  int a[] = {1, 2, 3};
  int k = 6;
  int n = sizeof(a) / sizeof(a[0]);
  std::cout << "Naive algorithm" << std::endl;
  int res = naive(a, n, k);
  std::cout << "Last element:" <<  res << std::endl;
  std::cout << "Optimized algorithm" << std::endl;
  cout << findKthSmallestSum(a, n, k);
  return 0;
}
