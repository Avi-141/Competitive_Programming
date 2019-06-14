#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); (i)++)
#define clr(x) memset((x), 0, sizeof((x)))
//#define push_back push_back
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

 ll n,m;
 cin>>n>>m;
 VI store(m),tree(m);
 	forn(i,m)
 		cin>>tree[i];
 	ll overflow=0,lc,rc,orig;
   
   store[0]=n;

   if(tree[0]>n)
   	cout<<0;

   forn(i,m)
   {
     n=store[i]-tree[i];
     if(n>0)
     {
      if(n%2==0)
      {
        lc=2*i+1;
        rc=2*i+2;
         if(lc<m&&rc<m)
         {
         	n=n/2;
         	store[lc]=n; 
         	store[rc]=n;
         }
         else if(lc<m&&rc>=m)
         {
         	n=n/2;
         	//n+=1;
         	store[lc]=n;
         	overflow+=n;
         }
         else 
         	overflow+=n;
     }

     else 
     {
        lc=2*i+1;
        rc=2*i+2;
         if(lc<m&&rc<m)
         {
         	n=n/2;
         	store[lc]=n+1; 
         	store[rc]=n;
         }
         else if(lc<m&&rc>=m)
         {
         	orig=n/2;
         	n=n/2;
         	n+=1;
         	store[lc]=n;
         	overflow+=orig;
         }
         else 
         	overflow+=n;
     }
    }
  //  else break;
   }
cout<<overflow<<endl;
}