#include <bits/stdc++.h>
using namespace std;
#define cin(x) cin>>x
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector< pair <int,int> > vii;


const int N = 55;
 
int a[N][N];
int T, n, m, cnt;
 
int main() {
	cin(T);
	while (T--) {
		cin(n); cin(m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cin(a[i][j]);
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			bool ok = 1;
			for (int j = 1; j <= m; j++) {
				if (a[i][j]) {
					ok = 0;
					break;
				}
			}
			now += ok;
		}
		cnt = now;
		now = 0;
		for (int i = 1; i <= m; i++) {
			bool ok = 1;
			for (int j = 1; j <= n; j++) {
				if (a[j][i]) {
					ok = 0;
					break;
				}
			}
			now += ok;
		}
		cnt = min(cnt, now);
		if (cnt & 1) printf("Ashish\n");
		else printf("Vivek\n");
	}
    return 0;
}