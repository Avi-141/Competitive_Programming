#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
 
using namespace std;
int n;
int a[200005];
bool vis[200005];
int ans[200005];
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			vis[i]=false;
			ans[i]=0;
		}
		int mx=0;
		for(int i=1;i<=n;++i)
		{
			if(vis[a[i]]) break;
			vis[a[i]]=true;
			mx=max(mx,a[i]);
			if(mx==i) ++ans[i];
		}
		mx=0;
		memset(vis,0,sizeof vis);
		for(int i=n;i>=1;--i)
		{
			if(vis[a[i]]) break;
			vis[a[i]]=true;
			mx=max(mx,a[i]);
			if(mx==n-i+1) ++ans[i-1];
		}
		
		int cnt=0;
		for(int i=1;i<=n;++i) if(ans[i]==2) ++cnt;
		printf("%d\n",cnt);
		for(int i=1;i<=n;++i) if(ans[i]==2) printf("%d %d\n",i,n-i);
	}
	return 0;
}