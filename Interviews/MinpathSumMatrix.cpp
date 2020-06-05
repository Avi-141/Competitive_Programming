  int minPathSum(vector<vector<int> > &grid) {
            if (grid.size() == 0) return 0;
            int m = grid.size(), n = grid[0].size();
            int minPath[m + 1][n + 1];
            for (int i = 0; i < m; i++) {
                minPath[i][0] = grid[i][0]; 
                if (i > 0) minPath[i][0] += minPath[i - 1][0];
                for (int j = 1; j < n; j++) {
                    minPath[i][j] = grid[i][j] + minPath[i][j-1];
                    if (i > 0) minPath[i][j] = min(minPath[i][j], grid[i][j] + minPath[i-1][j]);
                }
            }
            return minPath[m-1][n-1];
        }