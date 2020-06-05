#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) (v).size()
#define debug(x) cerr << #x << "_=_" << x << "\n";
#define sum(n) ((n)*((n)+1)>>1)
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
 
vvi tree;
vi dp;
 
int f(int u, int p=-1){
    for (int v : tree[u]){
        if(v==p) continue;
        dp[u] += f(v, u);
    }
    return dp[u] + 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        tree.assign(n+1, vi());
        dp.assign(n+1, 0);
        for (int i=0, u, v; i<n-1; i++){
            cin >> u >> v;
            tree[u].pb(v);
            tree[v].pb(u);
        }
 
        f(x);
        bool first=0;
        for (int v : tree[x])
            first ^= (dp[v]%2==0);
 
        if(first || tree[x].size() <= 1)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
 
        tree.clear();
        dp.clear();
    }
    return 0;
}

/*if I consider each heap as a nim heap the grundy number of each one will be 0 if it's even and 1 otherwise (this is because I'm only allowed to take 1 element each turn and 0 is a losing state) then I find the nim sum of the k-1 heaps, if the grundy number of the remain heap is 1 my nim sum change, otherwise nothing happen. So it is enough to find the nim sum of all of them. The special cases are handled seperately. This is equivalent to the approach of the editorial, but using Spargue-Grundy theorem

→ Reply
make the tree rooted from node x and calculate the amount of sons it has for each brach. Since for win the game I have to make the node x leaf, and for that need to eliminate all nodes of each branch first(all except one branch, I mean if there are k branchs, it is enough to eliminate k-1 of them) then the game is reduced to a modified nim game where the goal is reach the state {0 1} and for each turn the player can select one "heap" (amount of sons calculated previosly) and decrease it by 1.But I can't find a winning strategy for that game, please let me know if I am making some mistake..*/