#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define MOD 1000000007
vector<long long int> vec(1000002);
vector<long long int> maxsum(1000002);

 int main()
 {
 vec.push_back(0);
        vec.push_back(1);
        for (int i = 2; i < vec.size(); i++)
            vec[i] = (vec[i - 1]%MOD + (i - 1)%MOD + (vec[i - 1]%MOD * (i-1)%MOD)%MOD)%MOD;
        for (int i = 2; i < 1000002; i++)
            maxsum[i] += vec[i - 1];
  lli t;
  cin>>t;
  while(t--)
  {
    lli n;
    cin>>n;
    lli res=1;
    if(n!=1)
    	res=maxsum[n+2];
    cout<<res<<endl;
}
}