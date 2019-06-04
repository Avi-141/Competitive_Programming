#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <functional>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int main() {
	speed;
	ll t;
	cin >> t;
	while (t--) {
		ll n, mx = 0, mn = INT_MAX, v;
		cin >> n;
		set<int>sf, ss;
		for (int i = 0; i < n; ++i) {
			cin >> v;
			if (v > mx)
				mx = v;
			if (v < mn)
				mn = v;
			sf.insert(v);
		}
		ll ans = mn * mx;
		for (ll i = 2; i <= sqrt(ans); ++i) {
			if (ans % i == 0) {
				ss.insert(i);
				if ((ans / i) == 0)
					ss.insert(ans / i);
			}
		}
	   
		if (ss == sf)
			cout << ans;
		else
			cout << -1<<endl;
	}
}