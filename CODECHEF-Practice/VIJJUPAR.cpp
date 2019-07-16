#include <iostream>
#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;
#define ll long long 

int main(){

    ll  t;
    cin >> t;
    while(t--){
        ll  n,k;
        cin >> n >> k;
        ll  b[k];
        for(ll  i = 0;i<k;i++){
            cin >> b[i];
        }

        ll  dp[k][101];
        for(ll  i = 0;i<k;i++){
            for(ll  j = 0 ;j<=n;j++){
                dp[i][j] = 0;
            }
        }
        for(ll  i = 0;i<=b[0];i++){
            dp[0][i]= 1;
        }

        for(ll  i = 1;i<k;i++){
            for(ll  j = 0;j<=n;j++)
            {
                for(ll  ki = 0;ki<=b[i];ki++)
                {
                    if(j-ki<0)break;
                    dp[i][j]=(dp[i][j]+dp[i-1][j-ki])%MOD;
                }
            }
        }

        cout << dp[k-1][n] << endl;

    }
}