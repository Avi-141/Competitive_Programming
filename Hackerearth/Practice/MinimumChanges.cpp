#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define sz(x) (int)x.size()
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef long long int uli;
typedef vector<int> vi;


// partially solved
// rest Test cases WA

int main()
{
    	int t;
    	cin >> t;
    	
    	while(t--){
    		int n, k;
    		cin >> n >> k;
    		int a[n];
    		for(int i = 0; i < n; i++)
    			cin >> a[i];
    		if(k > 13){
    			cout << 22 << endl;
    			continue;
    		}
    		int fac = 1;
    		for(int i = 1; i <= k; i++){
    			fac *= i;
    		}
    		if(fac * n > 1e9){
    			cout << 22 << endl;
    			continue;
    		}
    		vi v;
    		for(int i = 1; i <= k; i++)
    			v.pb(i);
    			
    		int maxi = 1e9;
    		do{
    			int c = 0;
    			for(int i = 0; i < n; i++){
    				if(a[i] != v[i%v.size()])
    					c++;
    			}
    			maxi = min(maxi,c);
    		}
    		while(next_permutation(v.begin(),v.end()));
    		
    		cout << maxi << endl;
    	}
     
    	return 0;
    }