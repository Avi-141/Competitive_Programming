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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main() {
	fast_cin();
	int tc; cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cout << "Case #" << t << ": ";
		int x, y;
		cin >> x >> y;
		string ans;
		while (x or y) {
			if (((abs(x) & 1) ^ (abs(y) & 1)) == 0) {
				break;
			} else if (x == 0) {
				if (abs(y) == 1) {
					ans += (y > 0 ? 'N' : 'S');
					y = 0;
				} else if (((y - 1) / 2) % 2) {
					ans += 'N';
					y = (y - 1) / 2;
				} else {
					ans += 'S';
					y = (y + 1) / 2;
				}
			} else if (y == 0) {
				if (abs(x) == 1) {
					ans += (x > 0 ? 'E' : 'W');
					x = 0;
				} else if (((x - 1) / 2) % 2) {
					ans += 'E';
					x = (x - 1) / 2;
				} else {
					ans += 'W';
					x = (x + 1) / 2;
				}
			} else if (x & 1) {
				x = (x - 1) / 2;
				y /= 2;
				ans += 'E';
				if (((abs(x) & 1) ^ (abs(y) & 1)) == 0) {
					++x;
					ans.back() = 'W';
				} 
			} else {
				y = (y - 1) / 2;
				x /= 2;
				ans += 'N';
				if (((abs(x) & 1) ^ (abs(y) & 1)) == 0) {
					++y;
					ans.back() = 'S';
				}
			}
		}
		if (x or y) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ans << '\n';
		}
	}
}