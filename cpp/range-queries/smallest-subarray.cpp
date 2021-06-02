#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> merge(vector<int>& v1, vector<int>& v2) 
{ 
    int i = 0, j = 0; 
   
    vector<int> v; 
  
    while (i < v1.size() && j < v2.size()) { 
        if (v1[i] <= v2[j]) { 
            v.push_back(v1[i]); 
            i++; 
        } 
        else { 
            v.push_back(v2[j]); 
            j++; 
        } 
    } 
  
    for (int k = i; k < v1.size(); k++) 
        v.push_back(v1[k]); 
    for (int k = j; k < v2.size(); k++) 
        v.push_back(v2[k]); 
    return v; 
} 
  
void buildTree(vector<int>* tree, int* arr, 
               int index, int s, int e) 
{ 
  
    if (s == e) { 
        tree[index].push_back(arr[s]); 
        return; 
    } 
  
    int mid = (s + e) / 2; 
    buildTree(tree, arr, 2 * index, s, mid); 
    buildTree(tree, arr, 2 * index + 1, mid + 1, e); 
  
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]); 
} 
  
int query(vector<int>* tree, int index, int s, 
          int e, int l, int r, int k) 
{ 
  
    if (r < s || l > e) 
        return 0; 
  
    if (s >= l && e <= r) { 
        return (tree[index].size() 
                - (lower_bound(tree[index].begin(), 
                               tree[index].end(), k) 
                   - tree[index].begin())); 
    } 
  
    int mid = (s + e) / 2; 
    return (query(tree, 2 * index, s, 
                  mid, l, r, k) 
            + query(tree, 2 * index + 1, mid + 1, 
                    e, l, r, k)); 
} 
  

void solve()
{
  int n;
  cin >> n;
  assert(1 <= n and n <= 300000);

  int a[n];
  for(int i = 0 ; i < n ; i++)
  { 
    cin >> a[i];
    assert(1 <= a[i] and a[i] <= 1000000000);
  }

  int b[n];
  for(int i = 0 ; i < n ; i++)
  {
    cin >> b[i];
    assert(1 <= b[i] and b[i] <= n);
  }

  vector<int> tree[4*n+1];
  buildTree(tree, a, 1 , 0 , n - 1);

  for(int i = 0 ; i < n ; i++)
  {
    int value = a[i];
    int s = i;
    int e = n - 1;
    int ans = -1;

    while(s <= e){
      int m = (s+e) >> 1;
      int cnt = query(tree, 1, 0, n - 1, i, m, value);

      if(cnt >= b[i])
      {
        ans = m;
        e = m - 1;
      }
      else{
        s = m + 1;
      }
    }

    if(ans == -1) cout << ans << " ";
    else cout << (ans - i + 1 ) << " ";
  }
  cout << endl;
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while(t--)
  {
    solve();
  }
}