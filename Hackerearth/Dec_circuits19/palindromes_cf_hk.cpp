#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 300010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

struct palindromic_tree {
public:
  int slen, nodes, last; // slen = total length of string
  char str[MAXN];
  int len[MAXN], link[MAXN], next[MAXN][26], cnt[MAXN]; // cnt = count of the node
  vi adj[MAXN];
 
  palindromic_tree () {
    str[0] = -1;
    slen = 1;
    link[0] = 1;
    len[1] = -1;
    nodes = 2;
  }
 
  inline int getLink (int x) {
    while (str[slen - len[x] - 2] != str[slen - 1]) x = link[x];
    return x;
  }
 
  inline void insert (char ch) {
    ch -= 'a';
    str[slen++] = ch;
    last = getLink(last);
    if (!next[last][ch]) {
      len[nodes] = len[last] + 2;
      link[nodes] = next[getLink(link[last])][ch];  // link with the next char added previously to the end
      next[last][ch] = nodes;
      nodes++;
    }
    last = next[last][ch];
  }
} tree;

ll ans;
string s;

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (size_t i=0; i<s.size(); i++) {
      tree.insert(s[i]);
      tree.cnt[tree.last]++;
  }
  for (int i=tree.nodes - 1; i>1; i--) tree.cnt[tree.link[i]] += tree.cnt[i];
  for (int i=2; i<tree.nodes; i++) ans = max(ans, 1LL * tree.len[i] * tree.cnt[i]);
  cout << ans << "\n";
  return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */