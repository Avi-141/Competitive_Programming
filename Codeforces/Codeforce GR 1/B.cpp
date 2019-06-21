#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef pair<ll,long int> PIII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999

int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int n, m, k;

  cin >> n >> m >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {

    cin >> a[i];

  }

  vector<int> b;

  for (int i = 0; i < n - 1; i++) {

    b.push_back(a[i + 1] - a[i]-1);//(difference array)

  }

  sort(b.rbegin(), b.rend());

  int ans = a[n - 1] - a[0] + 1; // max length

  for (int i = n-2; i>n-k-1; i--) {

    ans -= b[i];

  }

  cout << ans << '\n';

  return 0;

}