#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 map<ll,ll>pair_same;
         ll n,mod,k;
         ll ans;

int main()
    {

         cin>>n>>mod>>k;
        ll a;
        for(int i=1;i<=n;++i)
        {
            cin>>a;
            int res=(1ll*a*a%mod*a%mod*a%mod+mod-1ll*k*a%mod)%mod;
            ans+=pair_same[res];
            ++pair_same[res];
        }
        cout<<ans;
    }