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
 
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    int t, le, x;
    string str;
    cin >> t;
    while( t-- ){
        cin >> str;
        le = str.length();
        x = 0;
        for( char c : str ) 
        	if( c != '0' ) x++;
        cout << x << "\n";
        for( int i = 0; i < le; i++ ){
            if( str[i] != '0' ){
                cout << str[i];
                for( int j = i+1 ; j < le ; j++ ) cout << 0;
                cout << " ";
            }
        }
        cout << "\n";
    }
 
}