#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

mt19937 gen;
uniform_int_distribution<int> dist(-1e9,1e9);
int main() {
    int t,T,A,B;
    cin >> T >> A >> B;
    for (t = 1; t <= T; t++) {
        int x,y,done = 0;
        string s;
        while (1) {
            x = dist(gen),y = dist(gen);
            cout << x << " " << y << endl;
            cin >> s;
            if (s == "CENTER") {
                done = 1;
                break;
            }
            else if (s == "HIT") break;
        }
        if (done) continue;
        int l = -1e9,r = x;
        while (l < r) {
            int m = l+(r-l)/2;
            cout << m << " " << y << endl;
            cin >> s;
            if (s == "CENTER") {
                done = 1;
                break;
            }
            if (s == "HIT") r = m;
            else l = m+1;
        }
        if (done) continue;
        int ll = l;
        l = x,r = 1e9;
        while (l < r) {
            int m = l+(r-l+1)/2;
            cout << m << " " << y << endl;
            cin >> s;
            if (s == "CENTER") {
                done = 1;
                break;
            }
            if (s == "HIT") l = m;
            else r = m-1;
        }
        if (done) continue;
        int rr = r;
        int cx = (ll+rr)/2;
        l = -1e9,r = y;
        while (l < r) {
            int m = l+(r-l)/2;
            cout << x << " " << m << endl;
            cin >> s;
            if (s == "CENTER") {
                done = 1;
                break;
            }
            if (s == "HIT") r = m;
            else l = m+1;
        }
        if (done) continue;
        ll = l;
        l = y,r = 1e9;
        while (l < r) {
            int m = l+(r-l+1)/2;
            cout << x << " " << m << endl;
            cin >> s;
            if (s == "CENTER") {
                done = 1;
                break;
            }
            if (s == "HIT") l = m;
            else r = m-1;
        }
        if (done) continue;
        rr = r;
        int cy = (ll+rr) / 2;
        cout << cx << " " << cy << endl;
        cin >> s;
        assert(s == "CENTER");
    }

    return 0;
}
/*First of all, if we find a point in the circle, 
we can find the boundary point of the same line or the same column with this point in 4 dichotomies, 
that is, find the two "strings" of the circle. The "string" here is not a string in a strict sense, 
but it has similar properties. 
For example, two "strings" can be used to determine the center of the circle, 
which is borrowed here for convenience.

Suppose a point in the circle is (x, y)
, The boundary points of the peers are (x, y1) and (x, y2), 
the boundary points of the same column are (x1, y) and (x2, y), then the center of the circle is (x1 + x2/2, y1 + y2/2)

.

Now we only need to solve the problem of finding a point in the circle.
 There are two methods, one is to directly take points at random, 
 it is easy to get the probability that the point falls within the circle is π/16
 So the desired number of random points is not large. 
 There is also a search at intervals of D = 10^9/4, 
 which can be easily obtained by the method of reproof (i ∗ D, j ∗ D), i, j∈ [−3,3]

At least one of the points falls within the circle.

Thus, the problem is solved.


/*Since the area of the dartboard makes up a significant percentage of the wall area (at least π / 16), 
we could do this by throwing darts at random until we hit one point 
(the probability of hitting could be slightly less than π / 16 
because we consider only points with integer nanometer coordinates, 
but the difference is negligible). This has an overwhelmingly high chance of hitting in 100 throws 
or fewer for all cases. 
However, there is a deterministic way that also works, which is to divide the wall into squares of side A. 
If the center of the dartboard is inside a square, 
it is guaranteed that at least one of the corners of that square is inside the dartboard. 
Therefore, we can simply try all those corners (there are only 25, and it is even possible to restrict it further), 
and we will find a hit point. /*/