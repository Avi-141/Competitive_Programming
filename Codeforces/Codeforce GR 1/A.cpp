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

  int b, k;

  cin >> b >> k;

  vector<int> a(k);

  for (int i = 0; i < k; i++) {

    cin >> a[i];

  }

  int p = 1, s = 0;

  for (int i = k - 1; i >= 0; i--) 
  {

    s = (s + p * a[i]) % 2;

    p = p * b % 2;

  }

  cout << (s ? "odd" : "even") << '\n';

  return 0;

}

