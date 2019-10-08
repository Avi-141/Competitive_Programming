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

void genDivs(vector<int> v, int lhs, int rhs, vector<int>& allDivs) {
  assert(v.size() == allDivs.size());
  for(int i = 0; i < allDivs.size(); i++) allDivs[i] = 1;
  for(int i = 2; i * i <= rhs; i++) {
    int x = (lhs/i) * i;
    while(x <= rhs) {
      if(x >= lhs) {
        int add = 1;
        while(v[x-lhs] % i == 0) {
          add++;
          v[x-lhs] /= i;
        }
        allDivs[x-lhs] *= add;
      }
      x += i;
    }
  }
  for(int i = 0; i < v.size(); i++) {
    if(v[i] > 1) allDivs[i] *= 2;
  }
}

void solve() {
  int lhs, rhs;
  cin >> lhs >> rhs;
  vector<int> v;
  vector<int> allDivs;
  for(int i = lhs; i <= rhs; i++) {
    v.push_back(i);
  }
  allDivs.resize(v.size());
  genDivs(v, lhs, rhs, allDivs);
  for(int i = 0; i < v.size(); i++) {
    while(v[i]%2 == 0) v[i] /= 2;
  }
  vector<int> evenDivs;
  evenDivs.resize(v.size());
  genDivs(v, lhs, rhs, evenDivs);
  int ret = 0;
  for(int i = 0; i < evenDivs.size(); i++) {
    int odd = evenDivs[i];
    int even = allDivs[i] - evenDivs[i];
    // cerr << i << ": " << even << " " << odd << endl;
    if(abs(even - odd) <= 2) ret++;
  }
  cout << ret << "\n";
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
