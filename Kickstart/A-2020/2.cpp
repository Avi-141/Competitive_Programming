#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;
const int K = 35;

int n, k, p;
int a[N][K];
int cache[N][N * K];

int dp(int idx, int taken)
{
	if(taken == 0)
		return 0;
	if(taken < 0)
		return -2e9;
	if(idx > n)
		return 0;
	int &ans = cache[idx][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int val = 0;
	for(int i = 0; i <= k; i++)
	{
		val += a[idx][i];
		ans = max(ans, val + dp(idx + 1, taken - i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0; 
	while(t--)
	{
		memset(cache, -1, sizeof(cache));
		tc++;
		cin >> n >> k >> p;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= k; j++)
				cin >> a[i][j];
		int ans = dp(1, p);
		cout << "Case #" << tc << ": " << ans << endl;
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