#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(x) x.begin(),x.end()
     
    ll k[2];
 int main()
    {
    	ll n;
    	cin >> n;
    	ll a[n+1];
     
    	for(ll i=0;i<n;i++)
    		cin >> a[i];
     
    	ll p=0, q=n-1;
    	ll i=0;
     
    	while(p <= q)
    	{
    		if(a[p] < a[q])
    		{
    			k[i%2]+=a[q];
    			q--;
    		}
    		else
    		{
    			k[i%2]+=a[p];
    			p++;
    		}
    		i++;
    	}
    	cout << k[0] << " " << k[1];
    }
     
    	