#include<bits/stdc++.h>
using namespace std; 
long long int* ans = NULL; 
long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main(){
	long long int n,t,i,x,k1,k2,k3,a,b;
	cin>>t;
	while(t--)
	{
		k1=0;k2=0;k3=0;
		long long int count1=0,count2=0;
	cin>>n>>a>>b;
	long long  int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	if(a%b==0)
		cout<<"BOB\n";
    else{
		for(int i=0;i<n;i++)
		{
			if((arr[i]%a)==0)
				count1++;
			else if((arr[i]%b)==0)
				count2++;
		}
		if(count1>count2)
			cout<<"BOB\n";
		 else
		 	cout<<"ALICE\n";
		}
	}
}
	/*long long int temp=gcd(a,b);
	temp=(a*b)/temp;
	for(i=0;i<n;i++)
		if(arr[i]%a==0)
			k1++;
	for(i=0;i<n;i++)
		if(arr[i]%b==0)
			k2++; 
    for(i=0;i<n;i++)
    	if(arr[i]%temp)
    		k3++; 
    long long int bob=k1-k3;
    long long int alice=k2-k3;
    if(bob>=alice)
    	cout<<"BOB\n";
    else
    cout<<"ALICE\n";
	}
	}*/
	//return 0;