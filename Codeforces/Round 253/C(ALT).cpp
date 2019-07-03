#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << (x) << endl
#define FOR(i, start, end) for (int i = start; i <= end; i++)
#define ROF(i, start, end) for (int i = start; i >= end; i--)
#define STFOR(i, start, end, step) for (int i = start; i <= end; i += step)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof (a))
#define good_time() ios_base::sync_with_stdio(false)
#define inf (1000 * 1000 * 1000)
#define infLL (1000LL * 1000 * 1000 * 1000 * 1000 * 1000)
#define MOD (1000 * 1000 * 1000 + 7)
#define eps (1e-8)
#define PI (3.14159265358979323846)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

const int N = 100 + 10;
const string X = "12345RGBYW";
string a[N];
map <char, bool> mp;

int main()
{
	good_time();
	int n;
	cin >> n;
	FOR (i, 0, n - 1)
		cin >> a[i];
	int ans = 10;
	FOR (mask, 0, (1 << 10) - 1)
	{
		int x = mask, y = 0;
		FOR (j, 0, 9)
		{
			mp[X[j]] = x % 2;
			y += x % 2;
			x /= 2;
		}
		bool ok = true;
		FOR (i, 0, n - 1)
			FOR (j, i + 1, n - 1)
			if (a[i] != a[j] && (a[i][0] == a[j][0] || (!mp[a[i][0]] && !mp[a[j][0]])) && (a[i][1] == a[j][1] || (!mp[a[i][1]] && !mp[a[j][1]])))
					ok = false;
		if (ok)
			ans = min(ans, y);
	}
	cout << ans << endl;
	return 0;
}