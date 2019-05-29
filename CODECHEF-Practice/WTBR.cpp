#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define f first 
#define s second
using namespace std;
typedef pair<ll,ll> pairs;


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
      ll n;
      cin>>n;
      vector<ll> d1(n),d2(n),d3(n),d4(n);
      ll x,y;
      for(int i=0;i<n;i++)
      {
      	cin>>x>>y;
      	d1[i]=x-y;
      	d2[i]=x+y;
      	d3[i]=-x+y;
      	d4[i]=-x-y;
      }
   sort(d1.begin(),d1.end());
   sort(d2.begin(),d2.end());
   sort(d3.begin(),d3.end());
   sort(d4.begin(),d4.end());
   ll mins=LLONG_MAX;

   for(int i=1;i<n;i++)
   {
   	  if(abs(d1[i]-d1[i-1])<mins)
          mins=abs(d1[i]-d1[i-1]);
    }
     for(int i=1;i<n;i++)
     {
   	  if(abs(d2[i]-d2[i-1])<mins)
          mins=abs(d2[i]-d2[i-1]);
      }
      double ans=mins/2.0;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    
   }
}