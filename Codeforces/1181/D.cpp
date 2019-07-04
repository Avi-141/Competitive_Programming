    #include<bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std ;
   // template <typename T>;
  //  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    #define rep(i,a,b) for(int i=a; i<=b; i++)
    #define per(i,b,a) for(int i=b; i>=a; i--)
    #define sz(v) (int)v.size()
    #define len(s) (int)s.length()
    #define all(v) v.begin(), v.end()
    #define pb push_back
    #define fi first
    #define se second
    typedef pair<int, int> pi ;
    typedef vector<pair<int,int> > vpi ;
    typedef vector<int> vi ;
    typedef long long ll ;
    typedef double db ;
    typedef long double ldb ;
    const int mod = 1e9 + 7;
    const int cmod = 998244353 ;
    const int inf = 1e9 + 5;
    const db cpi = 3.14159265358 ;
    ll powmod(ll a, ll b) { ll ret = 1 ; while(b) { if(b&1) ret = (ret*a)%mod ;  a = (a*a)%mod ; b >>= 1 ; }  return ret ; }
    const int maxn = 5e5 + 5;
    int n, m, q ;
    ll a[maxn] ;
    ll loc[maxn] ;
    ll cnt[maxn] ;
    ll miss[maxn] ;
    int main()
    {
        ios::sync_with_stdio(false) ;
        cin.tie(NULL) ;
        cin >> n >> m >> q ;
        rep(i,0,n-1)
        {
            cin >> a[i] ;
            loc[i] = m*cnt[a[i]] + a[i] ;
            cnt[a[i]]++ ;
        }
        sort(loc, loc + n) ;
        rep(i,0,n-1)
        {
            if(i == 0)
            {
                ll x = loc[i] - 1 ;
                miss[i] = x ;
            }
            else
            {
                ll x = loc[i] - loc[i-1] - 1 ;
                miss[i] = x ;
            }
        }
        rep(i,1,n-1)
        {
            miss[i] += miss[i-1] ;
        }
        while(q--)
        {
            ll year ;
            cin >> year ;
            year -= n ;
            int x = lower_bound(miss, miss + n, year) - miss ;
            ll p ;
            if(x) p = loc[x-1] ;
            else p = 0 ;
            ll ans ;
            if(x)
                ans = (p + year - miss[x-1])%m ;
            else
                ans = (p + year)%m ;
            if(ans == 0) ans = m ;
            cout << ans << "\n" ;
        }
        return 0 ;
    }