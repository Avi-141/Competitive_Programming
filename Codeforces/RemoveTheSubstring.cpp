#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> Z;
const int nax = 2e5+10;
int a[nax], b[nax];
string S, T;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
      cin >> S >> T;
        int Tlen=T.length();
        int Slen=S.length();
      int ans = 0;
      int j = 0;
      for (int i = 0; i < T.size(); i++) {
        while (S[j] != T[i]) j++;
        a[i] = j++;
      }
      ans = max(ans, (int)S.size()-j);
      j = (int)S.size()-1;
      for (int i = (int)T.size()-1; i >= 0; i--) {
        while (S[j] != T[i]) j--;
        b[i] = j--;
      }
      ans = max(ans, j+1);
      for (int i = 0; i+1 < T.size(); i++) {
        ans = max(ans, b[i+1]-a[i]-1);
      }
     cout << ans << endl;
}