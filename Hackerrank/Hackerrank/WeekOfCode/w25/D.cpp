#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vi64 v;
map<i64, int> w;

int win(i64 x) {
    if (w.count(x)) return w[x];
    w[x] = 0;
    for (auto y: v) {
        if (x % y) continue;
        w[x] |= y % 2 == 0 || !win(x / y);
    }
    return w[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
 #endif

    i64 x;
    cin >> x;
    int n;
    cin >> n;
    v.resize(n);
    forn(i, n) cin >> v[i];
    cout << (win(x) ? "First" : "Second") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
//https://www.spoj.com/problems/DAGCNT2/
//https://github.com/pin3da/Programming-contest/blob/master/solved/hackerrank/Week%20of%20Code%2025/DAG%20Queries/brute_force.cc
//http://solutionforhackerrank.blogspot.com/2018/03/happy-ladybugs.html