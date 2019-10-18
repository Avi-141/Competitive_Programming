#include<bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())
#define mp make_pair
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define f first 
#define s second
#define MOD (1000 * 1000 * 1000 + 7)
#define good_time() ios_base::sync_with_stdio(false)
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
#define dd double
#define ll long long 
#define ull unsigned long long 
#define bigint int64_t
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        unordered_map<string, pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            string str;
            int x;
            cin >> str;
            cin >> x;
            m.insert({str,make_pair(0,0)});
            auto it = m.find(str);
            if(it == m.end())
                m.insert({str,make_pair(0,0)});
            if(x)
                    it->second.second++;
                else 
                    it->second.first++;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            if(it->second.second > it->second.first)
                ans += it->second.second;
            else
                ans += it->second.first;
        }
        cout << ans << "\n";
}
}