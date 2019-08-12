#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 100005

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--)
	{
     ll n;
     cin>>n;
     vector<ll> a(n),b(n);
     for(ll i=0;i<n;i++)
     	cin>>a[i];
     for(ll i=0;i<n;i++)
     	cin>>b[i];
     ll maxx=0;
     for(ll i=0;i<n;i++)
     {
     	a[i]=a[i]*20- b[i]*10;
     	if(a[i]<0)
     		a[i]=0;
     	maxx=max(a[i],maxx);
     }
     cout<<maxx<<"\n";
  }
	return 0;
}