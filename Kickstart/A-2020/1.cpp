#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
 
 
int main(){
 
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
		ll n,b;
		cin>>n>>b;
		vector<ll> vec(n);
		for(ll i=0;i<n;i++)
			cin>>vec[i];
		sort(all(vec));
        ll count=0;
        ll flag=0;
		if(vec[0]>b)
			flag=1;
 
		for(ll i=0;i<n;i++){
			if(b<=0|| b<vec[i])
				break;
			b-=vec[i];
			count++;
		}
 
		if(flag==1){
			cout << "Case #" << i<< ": ";
			cout<<0<<"\n";
		}
		else if(flag==0){
			cout << "Case #" << i<< ": ";
			cout<<count<<"\n";
		}
 
	}
}