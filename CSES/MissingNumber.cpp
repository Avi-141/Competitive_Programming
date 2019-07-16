#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
	ll n;
	cin>>n;
	vector<ll> vec(n);
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		cin>>vec[i];
		sum+=vec[i];
	}
    ll exp=n*(n+1);
    exp/=2;
    cout<<exp-sum;
}