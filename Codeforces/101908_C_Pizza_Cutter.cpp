// concept of inversion count

#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define PI 3.141592653589793238462643383279502884
#define FOR(x,n) for(int x=0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x=1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x=int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x=(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define mset(x,y) memset(&x, (y), sizeof(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll inv;
int arr[MAXN], aux[MAXN];

void mergesort(int l, int r) {
    if (l == r) return;
    int m = (l + r)/2;
    mergesort(l, m);
    mergesort(m+1, r);
    int i = l, j = m + 1, k = l;
    while(i <= m && j <= r) {
        if (arr[i] > arr[j]) {
            aux[k++] = arr[j++];
            inv += j - k;
        }
        else aux[k++] = arr[i++];
    }
    while(i <= m) aux[k++] = arr[i++];
    for(i = l; i < k; i++) arr[i] = aux[i];
}

ii a[MAXN];

void solve(int n) {
    FOR(i, n) scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a, a+n);
    FOR(i, n) arr[i] = a[i].se;
    mergesort(0, n-1);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int h, v;
    scanf("%d %d", &h, &v);
    inv = (h+1LL)*(v+1LL);
    solve(h);
    solve(v);
    printf("%lld\n", inv);
    return 0;
}

//[close]