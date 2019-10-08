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

bool piisort(pii a, pii b) {
  // a.first / a.second > b.first / b.second
  return a.first * (ll)b.second > a.second * (ll)b.first;
}



void solve() {
  int q, n;
  cin >> q >> n;
  vector<pii> v;
  while(n--) {
    int a, b;
    cin >> a >> b;
    v.emplace_back(a, b);
  }
  sort(v.begin(), v.end(), piisort);
  vector<ll> aPref, bPref;
  aPref.push_back(0);
  bPref.push_back(0);
  for(int i = 0; i < v.size(); i++) {
    aPref.push_back(aPref.back() + v[i].first);
    bPref.push_back(bPref.back() + v[v.size()-1-i].second);
  }
  while(q--) {
    int aWant, bWant;
    cin >> aWant >> bWant;
    int lhs = 0;
    int rhs = aPref.size()-1;
    while(lhs != rhs) {
      int mid = (lhs+rhs+1)/2;
      if(aPref[mid] < aWant) lhs = mid;
      else rhs = mid-1;
    }
    if(lhs == aPref.size()-1) {
      if(aPref[lhs] >= aWant && bPref[0] >= bWant) cout << "Y";
      else cout << "N";
    }
    else {
      int idx = lhs;
      double aCurr = aPref[idx];
      double bCurr = bPref[v.size()-1-idx];
      double aNeed = (aWant - aCurr) / v[idx].first;
      bCurr += (1-aNeed) * v[idx].second;
      if(bCurr + 1e-6 >= bWant) {
        cout << "Y";
      }
      else {
        cout << "N";
      }
    }
  }
  cout << "\n";
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
