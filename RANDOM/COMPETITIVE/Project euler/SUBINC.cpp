#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int t,n,i,sum;
   cin>>t;
   while(t--)
   {
       cin>>n;
       long long int a[n],dp[n];
       for(i=0;i<n;i++)
         cin>>a[i];
        // sort(a,a+n);
       for(i=0;i<n;i++)
        dp[i]=1;
       for(i=1;i<n;i++)
       {
           if(a[i]>=a[i-1])
            dp[i]=dp[i]+dp[i-1];
       }
       sum=0;
       for(i=0;i<n;i++)
        sum+=dp[i];
        cout<<sum<<endl;
   }
}
