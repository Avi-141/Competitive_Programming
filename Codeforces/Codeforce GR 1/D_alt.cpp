// NOT MY SOLUTION
// author:unknown

    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long LL;
    typedef long double LD;
    typedef pair < int, int > PII;
    typedef pair < LL, LL > PLL;
    typedef pair < LD, LD > PDD;
     
    #define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)(x).size()
    template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
    template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }
     
    #ifdef LOCAL
    #define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
    #else
    #define DBG(...) (__VA_ARGS__)
    #define cerr if(0) cout
    #endif
     
    // ********************** CODE ********************** //
     
    const int N = 1e6 + 7;
    const int C = 3;
    const int INF = 1e9;
     
    int n, m, T[N];
    int dp[N][C][C][C];
     
    int main()
    {
        _upgrade
        
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            T[x]++;
        }
     
        int cur = 0;
     
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < C; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    for(int l = 0; l < C; l++)
                    {
                        int tmp[] = {j, j + k, j + k + l, k + l, l};
                        bool ok = true;
                        for(int z = 0; z < 5; z++)
                        {
                            if((i - z <= 0 && tmp[z] > 0) || tmp[z] > T[i - z])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if(!ok)
                        {
                            dp[i][j][k][l] = -INF;
                            continue;
                        }
                        int cr = 0;
                        if(i - 2 > 0)
                            cr = T[i - 2];
                        dp[i][j][k][l] = j + (cr - j - k - l) / 3 + max({dp[i - 1][k][l][0], dp[i - 1][k][l][1], dp[i - 1][k][l][2]});
                        int cr2 = 0;
                        if(i - 1 > 0)
                            cr2 = T[i - 1];
                        cur = max(cur, dp[i][j][k][l] + (T[i] - j) / 3 + (cr2 - j - k) / 3);
                        //printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, dp[i][j][k][l]);
                    }
                }
            }
        }
     
        cout << cur << "\n";
     
    	return 0;
    }