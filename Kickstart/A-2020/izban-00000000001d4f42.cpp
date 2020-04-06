#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        int n, k, p;
        scanf("%d%d%d", &n, &k, &p);
        vector<vector<int>> a(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < k; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        vector<int> dp(p + 1, 0);
        for (int i = 0; i < n; i++) {
            vector<int> ndp = dp;
            for (int j = 0; j <= p; j++) {
                int cur = 0;
                for (int l = 0; l <= k && j + l <= p; l++) {
                    ndp[j + l] =max(ndp[j + l], dp[j] + cur);
                    if (l < k) {
                        cur += a[i][l];
                    }
                }
            }
            dp =ndp;
        }

        printf("Case #%d: %d\n", test, dp[p]);
    }

    return 0;
}
