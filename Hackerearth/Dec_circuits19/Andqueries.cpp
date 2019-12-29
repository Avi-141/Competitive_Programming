
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
typedef struct {
    int left;
    int right;
    int sum;
} treeNode;
 
const int BIT = 8;
const ll MOD = 1000000007ll;
const int LIM = 1 << BIT;
const int MAX_NODES = 15000000;
 
int n;
treeNode nodes[MAX_NODES];
 
int next_node_id = 0;
int init_child() {
    nodes[next_node_id].left = -1;
    nodes[next_node_id].right = -1;
    nodes[next_node_id].sum = 0;
    return next_node_id++;
}

int updateRange(int id, int segmentStart, int segmentEnd, int queryStart, int queryEnd) {
    if (queryStart <= segmentStart && queryEnd >= segmentEnd) {
        return nodes[id].sum;
    }
 
    if (segmentEnd < queryStart || segmentStart > queryEnd)
        return 0;
 
    int ans = 0;
    int mid = (segmentStart + segmentEnd) / 2;
 
    if (nodes[id].left != -1) {
        ans += updateRange(nodes[id].left, segmentStart, mid, queryStart, queryEnd);
    }
    if (nodes[id].right != -1) {
        ans += updateRange(nodes[id].right, mid+1, segmentEnd, queryStart, queryEnd);
    }
 
    return ans;
}
 
ll powmod(ll base, ll exp) {
    ll ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
    }
    return ans;
}
 
 
void updateValue(int id, int segmentStart, int segmentEnd, int setIndex) {
    if (setIndex < segmentStart || setIndex > segmentEnd) {
        return;
    }
 
    nodes[id].sum += 1;
 
    if (segmentStart == segmentEnd) {
        return;
    }
 
    int mid = (segmentStart + segmentEnd) / 2;
    if (setIndex <= mid) {
        if (nodes[id].left == -1) nodes[id].left = init_child();
        updateValue(nodes[id].left, segmentStart, mid, setIndex);
    } else {
        if (nodes[id].right == -1) nodes[id].right = init_child();
        updateValue(nodes[id].right, mid+1, segmentEnd, setIndex);
    }
}
 
void setValue(int id, int segmentIndex) {
    updateValue(id, 0, n-1, segmentIndex);
}
 
int getRange(int id, int queryStart, int queryEnd) {
    return updateRange(id, 0, n-1, queryStart, queryEnd);
}
 
int main() {
    for (int i = 0; i < LIM; ++i) {
        init_child();
    }
 
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < LIM; ++j) {
            if ((a & j) == j) {
                setValue(j, i);
            }
        }
    }
 
    int m;
    cin >> m;
 
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
 
        ll ans = 0;
        for (int j = 0; j < LIM; ++j) {
            if ((j & x) == x) {
                int in_range = getRange(j, l, r);
                ll triples = powmod(in_range, 3);
                if ((__builtin_popcount(x) & 1) == (__builtin_popcount(j) & 1)) {
                    ans += triples;
                    while (ans >= MOD) {
                        ans -= MOD;
                    }
                } else {
                    ans -= triples;
                    while (ans < 0) {
                        ans += MOD;
                    }
                }
            }
        }
 
        cout << ans << '\n';
    }
 
    return 0;
}
