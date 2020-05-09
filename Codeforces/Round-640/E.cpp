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


ll solve(){

	int N;
	cin>>N;
	vector<ll> A(N);
	for(int i=0;i<N;i++)
		cin>>A[i];

	vector<ll> pref(N+1,0);
	for(int i=0 ; i<N ; i++){
		pref[i+1]=pref[i]+A[i];
	}
	vector<bool> ans(N+1,false);
	for(int i=0; i<N ;i++){
		for(int j=i+2;j<=N && pref[j]-pref[i]<=N; j++){
			ans[pref[j]-pref[i]]=true;
		}
	}

	int ans1=0;
	for(auto a : A)
		ans1+=ans[a];
	return ans1;
}

 
int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
     freopen("ip.txt", "r", stdin); freopen("output.txt", "w", stdout);
   #endif
 
    int tests;
    cin >> tests;
 
    while (tests--)
        cout<<solve()<<'\n';
}
