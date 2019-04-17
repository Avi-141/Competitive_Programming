#include<bits/stdc++.h>

using namespace std;
multiset <long long> s, t;
int main () {
  int n, m, x;
  cin >> n >> m >> x;
  for(int i = 1; i <= n; i++) {
    long long v; cin >> v;
    s.insert(v);
  }
  for(int i = 1; i <= m; i++) {
    long long v; cin >> v;
    t.insert(v);
  }
  long long ans = *s.rbegin() - *s.begin() + *t.rbegin() - *t.begin();
  int i = 1;
  while(i <= 5e5 + + 10) {
    long n1, n2;
    n1 = *s.rbegin();
    n2 = *t.rbegin();
    s.erase(s.find(n1));
    t.erase(t.find(n2));
    n1 -= x; n2 -= x;
    s.insert(n1);
    t.insert(n2);
    long long temp = *s.rbegin() - *s.begin() + *t.rbegin() - *t.begin();
    ans = min(ans, temp);
    i++;
  }
  cout << ans << endl;
}
