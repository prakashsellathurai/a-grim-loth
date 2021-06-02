#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll ans[1003][1003];
vector<int>adjacent[1003];
bool visited[1001];
int rt = -1;
int x;
ll fact[1003], invfact[1003];

ll power(ll a, ll n)
{
    if(n == 0) return 1;

    ll ans = 1;
    ll val = a;

    while(n)
    {
        if(n%2)
        {
            ans *= val;
            ans %= mod;
        }

        val *= val;
        val %= mod;
        n /= 2;
    }

    return ans;
}

void dfs(int u, int p)
{
    for(int i = 0 ; i < adjacent[u].size() ; i++)
    {
        int v = adjacent[u][i];
        if(v != p)
            dfs(v, u);
    }

    for(int j = 1 ; j <= 1000 ; j++)
    {
        ll md = 1;       
        for(int i = 0 ; i < adjacent[u].size() ; i++)
        {
            int v = adjacent[u][i];
            if(v != p){
                md *= ans[v][j];
                md %= mod;
            }
        }
        ans[u][j] = md;
    }

    for(int i = 2 ; i <= 1000 ; i++)
    {
        ans[u][i] += ans[u][i-1];
        ans[u][i] %= mod;
    }
}

void solve(){
    int n;
    cin >> n;
    assert(2 <= n and n <= 1000);

    ll x;
    cin >> x;
    assert(1 <= x and x <= 1000000000);

    for(int i = 1 ; i <= n ; i++){
      visited[i] = false;
      adjacent[i].clear();
    }

    for(int i = 1 ; i < 1003 ; i++)
    {
      for(int j = 1 ; j < 1003 ; j++)
      {
        ans[i][j] = 0;
      }
    }

    for(int i = 1 ; i <= n - 1 ; i++){
        int u, v;
        cin >> u >> v;
        assert(1 <= u and u <= n);
        assert(1 <= v and v <= n);
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    rt = 1;
    dfs(rt, -1);
    
    if(x <= 1000) cout << ans[rt][x] << endl;
    else{
        ll temp[n+1];
        temp[0] = x;

        for(int i = 1 ; i <= n ; i++)
        {
            temp[i] = (x-i);
            temp[i] %= mod;
        }

        ll pre[n+1];
        ll suff[n+2];

        pre[0] = temp[0];
        for(int i = 1 ; i <= n ; i++)
        {
          pre[i] = pre[i-1]*temp[i];
          pre[i] %= mod;
        }

        suff[n+1] = 1;
        for(int i = n ; i >= 1 ; i--)
        {
          suff[i] = temp[i]*suff[i+1];
          suff[i] %= mod;
        }


        ll answer = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            ll vl = suff[i+1];
            vl %= mod;

            vl *= pre[i-1];
            vl %= mod;

            ll tm = invfact[n - i];
            tm %= mod;

            if((n-i)&1){
                tm *= (mod - invfact[i]);
                tm %= mod;
            }
            else{
                tm *= invfact[i];
                tm %= mod;
            }

            vl *= tm;
            vl %= mod;

            vl *= ans[rt][i];
            vl %= mod;
            
            answer += vl;
            answer %= mod;
        }
        cout << answer << endl;
    }
}   

int main(){
    fact[0] = invfact[0] = 1;
    for(int i = 1 ; i <= 1000 ; i++){
        fact[i] = i*fact[i-1];
        fact[i] %= mod;

        invfact[i] = power(i, mod-2)*invfact[i-1];
        invfact[i] %= mod;
    }

    int t;
    cin >> t;
    assert(1 <= t and t <= 10);
    while(t--)
    {
        solve();
    }
}