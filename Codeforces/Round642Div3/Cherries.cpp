#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m, sz = 0;
bool vis[N];
vector<int> g[N];

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u] = 1;
	sz++;
	for(auto &it:g[u])
		dfs(it);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0;
	while(t--)
	{
		tc++;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			g[i].clear();
		}
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0, comp = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
			{
				sz = 0;
				dfs(i);
				comp++;
				ans += (sz - 1);
			}
		}
		ans += (comp - 1) * 2;
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
