#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    
    for (int n, m; cin >> n >> m; ) {
        vector<int> a(512);
        a[0] = 1;
        const int M = 1000000007;
        for (int i = 0, x; i < n && cin >> x; ++i) {
            vector<int> b(512);
            while (x >= 0) {
                for (int y = 0; y < 512; ++y) {
                    (b[x ^ y] += a[y]) %= M;
                }
                --x;
            }
            a.swap(b);
        }
        for (int i = 0; i <= m; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}