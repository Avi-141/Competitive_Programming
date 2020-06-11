#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

   int a[50][50];
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> one(n + m + 2), zer(n + m + 2);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                if (n + m - 2 - i - j == i + j) 
                	continue;
                int k = min(i + j, n + m - 2 - i - j);
                if (a[i][j])
                    ++one[k];
                else
                    ++zer[k];
            }
        int ans = 0;
        for (int i = 0; i <= n + m; ++i)
            ans += min(zer[i], one[i]);
        cout << ans << '\n';
    }
}
/*
int n, m;
int a[N], b[N];
 
void solve (){
    cin >> n >> m;
    int A = n + m - 1;
    for (int i = 1; i <= n+m; i ++)
        a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        int x;
        cin >> x;
        if (x == 0)
            a[i+j-1]++;
        else
            b[i+j-1]++;
    }
    int ans = 0;
    for (int i = 1; i*2 < A+1; i++)
        ans += min (a[i] + a[A - i + 1], b[i] + b[A + 1 - i]);
    cout << ans << endl;
}
//https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/discuss/446306/C%2B%2B-Bit-vector-%2B-Regular-BFS*/