#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define rep(i, a,b) for(ll  i=(a);i<=(b);++i)
#define _rep(i, a,b) for(ll  i=(a);i>=(b);--i)
#define iter(it) begin(it),end(it)
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
#define MN 200005
#define ll long long
#define mod 998244353
#define pii pair<ll,ll>
using namespace std;


/*ll  n;
ll  a[MN],b[MN],c[MN];
map<ll ,ll >mp;
ll  cc;
void ad(ll  x)
{
	if(mp[x]==0)++cc;++mp[x];
}
void su(ll  x)
{
	--mp[x];if(mp[x]==0)--cc;
}
void ans(ll  v)
{
	F(i,1,n)if(b[i]==v)
	{
		prll f("%d\n",i);break;
	}
}
ll  main(){
	scanf("%d",&n);
	if(n<=3)return puts("1"),0;
	F(i,1,n)scanf("%d",a+i),b[i]=a[i];
	sort(a+1,a+n+1);
	F(i,1,n-1)c[i]=a[i+1]-a[i];
	F(i,1,n-1)ad(c[i]);
	F(i,1,n){
		if(i==1)
		{
			su(c[1]);
			if(cc==1)return ans(a[1]),0;
			ad(c[1]);
		}
		else if(i==n)
		{
			su(c[n-1]);
			if(cc==1)return ans(a[n]),0;
			ad(c[n-1]);
		}
		else
		{
			su(c[i-1]),su(c[i]),ad(c[i-1]+c[i]);
			if(cc==1)return ans(a[i]),0;
			su(c[i-1]+c[i]),ad(c[i]),ad(c[i-1]);
		}
	}
	puts("-1");
	return 0;
}*/


bool remove(vector<pii>v,ll n,ll index)
{
    vector<ll>temp;
    for(ll  i=0;i<n;i++)
    {
        if(i!=index)
        {
            temp.pb(v[i].first);
        }
    }
    ll  d = temp[1]-temp[0];
    for(ll  i=1;i<n-1;i++)
    {
        if(temp[i]-temp[i-1] != d)  return false;
    }
    return true;
}

int64_t main()
{
    ll  n,val;
    cin>>n;
    vector<pii>vec(n);
    for(ll  i=0;i<n;i++)
    {
        cin>>val;
        vec[i].first = val; 
        vec[i].second = i+1;
    }
    if(n<=3)
    {
        cout<<"1\n";    
        return 0;
    }
    sort(vec.begin(),vec.end());
    if(remove(vec,n,0))
        cout<<vec[0].second<<"\n";
    else if(remove(vec,n,1))
        cout<<vec[1].second<<"\n";
    else{
        ll  d = vec[1].first - vec[0].first;
        for(ll  i=2;i<n;i++)
        {
            if(vec[i].first-vec[i-1].first != d)
            {
                if(remove(vec,n,i))
                    cout<<vec[i].second<<"\n";
                else
                    cout<<"-1\n";
                return 0;
            }
        }
    }

    
}