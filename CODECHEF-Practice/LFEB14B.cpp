#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;      
  
    x = x % p; 
    while (y > 0) 
    {  
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
} 
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
 	lli n;
 	cin>>n;
 	lli arr[n];
 	for(int i=0;i<n;i++)
 		cin>>arr[i];
 	lli count=0;
 	sort(arr,arr+n);
 	for(int i=0;i<n;i++)
 	{
 		if(arr[i]==arr[n-1])
 			count++;}
 lli ans=power(2,count,mod);
 cout<<ans<<endl;
}
}
