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
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007


ull fast_pow(ull base, ull n,ull M) 
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    ull halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
ull findMMI_fermat(ull n,ull M)
{
    return fast_pow(n,M-2,M);
}

int main(int argc, char const *argv[])
{
  
  ull t;
  cin>>t;
  test:
  while(t--)
  {
    ull n,k;
    cin>>n>>k;



       ull last_term=k-1;

       ull d=n-1;

       if(n==2)
       {
        cout<<ull((k*(k-1)/2.0))%MOD<<"\n";
        goto test;
       }
       else if(n>=k%%n!=2)
       {
        cout<<(k-1)%MOD<<"\n";
        goto test;
       }
       
       ull terms=ull((ld(k-1)/ld(n-1)));
       terms=terms;
       ull temp=terms;
       terms=terms+1;
       temp=(temp*terms)%MOD;
       temp=(temp/2);
       ull part1=(terms*last_term)%MOD;
       ull part2=(temp*d);
       ull answer=(part1-part2)%MOD;
       
    else if(n<k&&n!=2)
    {   
    cout<<answer<<"\n";
    goto test;
  }

  }
}
