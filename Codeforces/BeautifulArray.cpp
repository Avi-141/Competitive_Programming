#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef pair<ll,long int> PIII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999

ll maxll(ll a,ll b)
{
	if(a>b)
		return a;
	else return b;
}



int main(int argc, char const *argv[])
{
	ll n,x;
	scanf("%lld %lld",&n,&x);
	ll kadane[n];
	forn(i,n)
	  scanf("%lld",&kadane[i]);

	  ll best=0,sum=0;
	  ll ans=0,best1=0,best2=0,best3=0;
	  forn(i,n)
	  {
	  	//sum=maxll(kadane[k],kadane[k]+sum);
	  	//best=maxll(sum,best);
	  	best3=maxll(maxll(maxll(maxll(0,kadane[i]),best1+kadane[i]),best2+kadane[i]),best3+kadane[i]);
	  	//best1=maxll(maxll(0,kadane[i]),best1+kadane[i]);
	  	best2=maxll(maxll(maxll(0,x*kadane[i]),best1+kadane[i]*x),best2+kadane[i]*x);
	  	best1=maxll(maxll(0,kadane[i]),best1+kadane[i]);
	  	///best3=maxll(maxll(maxll(maxll(0,kadane[i]),best1+kadane[i]),best2+kadane[i]),best3+kadane[i]);
	  	ans=maxll(ans,maxll(maxll(best1,best2),best3));
	  }
	  cout<<ans<<"\n";
	return 0;
}
