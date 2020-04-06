#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

void solve() {
    int N, K; 
    int P; 
    cin >> N >> K;
    cin >> P;
    int dp[N+1][P+1]; 
    F0R(i, N+1) 
        F0R(j, P+1) 
            dp[i][j] = 0;
    int data[N][K]; 
    F0R(i, N) 
        F0R(j, K) 
            cin >> data[i][j];

    F0R(i, N) {
        F0R(j, P+1) {
            int sum = 0;
            F0R(k, K+1) {
                if (j+k > P)
                    break;
                dp[i+1][j+k] = max(dp[i+1][j+k], sum+dp[i][j]);
                if (k != K) 
                    sum += data[i][k];
            }
        }
    }

    /*F0R(i, N+1) {
        F0R(j, P+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[N][P] << endl;
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
 
/*First, let's consider an intermediate state dp[i][j] which denotes the maximum sum that can be obtained 
using the first i stacks when we need to pick j plates in total. 
Therefore, dp[N][P] would give us the maximum sum using the first N stacks if we need to pick P plates in total. 
In order to compute dp[][] efficiently, we need to be able to efficiently answer the question: 
What is the sum of the first x plates from stack i? We can precompute this once for all N stacks. 
Let sum[i][x] denote the sum of first x plates from stack i.
Next, we iterate over the stacks and try to answer the question: 
What is the maximum sum if we had to pick j plates in total using the i stacks we've seen so far? 
This would give us dp[i][j]. 
However, we need to also decide, among those j plates, how many come from the i-th stack? 
i.e., Let's say we pick x plates from the i-th stack, then dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x]). 
Therefore, in order to pick j plates in total from i stacks, 
we can pick anywhere between [0, 1, ..., j] plates from the i-th stack and [j, j-1, ..., 0] plates 
from the previous i-1 stacks respectively. Also, we need to do this for all values of 1 ≤ j ≤ P.

The flow would look like:
for i [1, N]:
 for j [0, P]:
  dp[i][j] := 0
   for x [0, min(j, K)]:
    dp[i][j] = max(dp[i][j], sum[i][x]+dp[i-1][j-x])
If we observe closely, this is similar to the 0-1 Knapsack Problem with some added complexity. 
To conclude, the overall time complexity would be O(N*P*K).*/