#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
const int N = 2e5 + 5;
 
int a[N], b[N], pos[N], cnt[N];
int n, m, ans;
 
int main() {
	#ifdef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	cin>>n;
	for (int i = 1; i <= n; i++) cin>>a[i], pos[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		cin>>b[i];
		int dis = pos[b[i]] - i; // actual pos
		if (dis < 0) dis += n; // n-1 shifts to actual pos 
		++cnt[dis];
	}
	for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
	cout<<ans<<'\n';
    return 0;
}