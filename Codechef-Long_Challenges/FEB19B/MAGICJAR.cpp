#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int t,n,i,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int a[n];
        sum=0;
	   for(i=0;i<n;i++)
			cin>>a[i];
       for(i=0;i<n;i++)
          a[i]=a[i]-1;
       for(i=0;i<n;i++)
	     sum=sum+a[i];
	 cout<<sum+1<<endl;
	}
}