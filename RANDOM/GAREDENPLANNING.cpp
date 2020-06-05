#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

const int N = 128;
const int M =  10;

int n, m, dot[N], meh[N];

void input()
{
    cin >> n >> m;
    rep(i, n) {
        string tmp;
        cin >> tmp;
        rep(j, m) {
            dot[i] |= (tmp[j] == '.') << j;
            meh[i] |= (tmp[j] == '?') << j;
        }
    }
}

#define ulong uint64_t

bool merge(const ulong cur, const int vacant, ulong& ret)
{
    static int root[M];
    {
        int t = 0;
        rep(i, m) {
            if (vacant >> i & 1) {
                root[i] = t;
            } else {
                root[i] = m;
                t = i + 1;
            }
        }
    }

    int acc = 0;
    static int merged[M], leftmost[M], correct[M];
    fill_n(merged, m, 0);
    fill_n(leftmost, m, m);
    copy_n(root, m, correct);
    correct[m] = m;
    rep(i, m) {
        const int s = cur >> 4 * i & 15;
        acc |= 1 << s;
        if (s != m and root[i] != m) {
            if (merged[root[i]] >> s & 1) return false;
            merged[root[i]] |= 1 << s;
            leftmost[s] = min(leftmost[s], root[i]);
            correct[root[i]] = min(correct[root[i]], leftmost[s]);
        }
    }

    ulong fixed = cur >> 32;
    rep(i, m) if (acc >> i & 1) {
        fixed += leftmost[i] == m;
        if (fixed > 1) return false;
    }
    ret = fixed << 32;
    rep(i, m) {
        ret |= correct[root[i]] << 4 * i;
    }
    return true;
}

const int mod = 1000000007;

void solve()
{
    using state = unordered_map<ulong, int>;
    state cur;
    /* initial state */ {
        ulong t = 0;
        rep(_, m) t <<= 4, t |= m;
        cur[t] = 1;
    }
    rep(i, n) {
        state suc;
        for (const auto& p : cur) {
            for (int s = meh[i]; ; s = (s - 1) & meh[i]) {
                ulong t;
                if (merge(p.first, s | dot[i], t)) {
                    suc[t] += p.second;
                    if (suc[t] >= mod) suc[t] -= mod;
                }
                if (s == 0) break;
            }
        }
        cur = move(suc);
    }
    long ans = 0;
    for (const auto& p : cur) {
        int acc = 0;
        rep(i, m) {
            acc |= 1 << (p.first >> 4 * i & 15);
        }
        const int comps = (p.first >> 32) + __builtin_popcount(acc & ((1 << m) - 1));
        if (comps <= 1) ans += p.second;
    }
    cout << ans % mod << endl;
}

int main()
{
    input();
    solve();
}
