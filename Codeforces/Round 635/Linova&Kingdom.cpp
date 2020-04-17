/* 
    __gcd(x, y); log10(N); log2(N); floor(K); pow(10, K); modi = pow(a,m-2,m);
    emplace_back(); num_of_digits = floor(log10(N)) + 1; isPowerOfTwo --> x && (!(x&(x-1)));
    all_of(); any_of(); none_of(); copy_n(); iota() increasing list;
    auto num = 0b111; initialization in binary form
    insert(); 1ll << x; acos(); cos();
    nth_element(a.begin(), a.begin()+K-1, a.end());
    reverse/(next/prev)_permutation/random_shuffle( begin() , end() ) , accumulate( begin() , end() , initval )
    binary_search/lower_bound/upper_bound/count( begin() , end() , x )
    lower_bound >= , upper_bound >
    ld pi = atan( (ld)1 )*4 , e = 2.71828
    Min Heap : priority_queue<int,vector<int>,greater<int>> q; push(x); pop(); top();
 
    stack<type> name empty(),size(),pop(),top(),push(x)
    queue<type> name empty(),size(),pop(),front(),back(),push(x)
    priority_queue <type> name default max, min priority_queue <int, vector<int>, greater<int> > pq; empty(),size(),pop(),top(),push(x)
    deque<type> name pop_front(),pop_back(),push_front(),push_back(),size(),at(index),front(),back()
    set/multiset/map/multimap<type>name begin(),end(),size(),empty(),insert(val),erase(itr or val),find(val)
*/ 
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mkpa make_pair
#define ull unsigned long long 
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i64 int64_t
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair 
#define all(x) x.begin(),x.end()
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
//typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll modm = 1e9+7;

const int mxN = 4e5+5;
int n, k;
vector<ll> deg;
vector<ll> dep;
vector<ll> child;
vector<ll> val;
vector<vector<int>> g;
//ll vis[N], dist[N], ways[N];

/*void bfs(ll k)
{
    queue<ll> q;
    q.push(k);
    ways[k]=1;
    vis[k]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(auto it:g[node])
        {
            if(!vis[it])
            {
                dist[it]=dist[node]+1;
                vis[it]=1;
                ways[it]+=ways[node];
                q.push(it);
            }
            else
            {
                if(dist[node]+1==dist[it])
                {
                    ways[it]+=ways[node];
                }
            }
        }
    }
}*/
//dist has depth. 
//we try to reach node 1 as the end.

void bfs(int start){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    dep[start] = 0LL;
    while(SZ(q)){
        int u = q.front(); q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto v: g[u]){
            q.push(v);
            dep[v] = min(1LL + dep[u], dep[v]);
        }
    }
    
}
 

ll dfs(int u, int father){
    ll cnt = 1LL;
    for(auto v: g[u]){
        if(v != father){
            cnt += dfs(v, u);
        }
    }
    child[u] = cnt - 1LL;
    return cnt;
}

int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> n >> k;

    g.resize(n);
    deg.resize(n);
    dep.resize(n);
    child.resize(n);
    val.resize(n);
    for(int i=0;i<n;i++) dep[i] = (ll)1e18;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    //for(int i=0;i<n;i++)
      //  bfs(i);
    bfs(0);
    dfs(0,-1);
    for(int i=0;i<n;i++){
        val[i]=dep[i]-child[i];
    }
    sort(all(val));

    ll ans = 0;
    for(int i=n-k;i<n;i++) {
        ans += (ll)val[i];
    }
    
    cout << ans << endl;
}
 
/* 
input
4 1
1 2
1 3
2 4

 
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int MAXN = 200010;
 
vector<int> distances;
vector<int> adj[MAXN];
 
int go(int u, int p, int depth) {
    int children = 0;
    for(auto v : adj[u]) {
        if(v == p) continue;
        children += 1 + go(v, u, depth + 1);
    }
    if(p != -1) {
        distances.emplace_back(depth - children);
    }
    // cout << "u: " << u << ", p : " << p << ", depth: " << depth << ", children: " << children << endl;   
    return children;    
}
 
void run() {
    int i, j, n, k;
    cin >> n >> k;
    for(i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    go(0, -1, 0);
    sort(distances.rbegin(), distances.rend());
    ll ret = 0;
    for(i=0; i<min(k, (int)distances.size()); i++) {
        ret += distances[i];
    }
    cout << ret << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     
    run();
}*/

/*For C, here are my Observations and Solution:

1) The objective is to label each city as either an tourism city (i.e. it contributes towards the total score), or as an industrial city (i.e. it is a starting point and doesn't contribute towards the total score). The solution is to find the sum of the k longest paths from any node ("industrial" city) to the root node (the "Capital" city) while visiting as many interim nodes ("tourism city") as possible.

2) Just taking leaf nodes is not sufficient. If you have one path that's 10 deep, and another that's just 1 deep and k = 5, then you have to take the 5 deepest nodes from the path that's 10 deep, and ignore the leaf node altogether.

3) The complexity is introduced when you've already taken a leaf node but also need to take its parent node. How can we account for that? Observe that when you add any parent, you could simply deduct 1 for each child it has (since that city is no longer a "tourism" city for each of the child nodes, and is instead an "industrial" city). So if you have to take a parent node, then its contribution is: (distance to root node) — (# of children)

4) So at each node, you need to know two things: the distance from root, and the number of children it has. In terms of the implementation, run a dfs that increments depth by 1 for each child node, and returns the number of children at each stage back to the parent node.

5) Store each of these depths in a vector (could also use a priority queue but no need, really)

6) Sort in reverse order. Sum up the first k values and return that.*/