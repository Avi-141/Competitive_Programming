#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long arr[100000000]
 long int i,n,T,count;

 cin>>T;
 while(T--)
 {
  cin>>n;
    for(i=0;i<n;i++)
    {cin>>arr[i];
    }
    sort(arr,arr+n)
    for(i=0;i<n;i++)
     {
      if(arr[i]==arr[i+1])
       count++;
       }
      }
      cout<<count<<endl;
      }
     }

