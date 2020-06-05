#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;

char s[100010];
ll t, n, k;
ll f[1000010], g[1000010], p[1000010];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		scanf("%s",s+1);
		for(ll i=1; i<=n; i++) 
			p[i] = p[i-1] + (s[i]=='1');
		for(ll i=1; i<=n; i++)
		{

			f[i] = min(f[max(0LL, i-k)] - p[max(0LL, i-k)], 0LL) + p[i-1] + (s[i]=='0');
			g[i] = min(g[i-1], f[i-1]) + (s[i]=='1');
		}
		printf("%d\n", min(f[n], g[n]));
	}
}