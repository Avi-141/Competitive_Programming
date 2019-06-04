#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int Mod=998244353;
const int maxn=100010;
int a[maxn],dp[maxn][101],sum[maxn],len[101];
int main()
{
    int N,K,L;
    scanf("%d%d%d",&N,&K,&L);
    rep(i,1,N) scanf("%d",&a[i]);
    sum[0]=1;
    rep(i,1,N)
    {
        rep(j,1,K) 
        len[j]=(a[i]==-1||a[i]==j)?len[j]+1:0;
        if(a[i]==-1)
        {
            rep(j,1,K) 
            {
                dp[i][j]=sum[i-1];
                if(len[j]>=L) 
                dp[i][j]=(dp[i][j]-(sum[i-L]-dp[i-L][j]+Mod)%Mod+Mod)%Mod;
            }
        }
        else  
        {
            dp[i][a[i]]=sum[i-1];
            if(len[a[i]]>=L) 
             dp[i][a[i]]=(dp[i][a[i]]-(sum[i-L]-dp[i-L][a[i]]+Mod)%Mod+Mod)%Mod;
        }
        rep(j,1,K) 
        sum[i]=(sum[i]+dp[i][j])%Mod;
    }
    printf("%d\n",sum[N]);
    return 0;
}