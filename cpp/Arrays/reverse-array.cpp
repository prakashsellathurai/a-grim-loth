#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void roatate_array(std::vector<int> *arr,int n,int k){
if(k<0){
    k = arr->size()+k;
}
reverse(arr->begin(),arr->end());
reverse(arr->begin()+0,arr->begin()+k-1);
reverse(arr->begin()+k,arr->begin()+n-1);

}
int main(int argc, const char** argv) {
    std::vector<int> a = {1,2,3,45,5};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    roatate_array(&a,n,k);
    
    for(int i = 0; i < n; ++i) {
      std::cout << a[i] << '\t';
    }
    
    return 0;
}