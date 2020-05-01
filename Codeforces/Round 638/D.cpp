#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(x) x.begin(),x.end()
#define pb push_back

int count (int n) {
	int cnt = 0;
	while (n) {
		n >>= 1;
		++cnt;
	}
	return cnt;
}
 
void solve() {
	int n, days, c = 0;
	cin >> n;
	days = count(n) - 1;
	vector <int> a;
	cout << days << '\n';
	for (int i = 0; i < days; ++i) {
		int Pow = 1ll << i;
		a.push_back(Pow);
		c += Pow;
	}
	if (c < n)
		a.push_back(n - c);
	sort(all(a));
	for (int i = 0; i < days; ++i)
		cout << (a [i] == a [i + 1] ? 0 : a [i + 1] - a [i]) << ' ';
	cout << '\n';
}
 
int main() {
	
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}