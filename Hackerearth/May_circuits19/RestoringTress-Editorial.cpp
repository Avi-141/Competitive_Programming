#include<bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, st[N], fn[N], rev[N], P[N];
void Solve(int v)
{
    int nw = st[v] + 1;
    int u = rev[nw];
    for (; nw < fn[v]; nw = fn[u], u = rev[nw])
        P[u] = v, Solve(u);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &st[i]), rev[st[i]] = i;
    for (int i = 1; i <= n; i++)
        scanf("%d", &fn[i]);
    Solve(rev[0]);
    for (int i = 1; i <= n; i++)
        printf("%d ", P[i]);
    printf("\n");
    return (0);
}