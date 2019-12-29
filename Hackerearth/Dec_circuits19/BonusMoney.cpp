#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=200000;
const ll M=200000;
ll mod = 1e9 + 7;
     
int main(){

    ll t;
    cin >> t >> mod;
     
    ll dp[N + 1][M + 1];
    for (ll i = N; i >= 1; --i) {
        for (ll j = 0; j <= M; ++j) {
            
            if (i == N)
            {
               dp[i][j] = 1;
               continue;
            }
     
            dp[i][j] = dp[i + 1][j];
     
            ll rest = N - i + 1;
            if (j >= rest)
            {
                dp[i][j] += dp[i][j - rest];
                dp[i][j] %= mod;
            }
        }
    }
     
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        cout << dp[N - n + 1][m] << endl;
    }
}