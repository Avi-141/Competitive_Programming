#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


vector<pair<int, int>> build_sequence(int n, int k, int side) {
    dbg(n, k, side);

    if (n == 0)
        return {};

    if (n == 1) {
        assert(k == 0);
        return {{0, 0}};
    }

    assert(k + 1 <= n && n < 1 << (k + 1));
    vector<pair<int, int>> sequence;

    if (n <= 1 << k) {
        sequence = build_sequence(n - 1, k - 1, side);
        sequence.emplace_back(k, side == 0 ? 0 : k);
        return sequence;
    }

    if (n <= (1 << k) + k) {
        sequence = build_sequence(n - k - 1, k - 1, side);

        if (side == 0) {
            sequence.emplace_back(k, 1);
            sequence.emplace_back(k, 0);
        } else {
            sequence.emplace_back(k, k - 1);
            sequence.emplace_back(k, k);
        }

        return sequence;
    }

    sequence = build_sequence(n - (1 << k), k - 1, 1 - side);

    if (side == 0) {
        for (int i = k; i >= 0; i--)
            sequence.emplace_back(k, i);
    } else {
        for (int i = 0; i <= k; i++)
            sequence.emplace_back(k, i);
    }

    return sequence;
}

void run_case() {
    int n;
    cin >> n;
    int k = 31 - __builtin_clz(n);
    vector<pair<int, int>> sequence = build_sequence(n, k, 0);

    for (pair<int, int> &p : sequence)
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        cout << "Case #" << tc << ":\n";
        run_case();
        cout << flush;
    }
}
