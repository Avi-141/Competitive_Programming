#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999


// as soon as the max element comes to the front of the dequee
// for n-1 times , there will be a fixed pattern that will repeat 
// so apply operations till max arrives at the front 

// then the pattern is bases on idx and %n-1 


int main()
{
    ll  n, q;
    cin >> n >> q;
    deque<ll > dq;
    vector<ll> a(n);
    vector<ll> queries(q);
    vector<PII> answers;
    for(ll  i = 0; i < n; i++)
    {
        cin >> a[i];
        dq.push_back(a[i]);
    }
    for(ll  i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    ll  max_ele = *max_element(all(a));
    ll  steps = 0;

    while(dq.front() != max_ele)
    {
        ll  A = dq.front();
        dq.pop_front();
        ll  B = dq.front();
        dq.pop_front();
        answers.pb({A, B});
        // pair banake rakho
        if (A > B)
        {
            dq.push_front(A);
            dq.push_back(B);
        } 
        else 
        {
            dq.push_back(A);
            dq.push_front(B);
        }
        steps++; //to keep track of what to print at query q
    }
    dq.pop_front();
    ll  c = 0;
    while(dq.size()!=0)
    {
        a[c++] = dq.front();
        dq.pop_front();
    }
    for(ll  i = 0; i < q; i++)
    {
        if (queries[i] - 1 < steps)
        {
            cout << answers[queries[i] - 1].first << " " << answers[queries[i] - 1].second << endl;
        } 
        else 
        {
            long long idx = queries[i] - steps - 1;
            idx %= (n - 1);
            cout << max_ele << " " << a[idx] << endl;
        }
    }
    return 0;
}