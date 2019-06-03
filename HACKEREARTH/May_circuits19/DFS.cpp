#include <bits/stdc++.h>
typedef long double ld;
using namespace std;
const int maxn = 3e5 + 14;
int n, m, from[maxn], to[maxn];
bool mark[maxn];
vector<int> vec, g[maxn];
bool dfs(int v = 1){
	if(mark[v])
		return 0;
	mark[v] = 1;
	if(v == n)
		return 1;
	for(auto i : g[v]){
		vec.push_back(i);
		if(dfs(from[i] ^ to[i] ^ v))
			return 1;
		vec.pop_back();
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	assert(cin >> n >> m);
	for(int i = 0; i < m; i++){
		int v, u, w;
		assert(cin >> v >> u >> w);
		from[i] = v;
		to[i] = u;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	dfs();
	cout << "1\n";
	cout << vec.size() << ' ';
	for(auto x : vec)
		cout << x + 1 << ' ';
	cout << '\n';
}
