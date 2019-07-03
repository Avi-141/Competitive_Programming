#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i=0;i<(n);++i)
#define clr(ar, val) memset(ar, val, sizeof(ar))
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<ld, ld> point;
const int MAXN = int(2e5) + 200;
     
    int n;
    vector<vector<int>> g(MAXN); //2d array of vertices
    vector<long long> res(MAXN), sz(MAXN);
    long long ans;
     
    void dfs(int v, int parent)
     {
        for (auto u : g[v]) 
        {
            if (u != parent) 
            {
                //cout << "purana" << v << " " << u << endl;
                dfs(u, v);
                sz[v] += sz[u]; // parent ka add karte raho
                res[v] += res[u]; 
            }
        }
        sz[v] += 1;
        res[v] += sz[v];
    }
     
    void findans(int v, int parent) 
    {
        ans = max(ans, res[v]);
        for (auto u : g[v]) 
        {
            if (u != parent) 
            {
                long long old_res = res[u];
                long long old_sz = sz[u];

                res[u] = res[v] + n - 2 * sz[u]; // no rerooting
                sz[u] = n;
                findans(u, v);

                res[u] = old_res;
                sz[u] = old_sz;
            }
        }
    }
     
    int main() {

     cin >> n;
        for (int i = 0; i < n - 1; ++i) 
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        /*
        for (int i = 1; i <= n; ++i) {
            cout << i << " -- " << sz[i] << " -- " << res[i] << endl;
        }
        */
        dfs(1, 1);
        findans(1, 1);
        cout << ans << endl;
        return 0;
    }