#include<bits/stdc++.h>
using namespace std;
const int N = 519, Mod = 1e9  +7;
int n, m, dp[N], tdp[N];
int main(){
    scanf("%d%d", &n, &m);
    dp[0] = 1;
    for (; n; n --){
        int a;
        scanf("%d", &a);
        memset(tdp, 0, sizeof(tdp));
        for (int i = 0; i <= a; i ++)
            for (int j = 0; j < 512; j ++){
                tdp[i ^ j] += dp[j];
                if (tdp[i ^ j] >= Mod)
                    tdp[i ^ j] -= Mod;
                }
        memcpy(dp, tdp, sizeof(dp));
        }
    for (int i = 0; i <= m; i ++)
        printf("%d ", dp[i]);
    return 0;
}