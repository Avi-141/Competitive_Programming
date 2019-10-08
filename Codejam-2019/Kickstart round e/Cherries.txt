#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

// NO SAD

int par[100005];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  par[x] = y;
  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    par[i] = i;
  }
  ll mst = 2*(n-1);
  while(m--) {
    int a, b;
    cin >> a >> b;
    if(merge(a, b)) {
      mst--;
    }
  }
  cout << mst << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int casenum = 1; casenum <= t; casenum++) {
    cout << "Case #" << casenum << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  casesolve();
  // solve();
}
