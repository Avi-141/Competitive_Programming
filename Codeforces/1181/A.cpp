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


int main(int argc, char const *argv[])
{
	ll x,y,z;
	cin>>x>>y>>z;

	ll temp=floor((x+y)/z);
	ll check1=z-max(x%z,y%z);
	//ll check2=z-(y%z);
	cout<<temp<<" ";
    if((x%z+y%z)<z)
     cout<<0;
   else 
   	 cout<<check1;
	//cout<<temp<<" "<<check1;
	return 0;
}