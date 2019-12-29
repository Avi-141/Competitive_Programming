//These codes give TLE .
//They have been accepted in the original contest.

/*#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
const int inf = 10000000000;
const int mod = (int)1e9 + 7;
using namespace std;
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = (int)1e5 + 10;
     
int n, m, k;
int ans[N];
int friends[N];
vector<int> v[N];
     
void dfs(int s, int curr, int costs){
    for(auto i: v[s]){
      friends[i] += costs;
      if(friends[i] >= k){
        smin(ans[i], curr);
        }
      }
}
int32_t main(){
     fastio
     cin>>n>>m>>k;
     for (int i = 0; i <= n; ++i){
          ans[i] = inf;
       }
     
       for (int i = 0; i < m; ++i){
          int x, y;
          cin >> x >> y;
          v[x].push_back(y);
          v[y].push_back(x);
       }
     
       int q;
       cin >> q;
     
       for (int i = 1; i <= q; ++i)
       {
          int ver, x;
          cin >> ver >> x;
          dfs(ver, i, x);
       }
     
       for (int i = 1; i <= n; ++i)
       {
          int tt = ans[i];
          if(tt == inf)tt = -1;
          cout<<tt<<' ';
       }
}

//const ll MAX=100005;

/*vector<ll> adj[MAX];


ll indeg[MAX];
ll val[MAX];

ll main(){

    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll q;
    cin >> q;
    for(ll i=0;i<q;i++){
        ll p,x;
        cin >> p >> x;
        for(auto it:adj[p])
        {
            val[it]+=x;
            if(val[it]>=k && indeg[it]==0)
                indeg[it]=i+1;
        }
    }
    for(ll i=1;i<n+1;i++){
        if(indeg[i]==0)
            cout << -1 << " ";
        else
            cout << indeg[i] << " ";
    }
        
}*/
#include <bits/stdc++.h>
#define maxn 100001
#define MOD   1000000007
#define int long long
#define inf 1e18
using namespace std;

vector< int > adj[maxn] ;
bool vis [ maxn ] ;
int ans [ maxn ] ;
int val [maxn] ;
 
int32_t main(){
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
 
   int n , m , k ;
   cin >> n >> m >> k ;
   while ( m-- ){
      int x , y ;
      cin >> x >> y;
      adj[x] . push_back (y) ;
      adj[y] . push_back (x) ;
   }
   int q ;
   cin >> q;
   for ( int i=1 ; i<=q ; i++ ) {
      int p , x;
      cin >> p >> x;
      for ( auto j : adj [p] ){
        if( !vis[j] ){
         val[ j ] = val[ j ] + x;
         if ( val[j] >= k ){
             ans [ j ] = i;
             vis [ j ] = true;
         }
        }
      }
   }
   for ( int i=1 ; i<=n ; i++ ){
     if( ans[i] == 0 )
        cout<<-1<<" ";
     else
        cout<<ans[i]<<" ";
   }
   return 0;
}