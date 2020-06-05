#include <cmath>
#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int md = 1000000007;

vector <int> add(vector <int> a, vector <int> b) {
    int n = a.size();
    int m = b.size();
    int k = (n > m ? n : m);
    vector <int> c(k);
    for (int i = 0; i < k; i++)
        if (i >= n) c[i] = b[i]; else
        if (i >= m) c[i] = a[i];
        else c[i] = (a[i] + b[i]) % md;
    return c;
}

vector <int> mul(vector <int> a, int b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] = ((long long)a[i] * b) % md;
        if (a[i] < 0) a[i] += md;
    }
    return a;
}

vector <int> mul_x(vector <int> a, int bb) {
    vector <int> b(1, 0);
    b.insert(b.end(), a.begin(), a.end());
    vector <int> c = mul(a, -bb);
    return add(b, c);
}

int eval(vector <int> a, int x) {
    int ans = 0, y = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        ans = (ans + (long long)y * a[i]) % md;
        y = (long long)y * x % md;
    }
    return ans;
}

void normalize(vector <int> &a) {
  int n = a.size();
  vector <int> color(n + 3, 0);
  int last = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      continue;
    }
    if (color[a[i]] == 0) {
      color[a[i]] = ++last;
    }
    a[i] = color[a[i]];
  }
}

map < vector <int>, vector <int> > f[10][10];
map < vector <int>, vector <int> >::iterator it;
vector <int> result[10][10];

int main() {
    for (int rows = 1; rows <= 8; rows++) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j <= 8; j++) f[i][j].clear();
        vector <int> temp(rows, 0);
        f[0][0][temp] = vector <int>(1, 1);
        for (int col = 0; col < 8; col++) {
            for (int row = 0; row < rows; row++) {
                int n_col = col;
                int n_row = row;
                if (n_row + 1 < rows) {
                    n_row++;
                } else {
                    n_row = 0;
                    n_col++;
                }
                it = f[row][col].begin();
                while (it != f[row][col].end()) {
                    vector <int> state = (*it).first;
                    vector <int> poly = (*it).second;
                    int maxc = 0;
                    for (int i = 0; i < rows; i++)
                        if (state[i] > maxc) maxc = state[i];
                    for (int c = 1; c <= maxc; c++) {
                        if (c == state[row]) {
                            continue;
                        }
                        if (row > 0 && c == state[row - 1]) {
                            continue;
                        }
                        vector <int> new_state = state;
                        new_state[row] = c;
                        normalize(new_state);
                        f[n_row][n_col][new_state] = add(f[n_row][n_col][new_state], poly);
                    }
                    vector <int> new_state = state;
                    new_state[row] = maxc + 1;
                    normalize(new_state);
                    vector <int> new_poly = mul_x(poly, maxc);
                    f[n_row][n_col][new_state] = add(f[n_row][n_col][new_state], new_poly);
                    it++;
                }
            }
        }
        for (int cols = 1; cols <= 8; cols++) {
            result[rows][cols] = vector <int>();
            it = f[0][cols].begin();
            while (it != f[0][cols].end()) {
                vector <int> poly = (*it).second;
                result[rows][cols] = add(result[rows][cols], poly);
                it++;
            }
        }
    }
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", eval(result[n][m], k));
    }
    return 0;
}