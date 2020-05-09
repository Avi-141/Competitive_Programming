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
    freopen("ip.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

	int T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		ll take;
		k--;
		ll ans=0;
		for(int bit=30;bit>=0;--bit){
			take=(n-1)*(1<<bit);
			if(k>=take){
				k=k-take;
				ans+=n*(1<<bit);
			}
		}
		ans++;
		cout<<ans+k<<"\n";

	}
}