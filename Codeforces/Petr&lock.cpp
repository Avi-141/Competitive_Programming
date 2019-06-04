
/* for(int i=0;i<n;i++)
 {
 	sum+=arr[i];
 	if(arr[i]==arr[i+1])
 		count++;
 }
if(count%2)
	cout<<"NO\n";
else if(!count%2||sum==360)
	cout<<"YES\n";*/
#include<bits/stdc++.h>
using namespace std;
int a[20],n;
bool dfs(int x,int s)
{
    if(x==n)
      return s%360==0?true:false;
    return dfs(x+1,s+a[x+1])||dfs(x+1,s-a[x+1]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    printf(dfs(0,0)?"YES\n":"NO\n");
    return 0;
}