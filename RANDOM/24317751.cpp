/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005


int main()
{
	
	io
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		std::vector<ll> a(n);
		rep(i,0,n)
		{
			cin>>a[i];
		}
		std::vector<long double> p(n);
		rep(i,0,n)
		{
			cin>>p[i];
		}		
		ll dp[n][30];
		memset(dp,0,sizeof(dp));
		rep(i,0,n)
		{
			ll j=a[i],cnt=0;
			while(j)
			{
				dp[i][cnt++]=j%2;
				j/=2;
			}
		}
		long double ans=0;
		rep(i,0,30)
		{
			long double ans1[2];
			ans1[0]=1;
			ans1[1]=0;
			rep(j,0,n)
			{
				long double temp[2]={0};
				if(dp[j][i])
				{
					temp[1]=p[j]*1.0*ans1[0]+(1-p[j])*1.0*(ans1[1]);
					temp[0]=(1-p[j])*1.0*ans1[0]+(p[j])*1.0*(ans1[1]);
					ans1[0]=temp[0];
					ans1[1]=temp[1];
				}
			}
			ans+=(1.0*pow(2,i)*ans1[1]);
		}
		cout<<fixed<<setprecision(21)<<ans<<endl;
	}
	
}