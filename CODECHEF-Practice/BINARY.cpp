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

    
using namespace std;
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    while(T--){
        int N, Z; cin >> N >> Z;
        
        bool A[N] = {};
        vector<int> vec;  
        //keep track of moves after which a zero is behind 1
        // taki uske baad switch kar sake 
        // refer to https://aleigorithms.wordpress.com/2019/05/
        // geometrical imagination 
        // havent still been able to get the devecue implementation
        // this solution is partially accepted

        int Zero = 0, front_idx = 0;        
        for(int x = 0; x < N; x++)
        {
            int i;
            cin >> i;

            
            if((vec.size() - front_idx) > 0 and vec[front_idx] >= Z)
             front_idx++;
            
            if(!i)
            {
                Zero++;

                if(!vec.empty() and Zero + (vec.size() - front_idx) > Z)
                 front_idx++;

                if(Zero >= Z) vec.clear(), front_idx = 0;;
            }
            else
            {
                Zero = min(Z, Zero);

                while(Zero--)
                    vec.push_back(Zero);

                A[x - (vec.size() - front_idx)] = 1;
                
                if(!vec.empty()) vec.back()++;

                for(int k = vec.size() - 2; k >= front_idx; k--)\
                {
                    if(vec[k] <= vec[k + 1])
                     vec[k] = vec[k + 1] + 1;
                    else vec[k]++;
                }
            
                
                Zero = 0;
            }

                     
        }

        for(auto &x : A)
            cout << x << " ";
        cout << "\n";

        vec.clear();
    }


return 0;
}

