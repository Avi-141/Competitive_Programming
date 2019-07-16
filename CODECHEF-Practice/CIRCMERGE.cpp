    #include<bits/stdc++.h>
    #define bint int64_t
    #define For(i,st,en) for(bint  (i) = (bint )(st); (i) <= (bint )(en); ++(i))
    #define forn(i, n) for(bint  (i) = 0; (i) < (bint )(n); ++(i))
    #define clr(x) memset((x), 0, sizeof((x)))
    #define pb push_back
    #define abint (x) (x).begin(), (x).end()
    #define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
    #define mp make_pair
    #define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
    using namespace std;
    typedef long double ld;
    typedef unsigned long long ull;
    typedef pair<bint , bint > PII;
    typedef vector<bint > VI;
    typedef vector<VI> VVI;
    #define MODD 1000000007
    #define INF 999999999
    #define MAX 100000 + 5
    #define ll long long


 ll dp[1000][1000];
 ll prefix[1000];
 //ll arr[802];

ll sum(ll x,ll y){
        return prefix[y+1]-prefix[x];
    }
 ll solve(ll i,ll j)
 {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) 
          return dp[i][j];
        
        dp[i][j]=INF;
        
        for(ll k=i;k<=j;k++) 
            dp[i][j]=min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)+sum(k+1,j));
        
        return dp[i][j];
    }
 ll one=-1;
 int main(int argc, char const *argv[])
   {
       ll t;
       cin>>t;
       while(t--)
       {
        ll n;
        cin>>n;
        vector<ll> arr1(2*n-1);
        for(ll i=0;i<1000;i++)
        {
            for(ll j=0;j<1000;j++)
            dp[i][j]=one;
          }
        forn(i,n)
        {
            cin>>arr1[i];
            //arr[i]=arr1[i];
        }
       for(ll i=n;i<2*n-1;i++)
          arr1[i]=arr1[i-n];
       prefix[0]=0;
       for(ll i=1;i<2*n;i++) 
         prefix[i]=prefix[i-1]+arr1[i-1];
        
       ll mins=INF;
       forn(i,n){
                mins=min(mins,solve(i,i+n-1));
            }
       cout<<mins<<"\n";
       }
}