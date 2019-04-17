#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
int mostFrequent(int arr[], int n) 
{ 
    sort(arr, arr + n); 
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
} 
  
int main()
{
 int t;
 cin>>t;
 int j;
 for(j=1;j<=t;j++)
 {
     int n,p;
     int sum=0,sum1=0,sum2=0;
     int count=0,flag=0;
     int flag2=0;
     cin>>n>>p;
     int arr[n];
     for (int i=0;i<n;i++)
     cin>>arr[i];
    int freq=maxFrequent(arr,n);
     sort(arr,arr+n);
     
/*int deviation=arr[1]-arr[0];*/
     for(int i=0;i<n-1;i++)
     {
     if(arr[i]==arr[i+1])count++;}
     
     if(n==p)
     {
     for(int i=0;i<n;i++)
     {
         arr[i]=arr[n-1]-arr[i];
         
     }
     for(int i=0;i<n;i++)
     {sum+=arr[i];}
      cout<<"Case #"<<j<<":"<<" ";
      if(count==n-1)
      cout<<0<<endl;
      else cout<<sum<<endl;
     }

    /*for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }*/
else{
    for(int i=0;i<n;i++)
    {
    if(count>1)
    {
     arr[i]=abs(res-arr[i]);
        flag=1;
    }
    }
    sort(arr,arr+n);
     if(flag==1)
     {
         flag2=1;
    for(int i=0;i<p;i++)
      {sum2+=arr[i];
          
      }}
    if(flag2==0)
{
    for(int i=0;i<p;i++)arr[i]=arr[p-1]-arr[i];
    for(int i=0;i<p;i++)
        sum1+=arr[i];
}
    cout<<"Case #"<<j<<":"<<" ";
    if(count==p-1)
      cout<<0<<endl;
    else if(flag2==1)
    cout<<sum2<<endl;
    else if(flag2==0)cout<<sum1<<endl;
}
}
}