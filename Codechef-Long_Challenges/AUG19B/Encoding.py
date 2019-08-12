def ti(c):
    return ord(c)-ord('0')

MOD = 1000000007
t = int(input())
for _ in range(t):
    l = input().split()
    ll = int(l[1])-1
    l = str(ll)
    r = input().split()
    r = r[1]
    
    def ans(s):
        p, sum1 =1,0
        s = s[::-1]
        s2 = 0
        
        sp,sx = 1,1
        for i in range(1,len(s)):
            si = ti(s[i])
            si1 = ti(s[i-1])
            if(i!=1):
                sp = (sp*10)%MOD
            if i>=2:
                s2 = (s2+(ti(s[i-2])*sx)%MOD)%MOD
                sx = (sx*10)%MOD
                
            spi = (sp*si)%MOD
            sum1 = (sum1 +((spi)*(spi-1)//2)%MOD)%MOD
            if(si1>si):
                sum1 = (sum1 + (spi*sp)%MOD)%MOD
            elif(si1==si):
                #print(si,si1,i)
                if i!=1:
                    str2 = s2+1
                    sum1 = (sum1 + (spi*str2)%MOD)%MOD
                else:
                    sum1 = (sum1 + si)%MOD
                
                
            p -= 1
            #print(i,si,sp,spi,s2,sum1)
        return sum1
    sl = ans(l)
    sr = ans(r)
    nl = (ll*(ll+1)//2)%MOD
    rr = int(r)
    rn = (rr*(rr+1)//2)%MOD
    print(((rn-sr)-(nl-sl))%MOD)
    
