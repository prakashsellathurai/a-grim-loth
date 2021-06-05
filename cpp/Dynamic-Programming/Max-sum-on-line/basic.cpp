#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char** argv) {
    std::vector<int> a = {1,2,3,4,5};
    int n = a.size();
    std::vector<int> m(n,0);
    m[0] = a[0];
    for(unsigned i = 1; i < n; ++i) {
        m[i] = max(a[i],m[i-1]+a[i]);
    }
    std::cout << m[n-1] << std::endl;
    
    return 0;
}