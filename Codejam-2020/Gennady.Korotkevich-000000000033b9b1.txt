/**
 *    author:  tourist
 *    created: 16.05.2020 16:57:57       
**/
#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 2.01e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    long long L, R;
    cin >> L >> R;
    long long x = 1;
    while (true) {
      if (L - R >= x) {
        long long low = x;
        long long high = inf;
        while (low < high) {
          long long mid = (low + high + 1) >> 1;
          long long sum = (mid - x + 1) * (x + mid) / 2;
          if (L - sum >= R) {
            low = mid;
          } else {
            high = mid - 1;
          }
        }
        long long mid = low;
        long long sum = (mid - x + 1) * (x + mid) / 2;
        L -= sum;
        x = mid + 1;
        continue;
      }
      if (R - L >= x) {
        long long low = x;
        long long high = inf;
        while (low < high) {
          long long mid = (low + high + 1) >> 1;
          long long sum = (mid - x + 1) * (x + mid) / 2;
          if (R - sum >= L) {
            low = mid;
          } else {
            high = mid - 1;
          }
        }
        long long mid = low;
        long long sum = (mid - x + 1) * (x + mid) / 2;
        R -= sum;
        x = mid + 1;
        continue;
      }
      if (L == R) {
        if (L < x) {
          break;
        }
        L -= x;
        x += 1;
        continue;
      }
      bool flag = false;
      if (L < R) {
        swap(L, R);
        flag = true;
      }
      auto Sum = [&](long long first, long long last) -> long long {
        if (first > last) {
          return 0;
        }
        assert(first % 2 == last % 2);
        long long cnt = (last - first) / 2 + 1;
        return first * cnt + cnt * (cnt - 1);
      };
      long long low = x - 1;
      long long high = inf;
      while (low <= high) {
        long long mid = (low + high + 1) >> 1;
        long long fromL = 0;
        long long fromR = 0;
        { // L
          long long first = x;
          long long last = mid;
          if (first % 2 != last % 2) {
            last -= 1;
          }
          fromL = Sum(first, last);
        }
        { // R
          long long first = x + 1;
          long long last = mid;
          if (first % 2 != last % 2) {
            last -= 1;
          }
          fromR = Sum(first, last);
        }
        if (low == high) {
          assert(L >= fromL && R >= fromR);
          L -= fromL;
          R -= fromR;
          x = low + 1;
          break;
        }
        if (L >= fromL && R >= fromR) {
          low = mid;
        } else {
          high = mid - 1;
        }
      }
      if (flag) {
        swap(L, R);
      }
      break;
    }
    cout << x - 1 << " " << L << " " << R << '\n';
  }
  return 0;
}
