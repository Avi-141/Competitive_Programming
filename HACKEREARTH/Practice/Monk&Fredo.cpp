/*// Gives TLE after some AC cases. 
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
}*/

// Ac solution
// credits:// https://aleigorithms.wordpress.com/category/hackerearth/
/*// Gives TLE after some AC cases. 
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
}*/

// AC solution
//O(log(max(a,b)))
// credits:// https://aleigorithms.wordpress.com/category/hackerearth/
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
typedef long long int uli;
    
    uli xgcd(uli a,uli b,uli &x,uli &y)
    {
      if(b==0){
        x=1,y=0;
        return a;
      }
      uli x1,y1;
      uli g=xgcd(b,a%b,x1,y1);
      x=y1;
      y=x1-(a/b)*y1;
      return g;
    }
    uli cel(uli a,uli b){
      if(a>=0)return (a+b-1)/b;
      return -( (-a)/b );
    }
    uli flr(uli a,uli b){
      if(a>=0)return a/b;
      return -( (-a+b-1)/b );
    }
    int main(){
      int t;
      scanf("%d",&t);
      while(t--){
        uli a,b,c;
        cin>>a>>b>>c;
        uli x,y;     
        uli g=xgcd(a,b,x,y);
        if(c%g!=0){
          cout<<"0"<<"\n";
          continue;
        }
        uli u=a/g,v=b/g;
        x=x*(c/g);
        y=y*(c/g);
    //    cout<<"from="<<-x<<"/"<<v<<" to "<<y<<"/"<<u<<endl;
        uli from=cel(-x,v);
        uli to=flr(y,u);
        uli ans=to-from+1;
        if(from>to)ans=0;
          cout<<ans<<"\n";
      }
      return 0;
    }