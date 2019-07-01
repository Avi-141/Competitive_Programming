#include<bits/stdc++.h>
#define ll long long 

#define bint int64_t
#define pb push_back
#define ld long double
using namespace std;
typedef vector<ll> VI;

ll binarySearch(vector<ld> arr,ld x) 
{ 
    return (upper_bound(arr.begin(),arr.end(),x)-arr.begin());
}


void fillPrefixSum(vector<ld> &arr, ll n, vector<ld> prefixSum) 
{ 
   
   
    prefixSum[0]=(arr[0]); 
  
    
    for (ll i = 1; i < n; i++) 
    {
        prefixSum[i]=(prefixSum[i-1] + arr[i]); 
       //.. cout<<prefixSum[i]<<" ";
       // cout<<arr[i]<<" ";
    }

} 

int main()
{

  ll n,m;
  cin>>n>>m;
  ld sum=0;
  vector<ld> vec(n),store(n);
  for(ll i=0;i<n;i++)
  {
    cin>>vec[i];
    vec[i]=log10(vec[i]);
   // cout<<vec[i]<<" ";
   sum+=vec[i];
  }
  vector<ld> arr(n);
  for(int i=1;i<=m;i++)
  {
    ll type,pos,val,newsum=0;
    ll ans=0;

    cin>>type;
    if(type==2)
    {
     fillPrefixSum(vec,n,arr);
     ans=binarySearch(arr,sum/2);
     cout<<ans<<"\n";

    }
    else if(type==1)
    {
      cin>>pos>>val;
      vec[pos-1]=vec[pos-1]*val;
      for(ll i=0;i<n;i++)
      {
        //cout<<vec[i]<<" ";
        sum+=vec[i];
        //sum=ull(sum);
      }
        
        cout<<"\n";
    
    }
  }
}




