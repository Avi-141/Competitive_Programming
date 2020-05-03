//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void solve_case(int cas, ll A, ll B);

int main(int argc, char * const *argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    struct rlimit stack_limit;
    getrlimit(RLIMIT_STACK, &stack_limit);
    stack_limit.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    if (argc >= 2)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }
    if (argc >= 3)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
    cin.exceptions(ios::failbit | ios::badbit);

    int cases;
    ll A, B;
    cin >> cases >> A >> B;
    for (int cas = 1; cas <= cases; cas++)
        solve_case(cas, A, B);
    return 0;
}

/*** END OF TEMPLATE CODE ***/

static constexpr ll LOWER = -1000000000;
static constexpr ll UPPER = 1000000000;

class center : public exception
{
};

static bool query(ll x, ll y)
{
    cout << x << ' ' << y << endl;
    string result;
    cin >> result;
    if (result[0] == 'C')
        throw center();
    else
        return result[0] == 'H';
}

static ll binsearch(const array<ll, 2> &xy, int axis, ll miss)
{
    ll hit = xy[axis];
    array<ll, 2> q = xy;
    while (llabs(hit - miss) > 1)
    {
        ll mid = (hit + miss) / 2;
        q[axis] = mid;
        if (query(q[0], q[1]))
            hit = mid;
        else
            miss = mid;
    }
    return hit;
}

static void adjust(array<ll, 2> &xy, int axis)
{
    ll lower = binsearch(xy, axis, LOWER - 1);
    ll upper = binsearch(xy, axis, UPPER + 1);
    xy[axis] = (lower + upper) / 2;
}

static void solve_case(int cas, ll A, ll B)
{
    try
    {
        constexpr ll STEP = 300000000;
        ll x, y;
        for (x = LOWER + STEP - 1; x <= UPPER; x += STEP)
            for (y = LOWER + STEP - 1; y <= UPPER; y += STEP)
            {
                if (query(x, y))
                    goto found;
            }
        assert(false);

found:
        array<ll, 2> xy = {x, y};
        adjust(xy, 0);
        adjust(xy, 1);
        query(xy[0], xy[1]);
        assert(false);
    }
    catch (center &e)
    {
    }
}
