#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int N=31;
vector<ll> pre(N);
void solve(){
	pre[1]=2;
	for(int i=2;i<31;i++){
		pre[i]=pre[i-1]*2+2;
	}
}

int main(){
	solve();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll idx=n/2;
		cout<<pre[idx]<<"\n";
		//cout<<((1LL<<(n/2)+1))-2<<"\n";
	}
}