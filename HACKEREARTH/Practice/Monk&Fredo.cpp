// Gives TLE after some AC cases. 
// Complexity O(up_bnd/y);


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


int main()
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll  x,y,z;
        cin>>x>>y>>z;
        
        if(y<x)
        swap(x,y);
            
        ll  up_bnd = z/x;
        ll  count=0;
            
        for(ll  i=0; i<=up_bnd; i++)
        {
            if((z-(i*x))==0)
                count++;
            else if((z-(i*x))%y==0)
                count++;
        }
        
        cout<<count<<endl;
    }
}