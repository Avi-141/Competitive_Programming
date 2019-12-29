#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second 
#define ret return
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i=a;i<=b;i++)
using ll =long long;

ll ans=1;
ll MAXW;
ll MOD=987654319;

ll modpow(ll base,ll exp){
	ll res;
    if(exp==0) ret 1;
	if(exp==1) ret base;
	
	res=modpow(base,exp>>1);
	res=(res*res)%MOD;
	
	if(exp&1)
	  res=(res*base)%MOD;
 ret res;
}

void init_ds(vector<ll> &id,vector<ll> &rank,ll N){
	for(ll i=1;i<=N;i++){
		id[i]=i;
		rank[i]=1;
	}
}

ll find(vector<ll> &id,ll par){
     ll root=par;
     while(root!=id[root]){
     	root=id[root];
     }
    //path compression
     while(par!=root){
     	ll newparent=id[par];
     	id[par]=root;
     	par=newparent;
     }
   ret root;
}

void merge(vector<ll> &id,vector<ll> &rank,ll x,ll y,ll wt){
   x=find(id,x);
   y=find(id,y);

   auto total=rank[x]*rank[y]-1;
   ans=(ans*modpow(max(MAXW-wt+2,0ll),total))%MOD;	
    
   if(rank[x]>rank[y]){
   	 id[y]=x;
   	 rank[x]=rank[x]+rank[y];
   }
   else{
   	id[x]=y;
   	rank[y]=rank[y]+rank[x];
   }
   if(rank[x]==rank[y]){
   	rank[y]+=1;
   }
}

int main(){

	vector<pair<ll,pair<ll,ll>>> edges;
	ll N;
	cin>>N>>MAXW;

	vector<ll> id(N+1),rank(N+1);
	init_ds(id,rank,N);

	REP(i,1,N-1){
		ll u,v,w;
		cin>>u>>v>>w;
		edges.pb({w,{u,v}});
	}
	sort(all(edges),[](pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
		return a.ff<b.ff;
	});
    
    for(auto e:edges){
    	ll u=e.ss.ff;
    	ll v=e.ss.ss;
    	ll w=e.ff;
    	merge(id,rank,u,v,w);
    }
    cout<<ans<<"\n";
}
