#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define int long long
 
int n;
vector<int> adj[200005];
int sz[200005];
int deph[200005];
int best = -1;
int initscore = 0;
 
void build(int node, int p, int d)
{
	sz[node] = 1;
	initscore += d + 1;
	for (int neighbor : adj[node])
	{
		if (neighbor != p)
		{
			build(neighbor, node, d + 1);
			sz[node] += sz[neighbor];
		}
	}
}
 
void dfs(int node, int p, int score)
{
	best = max(best, score);
	for (int neighbor : adj[node])
	{
		if (neighbor != p)
		{
			dfs(neighbor, node, score + n - 2 * sz[neighbor]);
		}
	}
}
 
signed main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	build(0, -1, 0);
	dfs(0, -1, initscore);
	cout << best << '\n';
}