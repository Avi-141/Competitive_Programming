    #include <bits/stdc++.h>
     
    using namespace std;
    using ull = unsigned long long;
     
    const int NMAX = 1001;
     
    int n, m;
    ull answer, prevVal;
    char mat[NMAX][NMAX];
    int up[NMAX][NMAX], down[NMAX][NMAX];
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
     
        cin >> n >> m;
     
        int center1 ,center2 , center3 ;
        for(int i = 0; i < n; ++i)
            cin >> mat[i];
     
     
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                up[i][j] = 1;
                if (i - 1 >= 0 && mat[i - 1][j] == mat[i][j])
                    up[i][j] += up[i - 1][j];
            }
        }
     
     
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j < m; ++j)
            {
                down[i][j] = 1;
     
                if(i + 1 <= n - 1 && mat[i + 1][j] == mat[i][j])
                    down[i][j] += down[i + 1][j];
            }
     
        for (int i = 0; i < n - 1; ++i )
        {
     
            for (int j = 0; j < m;)
            {
                center1 = up[i][j];
                if (i - center1 >= 0)
                    center2 = up[ i - center1 ][j];
                else {
                    ++j;
                    continue;
                }
                center3 = down[i + 1][j];
                if (center1 > center2 || center1 > center3)
                {
                    ++j;
                    continue;
                }
                if(mat[i + 1][j] == mat[i][j] || mat[i][j] == mat[i - center1][j])
                {
                    ++j;
                    continue;
                }
                ++j;
                ++answer;
                prevVal = 1;
                while(j < m &&  mat[i][j] == mat[i][j - 1] && up[i][j] >= center1 &&
                      mat[i - center1][j] == mat[i - center1][j - 1] && up[i-center1][j] >= center1 &&
                      mat[i + 1][j] == mat[i + 1][j - 1]  && center1 <= down[i + 1][j])
                {
                    ++prevVal;
                    ++j;
                    answer += prevVal;
                }
            }
        }
     
        cout << answer << '\n';
        return 0;
    }