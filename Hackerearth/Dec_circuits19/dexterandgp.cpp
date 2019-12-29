    #include <bits/stdc++.h>
    using namespace std;
    #define BigInt int64_t

    BigInt T,R,S,MOD;
    map<BigInt,BigInt> mp;
     
    BigInt ModMul(BigInt x,BigInt exp,BigInt MOD)
    {
        if(exp==0)
            return 1%MOD;
        BigInt tmp=ModMul(x,exp/2,MOD);
        if(exp%2==0)
            return tmp*tmp%MOD;
        return tmp*tmp%MOD*x%MOD;
    }
     
    int main()
    {
        cin>>T;
        while (T--)
        {
            cin>>R>>S>>MOD;
            if(MOD==2)
            {
                cout<<1<<"\n";
                continue;
            }
            BigInt Q=(S*(R-1)+1)%MOD;
            mp.clear();

            BigInt sq=sqrt(MOD),mul=1;
            
            for(BigInt r=0; r<sq; r++,mul=mul*R%MOD)
                mp[mul]=r;
            mul=ModMul(mul,MOD-2,MOD);
            
            BigInt N=-1;
            BigInt rbase = 1;
            
            for(BigInt q=0; q*sq<MOD; q++,rbase=rbase*mul%MOD)
            {
                BigInt x=(Q*rbase)%MOD;
                    if(mp.find(x)!=mp.end())
                    {
                        N=q*sq+mp[x];
                        break;
                    }
            }
            cout<<N<<"\n";
        }
     
        return 0;
    }