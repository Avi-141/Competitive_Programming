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

static void solve_case(int cas);

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
    cin >> cases;
    for (int cas = 1; cas <= cases; cas++)
        solve_case(cas);
    return 0;
}

/*** END OF TEMPLATE CODE ***/

struct item
{
    int rank;
    int rep;
};

void compact(vector<item> &deck)
{
    vector<item> out;
    for (const item &it : deck)
    {
        if (out.empty() || out.back().rank != it.rank)
            out.push_back(it);
        else
            out.back().rep += it.rep;
    }
    deck = move(out);
}

static void apply(vector<item> &deck, vector<pii> &moves, int p, int q)
{
    assert(p < q);
    int a = 0, b = 0;
    for (int i = 0; i < p; i++)
        a += deck[i].rep;
    for (int i = p; i < q; i++)
        b += deck[i].rep;
    moves.emplace_back(a, b);
    rotate(deck.begin(), deck.begin() + p, deck.begin() + q);
    compact(deck);
}

static void solve_case(int cas)
{
    int R, S;
    cin >> R >> S;
    vector<item> deck;
    for (int i = 0; i < S; i++)
        for (int j = 0; j < R; j++)
            deck.push_back(item{j + 1, 1});

    vector<pii> moves;
    while (true)
    {
        int r0 = deck[0].rank;
        int r1 = deck[1].rank;
        int cut = -1;
        for (int i = 2; i + 1 < SZ(deck); i++)
        {
            if (deck[i].rank == r0 && deck[i + 1].rank == r1)
            {
                cut = i + 1;
                break;
            }
        }
        if (cut == -1)
            break;
        apply(deck, moves, 2, cut);
    }
    if (SZ(deck) > R)
        apply(deck, moves, 1, SZ(deck) - 1);

    cout << "Case #" << cas << ": " << SZ(moves) << "\n";
    for (const auto &m : moves)
        cout << m.first << ' ' << m.second << endl;
}
