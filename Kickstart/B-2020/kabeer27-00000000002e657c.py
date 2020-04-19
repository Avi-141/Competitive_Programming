from math import log2 
MAX=200001
dp=[0]*MAX
def probability( k, n):  
  
    ans = 0 
    for i in range(k,n+1): 
        res = dp[n] - dp[i] - dp[n-i] - n  
        ans = ans + pow(2.0, res)  
      
    return ans  
  
  
def precompute():  
    for i in range(2,MAX):  
        dp[i] = log2(i) + dp[i-1]

precompute()

for _ in range(int(input())):
    W, H, L, U, R, D = map(int, input().split())
    right_side = 0
    down_side = 0
    if R != W and U >= 2:
        right_side = probability(R, R + U - 2)
    if D != H and L >= 2:
        down_side = probability(D , D + L - 2)
    
    print("Case #"+str(_ + 1)+": ", end=  "")
    print(right_side + down_side)
                    