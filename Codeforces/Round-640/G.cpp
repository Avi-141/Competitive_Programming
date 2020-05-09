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


vector<ll> ret;
void solve(){

	ll n;
	int flag=0;
	cin>>n;
	ret.clear();
	if(n<4){
		ret.push_back(-1);
		flag=1;
		//cout<<-1<<"\n";
		//return ret;
	}
	if(flag)
		return;
	//ret.clear();
	/*for(int i=2;i<=n+1;i+=2)
		ret.push_back(i);
	if(n&1){
		ret.push_back(n-4);
		ret.push_back(n);
		ret.push_back(n-2);
	}*/
	for(int i=0;i+4<=n;i+=4){
		ret.push_back(i+2);
		ret.push_back(i+4);
		ret.push_back(i+1);
		ret.push_back(i+3);
	}
	if(n%4==1){
		ret.push_back(n);
	}
	else if(n%4==2){
		int temp=ret.back();
		ret.pop_back();
		ret.push_back(n-1);
		ret.push_back(temp);
		ret.push_back(n);
	}
	else if(n%4==3){
		int temp=ret.back();
		ret.pop_back();
        ret.push_back(n - 2);
        ret.push_back(n);
        ret.push_back(temp);
        ret.push_back(n - 1);
	}
	//return ret;
}


int main(){
 fast_io;
 #ifndef ONLINE_JUDGE
 freopen("ip.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		solve();
		for(int i=0;i<ret.size();i++){
			cout<<ret[i]<<" ";
		}
		cout<<'\n';
	}
}