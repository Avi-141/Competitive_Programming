#include<bits/stdc++.h>
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define focurr(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
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
 
ll d[200005]= {0};
ll a[200005];
 
void sievedivisor(ll  n)
{
    ll  curr = sqrt(n);
    for (ll  i=1; i<=curr; i++)
    {
        if (n%i==0)
        {
            if (n == i*i)
                d[i]+=1;
            else
            {
                d[i]+=1;
                d[n/i]+=1;
            }
        }
    }
}
 
int  main()
{
    FASTER;
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        sievedivisor(a[i]);
    }
 
    ll t;cin>>t;
    while(t--){
        ll p, q;
        cin>>p>>q;
        ll hcf=__gcd(p,q);
        ll lcm = (p*q)/hcf;
        ll temp;
        if(lcm > 200000)
            temp = 0;
        else temp=d[lcm];
        cout<<d[p]+d[q]-temp<<"\n";
    }
}