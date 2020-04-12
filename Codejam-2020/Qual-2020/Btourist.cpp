/**
 *    author:  tourist
 *    created: 04.04.2020 16:16:05       
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    string color(n, ' ');
    bool fail = false;
    for (int i = 0; i < n; i++) {
      if (color[i] != ' ') {
        continue;
      }
      vector<int> que(1, i);
      color[i] = 'C';
      for (int bb = 0; bb < (int) que.size(); bb++) {
        for (int j = 0; j < n; j++) {
          if (j != que[bb] && max(a[j], a[que[bb]]) < min(b[j], b[que[bb]])) {
            if (color[j] == ' ') {
              color[j] = 'C' ^ 'J' ^ color[que[bb]];
              que.push_back(j);
            } else {
              if (color[j] == color[que[bb]]) {
                fail = true;
                break;
              }
            }
          }
        }
        if (fail) break;
      }
      if (fail) break;
    }
    cout << (fail ? "IMPOSSIBLE" : color) << '\n';
  }
  return 0;
}
