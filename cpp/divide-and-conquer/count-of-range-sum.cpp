#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int64_t> &sum, int i, int j, int u, int l) {
  if (i == j)
    return l <= sum[i] && sum[i] <= u;
    
  int mid = i + (j - i) / 2,
      count = mergeSort(sum, i, mid, u, l) + mergeSort(sum, mid + 1, j, u, l);

  for (int l_ = i, r_ = i, k = mid + 1; k <= j; ++k) { // Find all i, j pairs
    while (r_ <= mid && sum[r_] + l <= sum[k])
      ++r_;
    while (l_ <= mid && sum[k] > sum[l_] + u)
      ++l_;
    count += r_ - l_;
  }

  vector<int64_t> tmp(j - i + 1, 0);
  for (int k = i, l = mid + 1, m = 0; m <= j - i; ++m) { // merge
    if (k > mid)
      tmp[m] = sum[l++];
    else if (l > j)
      tmp[m] = sum[k++];
    else
      tmp[m] = sum[l] < sum[k] ? sum[l++] : sum[k++];
  }
  copy(tmp.begin(), tmp.end(), sum.begin() + i);
  return count;
}

int countRangeSum(vector<int> &nums, int lower, int upper) {
  const int size = nums.size();
  if (!size)
    return 0;
  vector<int64_t> sum(size, nums[0]);
  for (int i = 1; i < size; ++i)
    sum[i] = sum[i - 1] + nums[i];
  return mergeSort(sum, 0, size - 1, upper, lower);
}

int main(int argc, const char **argv) {

  vector<int> Arr = {-3, -5, 1, 4, 5};
  int l = -1, u = 1;
  std::cout << countRangeSum(Arr, l, u) << std::endl;
  return 0;
}
