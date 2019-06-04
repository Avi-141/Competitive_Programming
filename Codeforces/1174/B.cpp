#include<bits/stdc++.h>
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
#define dd double
using namespace std;

 
int main()
{
  ll n,j;
  cin>>n;
  vector<ll> vec(n),temp(n);
  forloop(i,n)
  {
  	cin>>vec[i];
  	temp[i]=vec[i];  
  }
  sort(vec.begin(),vec.end());
  ll counte=0,counto=0;
  forloop(i,n)
  {
  	if(vec[i]%2==0)
  		counte++;
  	if(vec[i]%2!=0)
  		counto++;
  }
  if(counte>0&&counto>0)
  {
		forloop(i,n)
		cout<<vec[i]<<" ";
		exit(0);
	}
else if(counte==n-1||counto==n-1)
{
  forloop(i,n)
  cout<<temp[i]<<" ";
  exit(0);
}
}