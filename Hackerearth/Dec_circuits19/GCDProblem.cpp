    #include <bits/stdc++.h> //White_Rat MS
    #define mod 1000000007
    #define INF INT_MAX
    #define max_range 1<<20
    #define ll long long
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
    using namespace std;
  
    ll power(ll x,ll y) {
      ll res=1; x =x%mod; 
       while (y > 0) {
        if(y&1)
          res=(res*x)%mod; 
          y=y>>1; x=(x*x)%mod;
        } 
    return res;}
    vector<vector<ll> > newdp(ll A, ll B){ 
      vector<vector<ll> > dp; dp.resize(A+1);
      for(int i = 0; i < A+1; i++){
        dp[i].resize(B+1);
        
      for(int j = 0; j < B+1; j++)
        dp[i][j] = -1;
      } 
    return dp;
   }
    vector<ll> all_prime;
    void prime()
    {
     bool hash[1000000];
     memset(hash,false,sizeof hash); 
     for (int p = 2; p * p < 1000000; p++)
      if (hash[p] == true)
        for (int i = p * 2; i < 1000000; i += p)
          hash[i] = false;
    for(int i = 2;i < 1000000; i++)
      if(hash[i]) all_prime.push_back(i);
    }
    
    ll all_mu[max_range];
    ll N;
    ll G_mobius(ll cnt)
    {
            ll res= ( cnt%mod * (cnt-1)%mod)%mod;
               res= ( res%mod * (cnt-2)%mod * (cnt-3)%mod);
               res= (res%mod * power(24,mod-2)%mod);
               res= ((res%mod)+mod)%mod;
        return res;
    }
    int main(int argc, char const *argv[]){

          ios_base::sync_with_stdio(false);
          cin.tie(NULL);  
          ll t; cin>>t;
          while(t)
          {
          cin>>N;
          ll res = 0;
          for(int i = N; i >= 1; --i){
          	  all_mu[i] =G_mobius(N/i);
          	  for(int j = 2 * i; j <= N; j += i)
          	  	  all_mu[i] = (all_mu[i] - all_mu[j] + mod)%mod;
              res = ((res + (all_mu[i] * power(i,4))%mod)+mod)%mod;    
            }
          cout<<res<<endl;  
          t--;
          }
    }