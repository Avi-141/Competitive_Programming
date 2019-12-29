#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

const ll N = 1e5 + 5;

//BIT TAKEN FROM 
//https://github.com/Ashishgup1/Competitive-Coding/
struct BIT{
	ll N;
	vector<ll> bit;

	void init(ll n){
		N = n;
		bit.assign(n + 1, 0);
	}

    void update(ll idx, ll val){
		while(idx <= N){
			bit[idx] += val;
			idx += idx & -idx;

		}
    }

	void updateMax(ll idx, ll val){
		while(idx <= N){
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;

		}

	}

	ll pref(ll idx){
		ll ans = 0;
		while(idx > 0){
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
	ll rsum(ll l, ll r){
		return pref(r) - pref(l - 1);
	}
	ll prefMax(ll idx){
		ll ans = -2e9;
		while(idx > 0){
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}

		return ans; 
	}

};

ll t,q;
ll a[N], ans[N];
vector<ll> g[N];
vector<pair<ll, ll> > query[N];

int main(){
	
	cin >> t >> q;
	for(ll i = 1; i <= t; i++){
		cin >> a[i];
		g[a[i]].push_back(i);

	}
	
	for(ll i = 1; i <= q; i++){
		ll m, n;
		cin >> m >> n;
		query[m].push_back({i, n});
	}

	a[0] = -1;
	BIT bit;
	bit.init(t + 5);

	for(ll i = 1e5; i >= 1; i--){

		for(auto &it:g[i])
			bit.update(it, 1);

		for(auto &it:query[i]){

			ll idx = it.first;
			ll val = it.second;
			ll lo = 1, hi = t;

			if(bit.pref(t) < val){
				ans[idx] = 0;
				continue;
			}

			while(lo < hi){

				ll mid = (lo + hi) / 2;
				if(bit.pref(mid) >= val)
					hi = mid;

				else
					lo = mid + 1;
			}
			ans[idx] = lo;
		}

	}

	for(ll i = 1; i <= q; i++)	
	  cout << a[ans[i]] << endl;

}
