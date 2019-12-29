    #include<stdio.h>
    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<set>
    #include<map>
    #include<string.h>
    #include<math.h>
    using namespace std;
     
    typedef long long int lli;
    #define fori(x,n) for(int x = 0; x < n; ++x)
    #define pb push_back
    #define mp make_pair
     
     
    lli discrete_log(lli a,lli b,lli p)  //a^x % m = b, let x=Bi-j where B= sqrt(m)
    {
     
        //solving a^(i*B) % p= b*(a^j);
        lli B=sqrt(p) + 1;
     
        lli r=1;
        for(lli i=0;i<B;i++)
            r = (r*a)%p;
     
        map<lli,lli> mp;
     
        lli cur=r;
        for(lli i=1;i<=B;i++)
        {
            mp[cur]=i;
            cur=(cur*r)%p;
        }
     
        cur=b;
     
        for(lli i=0;i<=B;i++)
        {
            if(mp[cur])
            {
                lli ans=B*mp[cur]-i;
                if(ans < p)
                    return ans;
     
            }
            cur=(cur*a)%p;
        }
     
        return -1;
     
     
    }
     
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            lli r,s,p;
     
            scanf("%lld%lld%lld",&r,&s,&p);
            if(s==1)
            {cout << 1 << endl;continue;}
     
            lli ans= (s*(r-1)+1LL)%p;
     
            ans= discrete_log(r,ans,p);
            cout << ans << endl;
        }
        return 0;
    }
