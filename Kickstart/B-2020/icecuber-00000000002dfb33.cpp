#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 3e5;
double fac[nax], pow2[nax];

int main() {
  fac[0] = pow2[0] = 0;
  for (int i = 1; i < nax; i++) {
    fac[i] = fac[i-1]+log(i);
    pow2[i] = pow2[i-1]+log(2);
  }


  auto prob = [&](int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0.;
    return exp(fac[n]-fac[k]-fac[n-k]-pow2[n]);
  };


  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int cc = 1;
  while (t--) {
    cout << "Case #" << cc++ << ": ";
    int w, h, x0, y0, x1, y1;
    cin >> w >> h >> x0 >> y0 >> x1 >> y1;
    x0--, y0--;

    auto f = [&](int x, int y) {
      double ret = prob(x+y, x);
      if (x == w-1) for (int i = w; i <= x+y; i++) ret += prob(x+y, i);
      if (y == h-1) for (int i = h; i <= x+y; i++) ret += prob(x+y, i);
      return ret;
    };
    double ans = 1.;
    for (int i = y0; i < y1; i++)
      if (x0)
	ans -= f(x0-1, i)*(i < h-1 ? 0.5 : 1);
    for (int i = x0; i < x1; i++)
      if (y0)
	ans -= f(i, y0-1)*(i < w-1 ? 0.5 : 1);
    if (x0 == 0 && y0 == 0) ans = 0;
    cout << setprecision(20) << ans << endl;
  }
}
