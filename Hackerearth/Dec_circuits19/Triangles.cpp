#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll N=1e6+5;
const ll M=1e9+7;

int dp[N],res[N],combi[N];

int main(){
   
   //dp[1]=1,res[1]=1;
   dp[1]=5;
   for(int i=2;i<N;i++){
    //cout<<i<<"\n";
    //cout<<"Before"<<" "<<dp[i-1]<<" ";
   	dp[i]=dp[i-1]*3+2;
   	//cout<<"New"<<" "<<dp[i]<<" ";
   	dp[i]=dp[i]%M;
    //combi[i]=dp[i-1];
    //cout<<"\n";
    //cout<<"Prev res"<<" "<<res[i-1];
    //res[i]=res[i-1]+dp[i]+combi[i];
    //cout<<"New res"<<" "<<res[i]<<" ";
    //res[i]%=M;
    //cout<<"\n";
   }
   int t;
   cin>>t;
   while(t--){
   	  ll n;
   	  cin>>n;
   	  cout<<dp[n]<<"\n";
   }
}