#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,d;
cin>>n>>d;
int arr[n];
int ans
	for(int i=0;i<n;i++)
	cin>>arr[i];
	sort(arr,arr+n);
int num = 0;
   ans=-1;
        for(ll i=0;i<n;i++)
        {
            maxdiff=1;
            for(ll j=i+1;j<n;j++)
            {
                if(a[j]-a[i]<=d)
                maxdiff++;
                else break;
            }
            if(maxdiff>ans)
            ans=maxdiff;
        }
        cout<<n-ans<<endl;
    }