#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		cout.precision (20);
		cout << "Case #" << it << ": " << endl;
		if (n <= 50) {
			for (int i = 0; i < n; i++) cout << i + 1 << " " << 1 << endl;
		} else {
			int req = 50;
			n -= 50;
			int side = 0;
			for (int i = 0; req; i++)
				if (i < 30 && ((n >> i) & 1)) {
					if (side) {
						for (int j = i + 1; j >= 1; j--) cout << i + 1 << " " << j << endl;
					} else {
						for (int j = 1; j <= i + 1; j++) cout << i + 1 << " " << j << endl;
					}
					side ^= 1;
				} else {
					req--;
					if (side) {
						cout << i + 1 << " " << i + 1 << endl;
					} else {
						cout << i + 1 << " " << 1 << endl;
					}
				}
		}
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}