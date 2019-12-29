#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define pb push_back

const ll N = 600;
ll n, k, ans = 0;
vector<pair<ll, ll> > g[N];

ll dfs(ll u, ll par){

	vector<ll> v;
	for(auto &it:g[u]){
		if(it.first == par){
		    //cout<<it.first<<" ";
			continue;
		}
		//cout<<"call dfs ans store dia"<<"\n";
		//cout<<u<<" "<<it.first<<" "<<it.second<<"\n";
		v.pb(dfs(it.first, u) + it.second);
	}
	v.pb(0);
	sort(all(v));
	
	while(v.size() > 1){
		ll last = v.back();
		ll second = v[v.size() - 2];

		if(last + second > k){
			ans++;
			//cout<<"Last"<<" "<<v.back();
			//cout<<"\n";
			v.pop_back();
		}
		else
			break;

    }
return v.back();
}	

int main(){
	cin >> n >> k;
	for(ll i = 1; i <n; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		g[u].pb(make_pair(v, w));
		g[v].pb(make_pair(u, w));

	}
	dfs(1, 1);
	ans+=1;
	cout<<ans<<"\n";
}
