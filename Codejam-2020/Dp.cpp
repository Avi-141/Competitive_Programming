#include <bits/stdc++.h>
#define endl '\n'
#define modulo 1000000007
#define int long long
#pragma GCC optimize("-O2")
using namespace std;

//a(i) and cost by b(i)
//no two adjacent elements of a(i) same
min cost

int DP[101][102],n,arr[101],arr2[101];
int Recursion(int idx,int b)
{
    if(idx>=n)
        return 0;
    if(DP[idx][b+1]+1)
        return DP[idx][b+1];
    DP[idx][b+1]=INT_MAX;
    for(int i=arr[idx]; i<101; i++)
    {
        if(i==b)
            continue;
        DP[idx][b+1]=min(DP[idx][b+1],Recursion(idx+1,i)+arr2[idx]*(i-arr[idx]));
    }
    return(DP[idx][b+1]);
}
int32_t main()
{
   iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>arr2[i];
    }
    for(int i=0; i<101; i++)
    {
        for(int z=0; z<101; z++)
            DP[i][z]=-1;
    }
    cout<<Recursion(0,-1);
    return 0;
}
