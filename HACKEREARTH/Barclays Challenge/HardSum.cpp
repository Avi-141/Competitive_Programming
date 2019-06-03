#include <bits/stdc++.h> 
using namespace std; 
const unsigned  long long int  MOD = 1000000007;

unsigned long long int  pairAndSum(vector<unsigned long long int> &vect, unsigned long long int  n) 
{ 
    unsigned long long int  ans = 0;
    for (unsigned long long int  i = 0; i < 32; i++)
   {
    unsigned long long int  k = 0;
    for (unsigned long long int  j = 0; j < n; j++)
        if ( !(vect[j] & (1 << i)) )
            k++;
    ans +=(((1<<i)%MOD) *((n*(n-1)/2)%MOD - (k*(k-1)/2)%MOD))%MOD;
    }
    return ans; 
}
int  main() 
{ 
    unsigned long long int  n,i; cin>>n;
    unsigned long long int arr[n];
    vector<unsigned long long int> vec(n);
    for(i=0;i<n;i++)
        vec[i]=i+1; 

    cout << (((2%MOD)*(pairAndSum(vec, n)%MOD))+(n*(n+1)/2)%MOD)%MOD << endl; 
    return 0; 
}