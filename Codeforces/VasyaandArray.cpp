#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
const int MOD = 1000000007;
const int MX = 200005;
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
const ll ranges=100000;
     
int main(){
    	
    	ll n, m; 
    	cin >> n >> m;
    	vpl quer2;
    	vl arr(n + 1, -1);
    	// fill array with -1;
    	while(m--)
    	{
    		ll t, l, r; 
    		cin >> t >> l >> r;
    		if (t == 1) 
    		{
    			for (ll i = l + 1; i <= r; ++i)
    			 {
    				arr[i] = 0; // fill zeroes for sorted range
    			}
    		} 
    		else 
    		{
    			quer2.push_back({l, r});
    		}
    	}
    	arr[0] = ranges;
    	// since it is non decreasing , keep array ele at min=n
    	// increase 
    	for (ll i = 1; i <= n; ++i) // now fill the whole array .
    	{
    		arr[i] += arr[i - 1];
    	}
    	for (auto range : quer2) 
    	{
    		if (is_sorted(arr.begin() + range.first, arr.begin() + range.second + 1)) 
    		{
    			return cout << "NO" << endl, 0;
    		}
    	}
    	cout << "YES" << endl;
    	for (ll i = 1; i <= n; ++i) 
    	{
    		cout << arr[i] << " ";
    	}
    	cout << endl;
    }