#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull	unsigned long long
#define EL '\n'

int main() {
	ll t, n, i, j; cin >> t;
	while(t--) {
		cin >> n;
		if(n == 1) {
			cout << 2 << EL;
			continue;
		}
		for(i = 1; i < n; i*=2);
		ll op1 = i+1;
		ll op2 = (i/2);
		for(j = i/4; op2+j > n; j/=2);
		op2 = op2+j;
		ll op3 = op2+(j*2);
		ll ans = (op1-n > abs(op2-n) ? (abs(op2-n) > abs(op3-n) ? abs(op3-n):abs(op2-n)):(abs(op1-n) > abs(op3-n) ? abs(op3-n):abs(op1-n)));
		cout << ans << EL;
	}
}		