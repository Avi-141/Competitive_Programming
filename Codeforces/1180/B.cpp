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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef pair<ll,long int> PIII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999




int main()
{
  ll n,zero=0,idx;
  cin>>n;
  ll l[n];
  forn(k,n)
  {
    cin>>l[k];
    if(l[k]>=0) l[k]=-l[k]-1;
    if(l[k]<zero)
    {
    	zero=l[k];
    	idx=k;}
  }
  if(n%2)
   l[idx]=-l[idx]-1;
  forn(j,n)
  {
    cout<<l[j]<<' ';
  }
}