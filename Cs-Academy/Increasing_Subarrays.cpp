#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL m, ans = 0;
int a[1000000];

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    REP(i, n) scanf("%d", a + i);
    int j = 0, mx = 0;
    LL sum = 0;
    REP(i, n) {
        while (j < n && sum + mx - a[j] <= m) {
            if (a[j] > mx) {
                mx = a[j];
            } else {
                sum += mx - a[j];
            }
            ++j;
        }
        ans += j - i;
        if (j <= i + 1) {
            j = i + 1;
            sum = 0;
            mx = 0;
        } else {
            int lmx = 0;
            bool ok = false;
            for (int k = i + 1; k < j; ++k) {
                if (a[k] >= a[i]) {
                    ok = true;
                    break;
                }
                if (a[k] > lmx) {
                    lmx = a[k];
                } else {
                    sum += lmx - a[k];
                }
                sum -= a[i] - a[k];
            }
            if (!ok) {
                mx = lmx;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
