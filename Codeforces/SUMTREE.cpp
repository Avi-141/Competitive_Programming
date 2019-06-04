#include <bits/stdc++.h>
using namespace std;

// #include <chrono>
// using namespace std::chrono;
// auto clockStart = high_resolution_clock::now();
// auto timer() {return duration_cast<milliseconds>(high_resolution_clock::now() - clockStart);}

#define endl '\n'

#define s(x)        scanf("%d",&x)
#define s2(x,y)     scanf("%d %d",&x,&y)
#define sd(x)       scanf("%lf",&x)

#define fr(i,s)     for(int i=0;i<(s);i++)
#define frl(i,s)    for(long long i=0;i<(s);i++)
#define sarr(x,s)   for(int i=0;i<(s);i++) scanf("%d",&x[i])

#define pb(x)       push_back(x)
#define ppb()       pop_back()
#define pf(x)       push_front(x)
#define ppf()       pop_front()
#define mp(x, y)    make_pair(x, y)
#define ff          first
#define ss          second

#define gcd(x, y)   __gcd(x, y)
#define isPow2(x)   ((x) && !((x) & ((x) - 1)))

#ifndef ONLINE_JUDGE  //debugging
#define debug(x) cout<<(#x)<<" = "<<(x)<<endl
void test() {cout<<"meaow"<<endl;}
template <class T1> void test(T1 e) {cout<<"meaow\t"<<e<<endl;}
template <class T1,class T2> void test(T1 e1,T2 e2) {cout<<"meaow\t"<<e1<<"\t"<<e2<<endl;}
template <class T1,class T2,class T3> void test(T1 e1,T2 e2,T3 e3) {cout<<"meaow\t"<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template <class T1,class T2,class T3,class T4> void test(T1 e1,T2 e2,T3 e3,T4 e4) {cout<<"meaow\t"<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<endl;}
template <class T1,class T2,class T3,class T4,class T5> void test(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5) {cout<<"meaow\t"<<e1<<"\t"<<e2<<"\t"<<e3<<"\t"<<e4<<"\t"<<e5<<endl;}
#define parr(x,s) for(int i=0;i<(s);i++) {cout<<x[i]<<"\t";} cout<<endl //tab separated
#else
#define debug(x)
void test() {}
template <class T1> void test(T1 e) {}
template <class T1,class T2> void test(T1 e1,T2 e2) {}
template <class T1,class T2,class T3> void test(T1 e1,T2 e2,T3 e3) {}
template <class T1,class T2,class T3,class T4> void test(T1 e1,T2 e2,T3 e3,T4 e4) {}
template <class T1,class T2,class T3,class T4,class T5> void test(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5) {}
#define parr(x, s)
#endif

const int MAX = (int) 1e5 + 9;
const int MOD = (int) 1e9 + 7;
const double pi = acos(-1.0);
const int inf = std :: numeric_limits <int> :: max() - 1;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

vector <int> tree[MAX];
int par[MAX];
ll cum[MAX];
bool nuke = false;

ll findSum(int start, int prev)
{
    ll sum = cum[start] - cum[prev];
    if (sum < 0) nuke = true;
    for (int i: tree[start]) sum += findSum(i, start);
    return sum;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        tree[temp].push_back(i);
        par[i] = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", cum + i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (cum[i] == -1)
        {
            ll mini = inf;
            for (int j: tree[i]) mini = min(cum[j], mini);
            // if (cum[i] - cum[par[i]] < 0) ans = false;
            if (tree[i].empty()) mini = cum[par[i]];
            cum[i] = mini;
        }
    }

    ll ansVal = findSum(1, 0);
    if (nuke) cout << -1 << endl;
    else cout << ansVal << endl;
    
    return 0;
}
