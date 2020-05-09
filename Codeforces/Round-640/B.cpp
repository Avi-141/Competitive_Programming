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
void solve() {
    int N, K; 
    cin>>N>>K;
 
    // does odd work?
    if ((K&1) == (N&1)) {
        if (K <= N) {
            cout<<"YES"<<"\n";
            cout<<(N - K + 1);
            for(int i=0;i<K-1;i++)
                cout<<" 1";
            cout<<"\n";
        } else {
            cout<<"NO";
        }
    return;
    }
 
    // does even work?
    if ((N % 2 == 0) && (N >= 2 * K)) 
    {
        cout<<"YES"<<"\n";
        cout<<N-2*K+2;
        for(int i=0;i<K-1;i++)
            cout<<" 2";
        cout<<"\n";
        return;
    }
    cout<<"NO\n";
}
 
int main() {

fast_io;
//#ifndef ONLINE_JUDGE
  //  freopen("ip.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
//#endif
    int T; 
    cin>>T;
    while(T--){
        solve();
    }
 
}