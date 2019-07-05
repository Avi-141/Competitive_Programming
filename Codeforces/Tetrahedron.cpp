#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
    ll n,i,p=1;
    cin>>n;
    vector<ll> dp(n+1);
    for(i=2;i<=n;i++)
    {
        p=(p*3)%MOD;
        dp[i]=(p-dp[i-1]+MOD)%MOD;
    }
    cout<<dp[n];
}