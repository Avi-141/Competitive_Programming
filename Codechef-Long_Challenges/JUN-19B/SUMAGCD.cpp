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

VI mults,notmults;

ll findGCD(vector<ll> arr, ll n,ll check) 
{ 
    ll result = arr[0]; 
    for (ll i = 1; i < n; i++) 
      if(arr[i]!=check)
      {
        result = __gcd(arr[i], result); 
      }
  
    return result; 
}
int main()
{
	ll t;
	cin>>t;
	lab:
while(t--)
{
     ll n;
     cin>>n;
     VI arr(n),vec;
     set<ll> st;
     
     ll submax=0,count=0,counts=0;
     ll check=0;
     forn(i,n)
     {
      cin>>arr[i];
      st.insert(arr[i]);
     }
     sort(all(arr));
    auto setIterator = st.begin();
    vec.assign(st.begin(), st.end());
    sort(all(vec));

    if(st.size()==1)
    {
        cout<<2*(*setIterator)<<"\n";
        goto lab;
    }
    if(st.size()==2)
    {
      cout<<vec[0]+vec[1]<<"\n";
    }
    
    //vec.assign(st.begin(), st.end());
    ll sz=vec.size();
    ll maxx=vec[sz-1];
    ll nextmax=vec[sz-2];
   // cout<<maxx<<" "<<nextmax<<"\n";
    //ll maxx=findGCD(vec,sz,max1);
    //ll nextmax=findGCD(vec,sz,nmax1);
    //ll fin1=arr[0]+arr[n-1];
    //ll fin2=arr[0]+arr[n-2];
   
   /*forn(i,n)
   {
       if(arr[i]!=arr[i+1])
        count++;
      else counts++;
   }*/
    ll gcd_upper=arr[0]+arr[n-1];
    ll gcd_lower=arr[n-1]+1;
    ll singleset=0,flag=0;
    
    ll gcd_nohigh=findGCD(vec,sz,maxx);
    ll gcd_nosechigh=findGCD(vec,sz,nextmax);
    
   ll gcd_high1=gcd_nohigh+maxx;
    ll gcd_sechigh1=gcd_nosechigh+nextmax;
    if(gcd_high1>gcd_sechigh1)
    {
       singleset=maxx;
       cout<<singleset+gcd_nohigh<<"\n";
       goto lab;
     }
      else 
      {
          singleset=nextmax;
          cout<<singleset+gcd_nosechigh<<"\n";
       goto lab;
	}
}
}