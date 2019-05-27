#include <bits/stdc++.h>
#define ll long long
#define array(x,n) (x,x+n)
#define vector(v) (v.begin(),v.end())
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define odd(x) (x&1)
#define even(x) (!x&1)
#define fbei(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fbe(i,x,y) for(ll i=x;i<=y;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
using namespace std;

bool isnotvowel(string s,ll i)
{
  return (s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u');
}
bool nextis(string s,ll i)
{
  return (s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u');
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	string strings;
	cin>>strings;
	int z=0;
	for(int i=0;i<n;i++){
		 if(isnotvowel(strings,i))
        if(nextis(strings,i))
          z++;
    }
 cout<<z<<endl;
   }
 return 0;
}