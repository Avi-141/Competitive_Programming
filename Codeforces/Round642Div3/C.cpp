#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;


int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
	fast_io
	int T;
	cin>>T;
	while(T--){
		ll N;
		cin>>N;
		ll ans=(N-1)*N*(N+1);
		cout<<ans/3<<'\n';
	}
}