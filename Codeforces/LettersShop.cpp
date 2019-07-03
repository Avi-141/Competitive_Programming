#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
const int MOD = 1000000007;
const int MX = 200005;
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd; 
 
string pref;
int foreachinput[26];
int counts[MX][26];

     
int main() {   
        
        const int A = 26;
        vector<int> v[A]; 

        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        string s;
        ll n;
        cin >> n >> s;
     
        FOR(i,0,n)
        {
            v[s[i] - 'a'].push_back(i);
        }
     
        int m;
        cin >> m;
     
        int ct[A];
     
        while (m--) 
        {
            string test;
            cin >> test;
     
            fill(ct, ct + A, 0);
            for (char c : test)
                ct[c - 'a']++; // freq array
            int ans = 0;
    
            for (int i = 0; i < A; i++) 
            {
                if (ct[i] > 0) 
                {
                    ans = max(ans, v[i][ct[i]-1]);
                }
            }
     
            cout << ans + 1 << "\n";
        }
     
        return 0;
    } 