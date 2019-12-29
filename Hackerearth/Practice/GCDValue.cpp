#include<bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
 
const int maxi=1e6+10;
int n,k;
string s;
vector<int> v[maxi];
int a[maxi];
 
int mxor(int x)
{
 
    if (!v[x].size()) return 0;
 
 
     for (int w=18;w>=0;w--)
    {
         sort(v[x].begin(),v[x].end());
         reverse(v[x].begin(), v[x].end());
 
         for (int i = 1 ;i<v[x].size();i++)
           if (v[x][0]^v[x][i]>v[x][i])
           {
               v[x][i] ^= v[x][0];
           }
 
    }
 
 
    sort(v[x].begin(),v[x].end());
    reverse(v[x].begin(), v[x].end());
 
    return v[x][0];
}
 
int main()
{
 
     cin>>n>>k;
 
     for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
 
     for (int i=1;i<=n;i++)
     {
         for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0)
         {
             v[j].pb(a[i]^k);
             if (j*j!=a[i]) v[a[i]/j].pb(a[i]^k);
         }
     }
 
    long long ans =0 ;
    for (int i=1;i<=100000;i++)
    {
         ans =max (ans, 1ll*i*mxor(i));
    }
 
    cout<<ans<<endl;
    return 0;
}