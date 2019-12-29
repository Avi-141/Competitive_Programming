//https://discuss.codechef.com/t/how-to-solve-strength-of-the-game-from-hackerearth-july-circuits-2019/34707/8
using namespace std;
#include    <bits/stdc++.h>
#define     ll      long long
#define     ret     return
#define     mod     1000000007
#define     REP(i,a,n)       for(ll i=a;i<n;++i)
#define     REPA(i,a,n)      for(ll i=a;i<=n;++i)

const int N=512;
int n,m,arr[N],dp[513][515];    
int main()
{
    cin >> n >> m;
   
    REP(i,0,n) cin >> arr[i];
    REPA(i,0,arr[0]) dp[0][i] = 1;
    REP(i,1,n)
    {
        REPA(j,0,arr[i])
        {
            REPA(k,0,513)
            {
                dp[i][k] += dp[i-1][j^k];
                dp[i][k] %= mod;
            }
        }
    }
    
    REP(i,0,m+1) cout << dp[n-1][i] << " ";
}