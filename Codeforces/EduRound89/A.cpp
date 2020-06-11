#include <bits/stdc++.h>
using namespace std;
 
 #define ll long long 


int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

	int T;
	cin>>T;
	while(T--){
		ll a,b;
		cin>>a>>b;
		if(a==0||b==0){
			cout<<0<<"\n";
			continue;
		}
		ll maxx=(a>b)?a:b;
		ll minn=(a<b)?a:b;
		if(maxx>2*minn){
			cout<<minn<<"\n";
			continue;
		}
		else cout<<(a+b)/3<<"\n";
	}
}