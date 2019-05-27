#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll v[21 + 5];
ll sum[(1 << 21) + 5];
ll group_sum;
int n, k;

void compute_sums(int position, ll current_sum, int mask)
{
    if (position == -1)
    {
        sum[mask] = current_sum;
        return;
    }

    compute_sums(position - 1, current_sum, mask << 1);
    compute_sums(position - 1, current_sum + v[position], (mask << 1) + 1);
}

void solve_case()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    memset(sum, 0, sizeof(sum));
    compute_sums(n - 1, 0, 0);

    group_sum = sum[(1 << n) - 1];
    if (group_sum % k != 0)
    {
        cout << "no" << endl;
        return;
    }
    if (group_sum == 0)
    {
        if (n >= k)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        return;
    }

    group_sum /= k;

    vector<int> M(1 << n, 0);
    M[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        if (M[mask])
        {
            int current_group = sum[mask] / group_sum;
            for (int i = 0; i < n; ++i)
            {
                if ((mask >> i) & 1)
                    continue;
                if (sum[mask | (1 << i)] <= group_sum * (current_group + 1))
                    M[mask | (1 << i)] = 1;
            }
        }
    }
    if (M[(1 << n) - 1])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    int cases;
    cin >> cases;
    for (int z = 1; z <= cases; ++z)
        solve_case();
}


/*You can solve the problem in O(N * 2^N), so the K is meaningless for the complexity.

First let me warn you about the corner case N < K with all the numbers being zero, in which the answer is "no".

The idea of my algorithm is the following. Assume we have computed the sum of each of the masks (that can be done in O(2^N)).
 We know that for each of the groups, the sum should be the total sum divided by K.

We can do a DP with masks in which the state is just a binary mask telling which numbers have been used. 
The key idea in removing the K from the algorithm complexity is noticing that if we know which numbers have 
been used, we know the sum so far, so we also know which group we are filling now (current sum / group sum).
 Then just try to select the next number for the group: it will be valid if we do not exceed the group 
 expected sum.*/