#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int u, v;
    cin >> u >> v;
    int a = (u + v);
    cout << 1LL * (u + v) * (u + v + 1) / 2 + u + 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}