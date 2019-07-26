#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll MOD = 1000000 + 3;

ll fact[MOD], inv[MOD], test, N, L, R;

ll inverse(ll n, ll k) {
	if (k > n)
		return 0;
	return (fact[n] * 1LL * inv[k] * 1LL * inv[n - k]) % MOD;
}

ll binpow (ll base, ll pw, ll mod) {
	if (pw == 1)
		return base;
	ll ret = binpow(base, pw / 2, mod);
	ret= (ret * 1LL * ret) % mod;
	if (pw % 2 == 1)
		ret = (ret * 1LL * base) % mod;
	return ret;
}

int main(int argc, char const *argv[])
{
	fact[0] = inv[0] = 1;
	for(ll i = 1; i <= MOD - 1; i++) {
		fact[i] = (fact[i - 1] * 1LL * i) % MOD;
		inv[i] = binpow(fact[i], MOD - 2, MOD);
	}
	cin >> test;
	while (test--) {
		cin >> N >> L >> R;
		ll k = R - L + 1;
		ll n = N + 1;
		ll ret = inverse((n + k - 1) / MOD, (n - 1) / MOD) * 1LL * inverse((n + k - 1) % MOD, (n - 1) % MOD) % MOD;
		cout << (ret - 1 + MOD) % MOD << endl;
	}

}