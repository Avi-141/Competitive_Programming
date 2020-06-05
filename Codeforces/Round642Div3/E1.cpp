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
int main()
{
 
   	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	int t;
	cin >> t;
	for(; t; --t)
	{
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int tots = 0;
		for(int i = 0; i < n; ++i)
			tots += (s[i] == '1');
		// one solution is making all lights =0;
		//upper bound on cost
		int ans = tots;
		// if pref sum of a subseq=0 turn off lights// no cost
		// if pref sum >0 turn on the off 
		// like max subarray sum
		for(int i = 0; i < k; ++i)
		{
			int dif = 0;
			for(int j = i; j < n; j += k)
			{
				if(s[j] == '1')
					++dif;
				else
					--dif;
				// if dif <0 
				dif = max(dif, 0);
				ans = min(ans, tots - dif);
			}
		}
		cout << ans << '\n';
	}
    return 0;
}
