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


int main(int argc, char const *argv[])
{

	ll t;
	cin>>t;
	labs:
	while(t--)
	{
      int d;
      cin>>d;
      string s;
      cin>>s;
      double pr=0;
      int temp=0;
      forn(i,d)
       if(s[i]=='P')
       	pr++;
     if(pr/d>=0.75)
     {
     	cout<<0<<"\n";
     goto labs;
     }
   For(i,2,d-3)
   {
    if(s[i]=='A'&&((s[i-1]=='P'||s[i-2]=='P')&&(s[i+1]=='P'||s[i+2]=='P')))
     {
       temp++;
       pr++;
     }
 double attend=pr/d;
 attend=(int)(attend*100);
 attend=attend/100;

 if(attend>=0.75)
 {
 	cout<<temp<<"\n";
    goto labs;
   }
  }
 cout<<-1<<"\n";
 }
}
