 
class Solution {
public:
    int numSquares(int n) {
        if(n < 3){
            return n;
        }
        int *dp = new int[n+1];
        
        /*while(num%4==0) num = num/4;
        if(num%8 == 7) return 4;
        if(perf(num)) return 1;
        for(int i=1;i*i<=num;i++) if(perf(num-i*i)) return 2;
        return 3;
        */
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4;i <= n;i++){
            dp[i] = i;
            for(int j = 1;j*j <= i;j++){
                dp[i] = min(dp[i],dp[i - j*j]+1);
            }
        }
        
        return dp[n];
    }
};