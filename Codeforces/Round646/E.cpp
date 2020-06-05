#include<bits/stdc++.h>
using namespace std; 
     
#define nfs() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl '\n'
#define pb push_back
#define pf push_front
#define eb emplace_back
#define debug(x) cerr << #x << ": " << x << '\n';
#define forin(i, n) for(int i=0;i<n;i++)
#define tr(c, it) for(auto it=c.begin();it!=c.end();it++)
#define sz(c) (int)c.size()
#define all(c) c.begin(), c.end()
#define ff first
#define ss second
#define m_p(x, y) make_pair(x, y)
#define mem(v, val) memset(v, val, sizeof(v))
 
typedef vector<vector<int> > Mat;
typedef pair<int, int> pi;
     

const int M = 1e9 + 7;
const int N = 200100;
int c[N], b[N], a[N], subsb[N], subsc[N], unbalanced[N];
bool vis[N];
int ans;
vector<int> adj[N];

void dfs(int u){
	vis[u] = 1;
	unbalanced[u] = (c[u]-b[u]);
	int temp = abs(c[u] - b[u]);
	for(int v:adj[u]){
		if(!vis[v]){
			//par[v]=u;
			if(a[v] > a[u])
				a[v] = a[u];
			dfs(v);
			unbalanced[u] += (unbalanced[v]);
			temp += (abs(unbalanced[v]));
		}
	}
	ans += (a[u]*(temp - abs(unbalanced[u])));
}
 
void solve(){
	int n, i, j, k, m, x=0, y=0;
	cin >> n;
	forin(i, n){
		cin >> a[i+1] >> b[i+1] >> c[i+1];
		x+=(c[i+1]);
		y+=(b[i+1]);
	}
	forin(i, n-1){
		cin >> j >> k;
		adj[j].eb(k);
		adj[k].eb(j);
	}
	if(x!=y){
		cout << "-1\n";
		return;
	}
	dfs(1);
	cout << ans << '\n';
	return;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        solve();
    return 0;
}



/*I have a solution for E which is similar to the idea in the editorial but it uses a small trick 
and without maintaining the parent and instead storing how many unbalanced cases are to be resolved 
by shuffling in sub-tree of a node. Code
For the case of impossibility if summation of bi != summation of ci, 
we print -1 otherwise we have a solution. 
We have a global variable ans which we print if it's possible to reshuffle 
values to get desired structure. 
So we maintain a global array 'unbalanced' 
which stores how many 1s in sub-tree of the node still require shuffling 
while maintaining a[node] <= a[par] for node != 1 (the root). 
So for any node let the initial unbalanced amount be c[node] — b[node]. 
We will see how this comes handy later. Now if we sum unbalanced[v] for all v 
in children of node with unbalanced[node] 
we get the number of 1s that cannot be shuffled within the sub-tree rooted at node. 
Even if it turns out to be negative it is fine as it will get balanced by some other nodes 
as summation bi = summation ci. 
Now unbalanced stores the number of 1s in sub-tree of v 
which cannot be resolved by any shuffles within the tree and the number of shuffles
 which can be made in the sub-tree is 
 {summation abs(unbalanced[v]) | node is a parent of v + abs(c[node]-b[node]) } — {abs(unbalanced[u])}. 
 We multiply this with a[node] and add it to the global answer variable, 
 as the optimal cost for shuffling can only come from this because a[par] >= a[node] 
 which I maintain by this, if(a[v] > a[node]) a[v] = a[node];*/