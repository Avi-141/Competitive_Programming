#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
void MakePreSum(long long int  arr[], long long int  presum[], long long int  n,long long int i) 
{ 

    presum[i] = arr[i]; 
    for (long long int  j = i+1;j < n; j++) 
        presum[j] = presum[j - 1] + arr[j];
} 
long long int  BinaryLifting(long long int  presum[], long long int  n, long long int  x) 
{ 
    long long int  pos = 0;
    long long int  LOGN = log2(n); 
    int flag=0;
    for (long long int  i = LOGN; i >= 0; i--) { 
        if (pos + (1 << i) < n &&  presum[pos + (1 << i)] <=x) 
        { 
          flag=1;
          pos += (1 << i); 
        } 
    } 
if(flag=0)
  return -1;
else return pos;
} 
int  main() 
{ 

    long long int n,k;
    cin>>n>>k;
    long long int sum=0;
    long long int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    long long int  presum[n] = { 0 }; 
for(long long int i=0;i<n;i++)
{
    MakePreSum(arr, presum,n,i); 
    ll temp=BinaryLifting(presum, n, k); 
    ll sums=presum[temp];
    arr[((i+sums)%n)]=k^sums;
}
for(long long int i=0;i<n;i++)
  sum+=arr[i];
cout<<sum;
}
