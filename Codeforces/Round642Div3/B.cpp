#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
#define all(x)  x.begin(),x.end()
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;

void solve(){
	ll N,K;
	cin>>N>>K;
	ll sum=0;
	vector<ll> a(N),b(N);
	for(ll i=0;i<N;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(ll i=0;i<N;i++)
		cin>>b[i];
	sort(all(a));
	//sort(all(b));
	sort(b.rbegin(),b.rend());
	if(K==0){
		cout<<sum<<'\n';
		return;
	}
	sum=0;
	for(ll i=0;i<N;i++){
		if(i>=K)
			sum+=a[i];
		else
			sum+=max(a[i],b[i]);
	}
	cout<<sum<<'\n';

}
int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}