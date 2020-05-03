/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, inf = 1e9, B = 30;

void solve();
int query(int x, int y);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	fast_cin();
	int t, a, b;
	cin >> t >> a >> b;
	while (t--) {
		solve();
	}
}

void solve() {
	int x, y;
	while (true) {
		x = uniform_int_distribution<int>(-inf, inf)(rng);
		y = uniform_int_distribution<int>(-inf, inf)(rng);
		auto res = query(x, y);
		if (res == 2) {
			return;
		} else if (res == 1) {
			break;
		}
	}
	int x2 = x;
	for (int i = B; i >= 0; --i) {
		auto res = query(min(inf, x2 + (1 << i)), y);
		if (res == 2) {
			return;
		} else if (res == 1) {
			x2 = min(inf, x2 + (1 << i));
		}
	}
	int x1 = x;
	for (int i = B; i >= 0; --i) {
		auto res = query(max(-inf, x1 - (1 << i)), y);
		if (res == 2) {
			return;
		} else if (res == 1) {
			x1 = max(-inf, x1 - (1 << i));
		}
	}
	x = (x1 + x2) / 2;
	int y2 = y;
	for (int i = B; i >= 0; --i) {
		auto res = query(x, min(inf, y2 + (1 << i)));
		if (res == 2) {
			return;
		} else if (res == 1) {
			y2 = min(inf, y2 + (1 << i));
		}
	}
	int y1 = y;
	for (int i = B; i >= 0; --i) {
		auto res = query(x, max(-inf, y1 - (1 << i)));
		if (res == 2) {
			return;
		} else if (res == 1) {
			y1 = max(-inf, y1 - (1 << i));
		}
	}
	y = (y1 + y2) / 2;
	assert(query(x, y) == 2);
}

int query(int x, int y) {
	cout << x << ' ' << y << endl;
	string ans; cin >> ans;
	if (ans[0] == 'C') {
		return 2;
	} else {
		return (ans[0] == 'H');
	}
}