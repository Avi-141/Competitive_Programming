#include<bits/stdc++.h>
using namespace std;
#define deptchef long long int
int main()
{

deptchef n,t;
cin>>t;
while(t--)
{
 cin>>n;
 deptchef flag;
 deptchef iter,temp,ans=-1;
 deptchef attack[n];
 deptchef defense[n];
 for(iter =0;iter<n;iter++){ cin>>attack[iter];}
 for(iter =0;iter<n;iter++){ cin>>defense[iter];}
 	if(attack[n-2]+attack[0]<defense[n-1])
 		ans=defense[n-1];
 for(iter =1;iter<n-1;iter++)
 {
 	if(attack[iter-1]+attack[iter+1]<defense[iter])
 		ans=max(ans,defense[iter]);
 }
 if(attack[n-1]+attack[1]<defense[0])
    ans=max(ans,defense[0]);
  if(ans==-1) cout<<-1<<endl;
  else
    cout<<ans<<endl;
 }
}