#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,x=0,total1=0,store=0,ans;
		char y;
		cin>>n;
		ll arr[n];
		cin>>arr[0];
		for(i=1;i<n;i++)
		{
			cin>>y>>arr[i];
			if(y=='-')
				arr[i]=-arr[i];
			store=store+arr[i];
		}
		ans=store;
		for(i=n-1;i>0;i--) //do not change loop .
		{
			total1=total1+abs(arr[i]);
			store=store-arr[i];
			if(arr[i]<0)
			{
				ans=max(store-total1+x,ans);
				x+=total1;
				total1=0;
			}
		}
		cout<<ans+arr[0]<<endl;
	}
	return 0;
}