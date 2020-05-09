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
void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if(b==0) {
		if(a) {
			for(int i=0; i<=a; ++i)
				cout << 0;
			cout << "\n";
		} 
		else {
			for(int i=0; i<=c; ++i)
				cout << 1;
			cout << "\n";
		}
	} 
	else {
		for(int i=0; i<a; ++i)
			cout << 0;
		cout << "01";
		//fixed pattern
		--b;
		for(int i=0; i<c; ++i)
			cout << 1;
		int d=0;
		while(b) {
			cout << d;
			d^=1;
			//alt bits
			--b;
		}
		cout << "\n";
	}
}
int main() { 
fast_io;
 #ifndef ONLINE_JUDGE
 freopen("ip.txt", "r", stdin); 
 freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while(t--)
		solve();
}