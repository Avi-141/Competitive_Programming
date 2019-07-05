#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn = 4e5+10;
     
ll pow_mod(ll a,ll n,ll mod)
{
        ll ret=1;
        while(n)
        {
         if(n&1)
            ret=(ret%mod*a%mod);
            n>>=1;
            a=(a%mod*a%mod);
        }
        return ret%mod;
    }
    
int main()
{
    map<ll,ll>mp;
    vector<ll> a(maxn);
    ll n;
    ll p,k,ans;
    cin>>n>>p>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            //(ai+aj)*(ai2+aj2)===ai4-aj4===k*(ai-aj)
            //why was this E
            // count equal pairs
            ll pair_pow4 = pow_mod(a[i],4,p);
            pair_pow4 = (pair_pow4 - k*a[i]%p+p)%p;
            ans = ans + mp[pair_pow4];
            mp[pair_pow4]++; 
        }
        cout<<ans;
    	return 0;
    }

