#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      int d = pow(2, n);
      // 1/4 5/16 11/32 3/8 1/2 .....these are the locations of the folds on the paper.
      //what i noticed was..
      //16/32 8/32 12/32 10/32 11/32 
      //fibonacci average of numerators.
      //
      vector<int> v(25); 
      v[0] = d / 2;
      v[1] = d / 4;
      for (int i = 2; i < n; ++i) 
         v[i] = (v[i - 1] + v[i - 2]) / 2;
      cout << v[n - 1] << ' ' << d << ' ';
   }
   return 0;
}