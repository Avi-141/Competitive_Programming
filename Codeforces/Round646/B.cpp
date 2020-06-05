#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) (v).size()
#define debug(x) cerr << #x << "_=_" << x << "\n";
#define sum(n) ((n)*((n)+1)>>1)
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tt;
	cin >> tt;
	while(tt--){
		string str;
		cin >> str;
		int n=(int)str.size();
		
		int res=1<<29;
		for(int i=0;i<=n;i++){
			int v=0;
			for(int j=0;j<i;j++){
				if(str[j]=='1') v++;
			}
			for(int j=i;j<n;j++){
				if(str[j]=='0') v++;
			}
			
			res=min(res,v);
		}
		
		for(int i=0;i<=n;i++){
			int v=0;
			for(int j=0;j<i;j++){
				if(str[j]=='0') v++;
			}
			for(int j=i;j<n;j++){
				if(str[j]=='1') v++;
			}
			
			res=min(res,v);
		}
		
		cout << res << "\n";
	}
	return 0;
}s