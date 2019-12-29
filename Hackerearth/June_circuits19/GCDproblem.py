import math
mod=10**9+7
def Mobius_NC4(n):
   count=0
   for d in range(2,n//4+1):
       count+=answ[n//d]
   answ[n]=(int(Combin(n,4))-count)
   #print(n,answ[n])
   return (int(Combin(n,4))-count)
def Combin(n, r):
   C = [0] * (n + 1)
   C[0] = 1
   for i in range(1, (n + 1)):
       j = min(i, r)
       while(j > 0):
           C[j] = (C[j] + C[j - 1]) % mod
           j -= 1
   return C[r]
if __name__ == "__main__":
   t=int(input())
   while t>0:
       answ=[0]*(10**5+1)
       t-=1
       n=int(input())
       end=n//4
       ans=0
       count=0
       for x in range(end,0,-1):
           ans=(ans+(Mobius_NC4(n//x)*pow(x,4,mod))%mod)%mod
           #print(Mobius_NC4(n//x))
       print(ans)