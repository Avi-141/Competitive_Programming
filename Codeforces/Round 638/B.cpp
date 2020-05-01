#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, k, c = 0;
	cin >> n >> k;
	vector <int> a;
	vector <bool> b (100, false);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; --x;
		if (!b [x]) {
			b [x] = true;
			++c;
			a.push_back(x);
		}
	}
	if (c > k)
		cout << -1;
	else {
		cout << n * k << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < c; ++j)
				cout << a [j] + 1 << ' ';
			for (int j = c; j < k; ++j)
				cout << 1 << ' ';
		}
	}
	cout << '\n';
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}
