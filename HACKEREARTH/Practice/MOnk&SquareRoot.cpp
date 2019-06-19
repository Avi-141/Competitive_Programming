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


    int main(){
        ll t; 
        cin>>t;
        while(t--)
        {
            ll n, m;
            cin>>n>>m;
            ll low=sqrt(n);
            ll ans = -1;
            ll lim=ceil(ld(m/2.0)); // editorial.
            for(ll i=low; i<lim; i++)
            if((i*i)%m == n)
            {
                ans = i;
                break;
            }
            cout<<ans<<endl;
        }
        
    }

