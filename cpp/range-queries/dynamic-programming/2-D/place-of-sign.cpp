#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


ll dp[5001][5001];
int main() {
//    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    memset(dp, 0, sizeof dp);
    for (int j = 1; j < n + 1; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i < n + 1; i++) {
        if (s[i - 2] == '<') {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
            }
        }

        else if (s[i - 2] == '>') {
            for (int j = n; j; j--) {
                dp[i][j] = (dp[i][j + 1] + dp[i - 1][j + 1]) % mod;
            }
        }

        else {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    ll ans = 0;
    for (int j = 1; j < n + 1; j++) {
        ans += dp[n][j];
    }

    cout << ans % mod;

}