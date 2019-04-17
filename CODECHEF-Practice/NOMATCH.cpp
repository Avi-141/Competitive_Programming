#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t,n;
 long long  maxsum;
 cin>>t;
 while(t--)
 	{
 		cin>>n;
 		long long distance[n+1];
 		for(int i=1;i<=n;i++)
 			cin>>distance[i];
 		sort(distance+1,distance+n+1);
 		maxsum=0;

 		for(int i=1;i<=n/2;i++)
 	        maxsum=maxsum+fabs(distance[i]-distance[n-i+1]);
 		//mod distance
 		//brilliant.org
 		cout<<(maxsum)<<endl;

 	}
 	}