from math import gcd

T=int(input())
for t in range(T):
    N,M=map(int,input().split())
    l=list(map(int,input().split()))
    a=[0]*(M+1)
    for i in range(len(l)-1):
        if l[i]!=l[i+1]:
            a[i+1]=gcd(l[i],l[i+1])
            for j in range(i,-1,-1):
                a[j]=l[j]//a[j+1]
            for j in range(i+1,M):
                a[j+1]=l[j]//a[j]
    # print(a)
    b=sorted(list(set(a)))
    d={}
    for i in range(len(b)):
        d[b[i]]=chr(65+i)
    ans=""
    for i in a:
        ans+=d[i]
    print("Case #"+str(t+1)+":",ans)