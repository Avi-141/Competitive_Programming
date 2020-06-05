#include <iostream>
#include <vector>
 
#define ll long long
using namespace std;
 
void dfs(int source, int dest, ll ab[], vector <int> adj[], int depth, int k);
 
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, m;
		cin>>n>>m;
		ll ab[100005] = {0};
		ll bc[100005] = {0};
		n++;
		vector<int> adj[n];
		n--;
		int a, b, c, k;
		for(int i=0; i<m; i++) {
			cin>>a>>b;
			adj[a].push_back(b);
		}
		
		cin>>a>>b>>c>>k;
		
		dfs(a, b, ab, adj, 0, k);
		dfs(b, c, bc, adj, 0, k);
		
		ll count=0;
		
		for(int i=1; i<k; i++) {
			count+=(ab[i]*bc[k-i]);
		}
		
		cout<<count<<"\n";
	}
	return 0;
}
 
void dfs(int source, int dest, ll ab[], vector <int> adj[], int depth, int k) {
	if(depth>k) return;
	if(depth==k && source!=dest) return;
	if(source==dest) {
		ab[depth]++;
		return;
	}
	int sz=adj[source].size();
	for(int i=0; i<sz; i++) {
		dfs(adj[source][i], dest, ab, adj, depth+1, k);
	}
}