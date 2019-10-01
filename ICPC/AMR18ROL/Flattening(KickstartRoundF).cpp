//Started 1 hr 10 mins late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

const int N = 105;
const int M = 1005;

int n, k;
int a[N], cache[N][N];

int dp(int i, int k)
{
	if(i > n)
		return 0;
	if(k < 0)
		return 1e9;
	int &ans = cache[i][k];
	if(ans != -1)
		return ans;
	ans = 1e9;
	vector<int> f(1001, 0);
	int mx = 0;
	for(int j = i; j <= n; j++)
	{
		f[a[j]]++;
		mx = max(mx, f[a[j]]);
		ans = min(ans, j - i + 1 - mx + dp(j + 1, k - 1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0;
	while(t--)
	{
		tc++;
		memset(cache, -1, sizeof(cache));
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = dp(1, k);
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
