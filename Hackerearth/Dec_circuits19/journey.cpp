#include <bits/stdc++.h>
#define ll long long 
#define vi vector<int>
using namespace std;

const int MAXN = 1e5 + 10;
int n, u, v, dist[MAXN];
bool vis[MAXN];
vi graph[MAXN];

double DFS(int node, int prev) {
  double ans = 0.0;
  int cnt = 0;
  vis[node] = 1;
  dist[node] = 1;
	for (int next : graph[node]) {
		if (next == prev) continue;
		if (!vis[next]) {
		  cnt++;
		  dist[next] += 1;
		  vis[next] = 1;
		  ans += DFS(next, node);
		}
	}
	if (!cnt) return 0.0;
	else return (ans / cnt) + 1.0;
}

int main () {
	scanf("%d", &n);
	for (int i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	printf("%.15f\n", DFS(1, 0));
}
