#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 40; //check the limits, dummy


/*int64_t Comb(int a, int b) {
  #define COMB__MAXA 1000
  #define COMB__MAXB 1000
  if (b > a || b < 0) return 0;
  if (!a) return 1;
  static int64_t combmemo[COMB__MAXA+1][COMB__MAXB+1];
  int64_t &ret = combmemo[a][b];
  if (!ret) ret = Comb(a-1, b-1)+Comb(a-1,b);
  return ret;
}

int main() {
  int T, N, prob=1;
  for (cin >> T; T--;) {
    cin >> N;
    cout << "Case #" << prob++ << ":" << endl;
    if (N <= 500) {
      for (int i = 1; i <= N; i++) cout << i << " 1" << endl;
    } else {
      int64_t cur = 2, r = 1, k = 0, kd = 1;
      vector<int64_t> opt, optr, optk, retr{0, 1}, retk{0, 0};
      for (;;) {
        optr.push_back(r);
        optk.push_back(k + (kd ? 1 : -1));
        opt.push_back(Comb(optr.back(), optk.back()));
        r++;
        k += kd;
        kd = !kd;
        if (cur + Comb(r, k) > N) break;
        cur += Comb(r, k);
        retr.push_back(r);
        retk.push_back(k);
      }
      for (int i = opt.size()-1; i >= 0; i--) if (cur+opt[i] <= N) {
        cur += opt[i];
        retr.insert(retr.begin()+i+1, optr[i]);
        retk.insert(retk.begin()+i+1, optk[i]);
      }
      //int64_t tot = 0;
      //for (int i = 0; i < retr.size(); i++) tot += Comb(retr[i], retk[i]);
      //cout << tot << endl;
      for (int i = 0; i < retr.size(); i++) cout << retr[i]+1 << ' ' << retk[i]+1 << endl;
    }
  }
}*/

/*Start with the path going SW, SE, SW, SE, SW, SE, ... until you're just about to exceed N. 
Now, you can also easily add the numbers to the E, W, E, W of your choices to the path 
(the ones fitting into the crooks of the diagonal path). You now have a set of "optional" numbers 1, 1, 3, 4, 10, 15, 35, 56, ... 
(these are a path of knight's moves down Pascal's Triangle). 
Now you can probably fill in the rest of N by picking the correct set of these optional numbers — 
ie, you could solve the rest as a knapsack problem. 
But here's the surprise: the first 2k of these numbers always sums to exactly 1 less than the (2k+1)th number. 
So these numbers are just close enough for knapsack to work, and furthermore you can just solve it greedily, 
always choosing the largest value less than the remaining count!

These generated paths end up very short, using fewer than 64 steps for any N <= 10^9 (well below the limit of 500).*/

void solve() {
    cout << nl;
    ll N; cin >> N;
    ll oN = N;
    if (N < 32) {
        F0R(i, N) {
            cout << i+1 << " " << i+1 << nl;
        }
        return;
    }
    N -= 32;
    bool full[32];
    F0Rd(i, 32) {
        if (N >= (1ll << i) - 1) {
            N -= (1ll << i) - 1;
            full[i] = true;
        } else full[i] = false;
    }

    bool hi = false;
    ll sum = 0;
    F0R(i, 32) {
        if (!full[i]) {
            if (hi) {
                cout << i+1 << " " << i+1 << nl;
                sum += 1;
            } else {

                cout << i+1 << " " << 1 << nl;
                sum += 1;
            }
        } else {
            F0R(j, i+1) {
                if (hi) {
                    cout << i+1 << " " << i+1-j << nl;
                } else cout << i+1 << " " << j+1 << nl;
            }
            sum += (1ll << i);
            hi = !hi;
        }
    }


    F0R(i, N) {
        if (hi) {
            cout << 33+i << " " << 33+i << nl;
        } else {
            cout << 33+i << " " << 1 << nl;
        }
        sum++;
    }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);    
  
    int T; cin >> T;
    FOR(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
  return 0;
}