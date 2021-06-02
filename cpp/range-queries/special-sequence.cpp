#include<bits/stdc++.h>
#define ll long double
using namespace std;
vector<long long>p;

signed main(){
    long long sum = 0;
    p.push_back(0);
    for(ll i = 1 ; i <= 500000 ; i++){
        long long val = i*floor(sqrt(i)) + ceil(i/2);
        p.push_back(val);
    }

    int sz = p.size();

    for(int i = 1 ; i < sz ; i++){
        p[i] += p[i-1];
    }

    int q;
    cin >> q;
    assert(1 <= q and q <= 100000);
    while(q--){
        long long l, r;
        cin >> l >> r;
        assert(1 <= l and l <= r and r <= 10000000000000);
        int s = 0;
        int e = sz - 1;
        int ans1 = -1;
        while(s <= e){
            int m = (s + e)/2;
            if(p[m] < l){
                ans1 = m;
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }

        ans1++;

        s = 0;
        e = sz - 1;
        int ans2 = -1;
        while(s <= e){
            int m = (s + e)/2;
            if(p[m] < r){
                ans2 = m;
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        ans2++;

        cout << (ans2 - ans1 + 1) << endl;
    }   
}