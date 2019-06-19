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


    ll gcd(ll a,ll b)
    {
    	return (!b)?a:gcd(b,a%b);
    }
    int main()
    {
    	int n;
    	cin>>n;
    	coordsector<ll>coords;
    	map<ll,int>m;
    	for(int i=1;i<=n;i++)
    	{
    		ll x1,y1,x2,y2;
    		cin>>x1>>y1>>x2>>y2;
    		ll g=gcd(abs(y2-y1),abs(x2-x1));
            g=g+1;
    		coords.push_back(g);
    		if(!m[g])
                m[g]=i;
    	}
    	sort(coords.begin(),coords.end());
    	int q;
    	cin>>q;
    	while(q--)
    	{
    		ll x;
    		cin>>x;
    		int index=lower_bound(coords.begin(),coords.end(),x)-coords.begin();
    		if(index==coords.size())
                cout<<"-1\n";
    		else 
                cout<<m[coords[index]]<<"\n";
    	}
    	return 0;
    }

