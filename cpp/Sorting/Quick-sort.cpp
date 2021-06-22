#include <iostream>


using namespace std;

int partition(int arr[], int l, int h) {
    int firsthigh,p,i;
    p = h;
    firsthigh = l;
    
    for(i = l; i < p; ++i) {
       if(arr[i]<arr[p]){
           swap(arr[i], arr[firsthigh]);
           firsthigh++;
       }
    }
    swap(arr[p], arr[firsthigh]);
    return firsthigh;
    
}
void QuickSort(int arr[], int l, int r) {
  int p;
  if ((r - l) > 0) {
    p = partition(arr, l, r);
    QuickSort(arr, l, p-1);
    QuickSort(arr, p + 1, r);

  } else {
    return;
  }
}
void print_arr(int array[], int n) {

  for (int i = 0; i < n; ++i) {
    cout << array[i] << " ";
  }

  std::cout << std::endl;
}
int main(int argc, char const *argv[]) {

  int array[] = {22, 4, 5, 4, 8, 7, 8, 7, 8, 9, 10, 1, 0,22};
  int n = sizeof(array) / sizeof(array[0]);
  print_arr(array, n);
  QuickSort(array, 0, n -1);
  print_arr(array, n);
}