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


int main() {
    int t,T,X,Y;
    scanf("%d",&T);
    for (t = 1; t <= T; t++) {
        scanf("%d %d",&X,&Y);

        if (!((X+Y) & 1)) printf("Case #%d: IMPOSSIBLE\n",t);
        else {
            string ans;
            while ((X != 0) || (Y != 0)) {
                if (abs(X)+abs(Y) == 1) {
                    if ((X == 0) && (Y == 1)) ans += 'N',Y = 0;
                    else if ((X == 0) && (Y == -1)) ans += 'S',Y = 0;
                    else if ((Y == 0) && (X == 1)) ans += 'E',X = 0;
                    else ans += 'W',X = 0;
                    break;
                }
                if (X & 1) {
                    int y = Y/2,x = (X+1)/2;
                    if ((x+y) & 1) ans += 'W',Y = y,X = x;
                    else ans += 'E',Y = y,X = (X-1)/2;
                }
                else {
                    int y = (Y+1)/2,x = X/2;
                    if ((x+y) & 1) ans += 'S',Y = y,X = x;
                    else ans += 'N',Y = (Y-1)/2,X = x;
                }
            }
            printf("Case #%d: %s\n",t,ans.c_str());
        }
    }

    return 0;
}

