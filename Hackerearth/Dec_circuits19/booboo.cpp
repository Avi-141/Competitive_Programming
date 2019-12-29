#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int search(ll curr,vector<ll> q,ll n,ll m){
	ll days=1;
	ll acc=0;
	for(ll i=0;i<n;i++){
		if(acc+q[i]>curr){
			days++;
			acc=q[i];
		}
		else acc+=q[i];
	}
   if(days<=m)
   	return 1;
   return -1;
}



int main(){

	ll n,m;
	cin>>n>>m;
	vector<ll> q(n);
	int maxx=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>q[i];
		if(maxx<q[i])
			maxx=q[i];
	}

	int temp=maxx; ll sum=0;
	for(int i=0;i<n;i++)sum+=q[i];

	ll lo=0,hi=sum,mid;
    while(lo<hi){
    	mid=lo+(hi-lo)/2;
    	if(search(mid,q,n,m)==1)
    		hi=mid;
    	else if(search(mid,q,n,m)==-1)
    		lo=mid+1;
    }
    cout<<lo<<"\n";
}