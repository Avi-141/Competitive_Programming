/**
 *    author:  tourist
 *    created: 04.04.2020 21:51:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, b;
  cin >> t >> b;
  cerr << t << " " << b << '\n';
  while (t--) {
    auto Ask = [&](int x) {
      cout << x + 1 << endl;
      string foo;
      cin >> foo;
      return foo[0];
    };
    string s(b, '?');
    int L = 0, R = b;
    while (L < R) {
      int iter = 10;
      for (int i = 0; i < L; i++) {
        if (s[i] == s[b - 1 - i]) {
          --iter;
          if (Ask(i) != s[i]) {
            for (int j = 0; j < b; j++) {
              if (s[j] != '?') {
                s[j] ^= '0' ^ '1';
              }
            }
          }
          break;
        }
      }
      for (int i = 0; i < L; i++) {
        if (s[i] != s[b - 1 - i]) {
          --iter;
          if (Ask(i) != s[i]) {
            reverse(s.begin(), s.end());
          }
          break;
        }
      }
      while (iter >= 2 && L < R) {
        iter -= 2;
        s[L] = Ask(L);
        ++L;
        if (L < R) {
          --R;
          s[R] = Ask(R);
        }
      }
      if (iter > 0) {
        Ask(0);
      }
    }
    cout << s << endl;
    string foo;
    cin >> foo;
    if (foo == "N") {
      break;
    }
  }
  cerr << "done!" << '\n';
  return 0;
}
