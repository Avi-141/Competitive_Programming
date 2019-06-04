#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define vi vector<int> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vl vector<ll>
#define pii pair<int, int>

ll ans;
int flag;

void dfs(vi adj[], bool vis[], int src, int prev, int a[], int l, ll sum, int ctr, int pr)
{
	vis[src]=true;
	vi:: iterator it;
	for(it=adj[src].begin(); it!=adj[src].end(); it++)
	{
		if(!vis[*it])
		{
			if(a[*it]!=-1)
			{
				pr=1;
				if(a[*it]-prev<0)
					flag=1;
				//ans+=a[*it]-prev;
				//cout<<ans<<endl;
				dfs(adj,vis,*it,a[*it],a,INT_MAX,0,0,0);
				sum+=a[*it]-prev;
				ctr++;
				l=min(l,a[*it]-prev);
			}
			else
				dfs(adj,vis,*it,prev,a,INT_MAX,0,0,0);
		}
		//cout<<pr<<endl;
	}
	if(pr)
		{
			ans+=l+sum-(l*ctr);
			//cout<<"ans= "<<ans<<endl;
		}
}

int main()
{
	int n,tmp;
	cin>>n;
	int a[n];
	vi* adj= new vi[n];
	bool vis[n];
	for(int i=0;i<n;i++)
		vis[i]=false;
	flag=0;
	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		adj[i].pb(tmp-1);
		adj[tmp-1].pb(i);
	}
	for(int i=0;i<n;i++)
		cin>>a[i];
	ans=a[0];
	dfs(adj,vis,0,a[0],a,INT_MAX,0,0,0);
	if(flag)
		cout<<-1;
	else
		cout<<ans;		
}	