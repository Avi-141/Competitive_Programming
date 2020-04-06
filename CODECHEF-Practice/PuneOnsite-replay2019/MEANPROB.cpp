#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N=1e5;
int main(){
	
     int t;
     cin>>t;
     while(t--){
     	int n;
     	cin>>n;
     	int arr[N];
     	int sum=0;
     	for(int i=0;i<n;i++){
     		cin>>arr[i];
     		sum+=arr[i];
     	}
     	arr[n]=sum/n;
     	for(int i=n+1;i<N;i++){
     		sum+=arr[i-1];
     		sum-=arr[i-n-1];
     		arr[i]=sum/n;
     	}

     	int q;
     	cin>>q;
     	for(int i=0;i<q;i++){
     		ll x;
     		cin>>x;
     		if(x>=N)
     			cout<<arr[N-1]<<"\n";
     		else 
     			cout<<arr[x-1]<<"\n";
     	}
     }

}