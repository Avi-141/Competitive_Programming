/**
 *    author:  tourist
 *    created: 04.04.2020 15:57:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    string s;
    cin >> s;
    int balance = 0;
    for (char c : s) {
      int d = (int) (c - '0');
      while (balance < d) {
        cout << '(';
        ++balance;
      }
      while (balance > d) {
        cout << ')';
        --balance;
      }
      cout << c;
    }
    while (balance > 0) {
      cout << ')';
      --balance;
    }
    cout << '\n';
  }
  return 0;
}
