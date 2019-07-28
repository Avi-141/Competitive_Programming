#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
bool isSorted(vector<ll> ar, ll size) {

    ll previous_value=ar[0];

    for(ll i=1;i<=size;i++)
    {
       if (ar[i] < previous_value)
             return false;
       previous_value= ar[i];

     }
     return true;
}
int main()
{
	ll games;
	cin>>games;
	test:
	while(games--){
		
     ll n;
     cin>>n;
     vector<ll> arr(n);
     ll max=INT_MIN;
     ll idx=0;
     ll countmax=0;
     for(ll i=0;i<n;i++){
     	cin>>arr[i];
     	if(arr[i]>max)
    	 {
     		max=arr[i];
     		idx=i;
     		countmax++;
    		 }
     }

     if(idx==0)
     {
     	cout<<"BOB"<<"\n";
     	goto test;
     }
     else if(idx==1)
     {
     	cout<<"ANDY"<<"\n";
     	goto test;
     }
     else if(isSorted(arr,n-1))
     {
     	if(n%2==0)
     	{
     		cout<<"ANDY"<<"\n";
     		goto test;
     	}
     	else if(n%2==1)
     	{
     		cout<<"BOB"<<"\n";
     		goto test;
     	}
     }
     else
     {
     	if(countmax%2==0)
     	cout<<"ANDY"<<"\n";
     	else 
     		cout<<"BOB"<<"\n";

     }
 }
}