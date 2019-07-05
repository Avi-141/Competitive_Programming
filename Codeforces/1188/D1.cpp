#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main() {
 
    ll  n;
    cin>>n;
    vector<ll > graph(n+5);
    ll  u, v;
    for (ll  i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        graph[u]++;
        graph[v]++;
    }
    bool check = false;
    for (ll  i = 1; i<=n; i++) 
        if (graph[i]==2) 
            check = true;
    if (check) cout<<"NO";
    else cout<<"YES";
}