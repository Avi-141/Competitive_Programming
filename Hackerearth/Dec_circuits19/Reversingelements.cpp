#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Segtree_node {
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSubarraySum;
     
    Segtree_node() {
        maxPrefixSum = maxSuffixSum =maxSubarraySum = 0;
        totalSum = 0;
    }
};
     
Segtree_node merge(Segtree_node leftChild, Segtree_node rightChild) {
    Segtree_node parentnode;
    parentnode.maxPrefixSum = max(leftChild.maxPrefixSum,
                                      leftChild.totalSum +
                                      rightChild.maxPrefixSum);
     
    parentnode.maxSuffixSum = max(rightChild.maxSuffixSum,
                                      rightChild.totalSum +
                                      leftChild.maxSuffixSum);
     
    parentnode.totalSum = leftChild.totalSum +
                              rightChild.totalSum;
     
    parentnode.maxSubarraySum = max({leftChild.maxSubarraySum,
                                         rightChild.maxSubarraySum,
                                         leftChild.maxSuffixSum +
                                         rightChild.maxPrefixSum});
     
    return parentnode;
}
     
void build(Segtree_node *tree, ll arr[], ll start,ll end, ll index) {
     
        /* Leaf Segtree_node */
        if (start == end) {
     
            // single element is covered under this range
            tree[index].totalSum = arr[start];
            tree[index].maxSuffixSum = arr[start];
            tree[index].maxPrefixSum = arr[start];
            tree[index].maxSubarraySum = arr[start];
            return;
        }
     
        ll mid = (start + end) / 2;
        build(tree, arr, start, mid, 2 * index);
        build(tree, arr, mid + 1, end, 2 * index + 1);
     
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}
     
     
Segtree_node *buildTree(ll arr[], ll n) {
        // Allocate memory for segment tree
    auto x = (long long int) (ceil(log2(n))); // Height of the tree
     
        // Maximum size of segment tree
    ll max_size = 2 * (long long int) pow(2, x) - 1;
    Segtree_node *tree = new Segtree_node[max_size];
     
        // Fill the allocated memory tree
    build(tree, arr, 0, n - 1, 1);
     
        // Return the constructed segment tree
    return tree;
}
Segtree_node queryTree(Segtree_node *tree, ll ss, ll se, ll qs,ll qe, ll index) {
        // No overlap
    if (ss > qe || se < qs) {
     
            // returns a Segtree_node for out of bounds condition
        Segtree_node nullnode;
        return nullnode;
    }
     
        // Complete overlap
    if (ss >= qs && se <= qe) {
        return tree[index];
    }
     
        // Partial Overlap Merge results of Left
        // and Right subtrees
    ll mid = (ss + se) / 2;
    Segtree_node left = queryTree(tree, ss, mid, qs, qe,2 * index);
    Segtree_node right = queryTree(tree, mid + 1, se, qs,qe, 2 * index + 1);
     
        // merge left and right subtree query results
    Segtree_node res = merge(left, right);
    return res;
}
     
     
Segtree_node query(Segtree_node *tree, ll start, ll end, ll n) {
    Segtree_node res = queryTree(tree, 0, n - 1, start, end, 1);
    return res;
}
int main(){
        
    ll n, q;
    cin >> n >> q;
    ll arr[n], ma = -10000000;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        ma = max(ma, arr[i]);
    }
    Segtree_node *Tree = buildTree(arr, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        Segtree_node rev, str, end;
        rev = query(Tree, l - 1, r - 1, n);
        if (l > 1)
            str = query(Tree, 0, l - 2, n);
        if (r < n)
            end = query(Tree, r, n - 1, n);
        ll ans;
        ans = rev.maxSubarraySum;
        
        if (l > 1) {
            ans = max(ans, rev.maxSuffixSum + str.maxSuffixSum);
            ans = max(ans, str.maxSubarraySum);
        }
        if (r < n) {
            ans = max(ans, rev.maxPrefixSum + end.maxPrefixSum);
            ans = max(ans, end.maxSubarraySum);
        }
        if (r < n && l > 1)
            ans = max(ans, str.maxSuffixSum + rev.totalSum + end.maxPrefixSum);
        if (ma < 0)
            cout << ma << "\n";
        else
            cout << ans << "\n";
    }
}