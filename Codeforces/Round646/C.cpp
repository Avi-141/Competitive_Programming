#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) (v).size()
#define debug(x) cerr << #x << "_=_" << x << "\n";
#define sum(n) ((n)*((n)+1)>>1)
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
 
vvi tree;
vi dp;
 
int f(int u, int p=-1){
    for (int v : tree[u]){
        if(v==p) continue;
        dp[u] += f(v, u);
    }
    return dp[u] + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        tree.assign(n+1, vi());
        dp.assign(n+1, 0);
        for (int i=0, u, v; i<n-1; i++){
            cin >> u >> v;
            tree[u].pb(v);
            tree[v].pb(u);
        }
 
        f(x);
        bool first=0;
        for (int v : tree[x])
            first ^= (dp[v]%2==0);
 
        if(first || tree[x].size() <= 1)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
 
        tree.clear();
        dp.clear();
    }
    return 0;
}