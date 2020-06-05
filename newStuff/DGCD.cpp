#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
 
using namespace std;
 
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
 
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
 
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
 
// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define whole(a)                    a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
 
// Some common useful functions
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)
#define DREP(a)			    sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)		    (lower_bound(all(arr),ind)-arr.begin())
 
using namespace std;
 
#if DEBUG && !ONLINE_JUDGE
 
    #define debug(args...)     (Debugger()) , args
 
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
 
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std:cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std:cerr << endl;}
 
        private:
        bool first;
        std::string separator;
    };
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
 
#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif
 
typedef long long LL;
 
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;
 
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<VL> VVL;
 
 
int ni()
{
    int _num; s(_num);
    return _num;
}
 
 
 
/*-------------------------Main code begins now ------------------------------*/
int testnum;
 
struct LCA
{
    #include <vector>
 
    vector<int> L, D;
    vector<vector<int> > P;
    int N;
    LCA(vector<int>  dad, vector<int>  level)
    {
        N = dad.size();
        D = dad,         L = level;
        int LOG = 1,     base = 1;
 
        while(base < N)
            LOG++, base <<= 1;
 
        P.resize(N, vector<int>(LOG, -1));
 
        for (int i = 0; i < N; i++)
            P[i][0] = D[i];
 
        for (int j = 1; 1 << j < N; j++)
            for (int i = 0; i < N; i++)
                if (P[i][j - 1] != -1)
                    P[i][j] = P[P[i][j - 1]][j - 1];
    }
 
    int query(int p, int q)
    {
        int tmp, log, i;
        if (L[p] < L[q])
            tmp = p, p = q, q = tmp;
 
        for (log = 1; 1 << log <= L[p]; log++);
        log--;
 
        for (i = log; i >= 0; i--)
            if (L[p] - (1 << i) >= L[q])
                p = P[p][i];
 
        if (p == q)
            return p;
 
        for (i = log; i >= 0; i--)
            if (P[p][i] != -1 && P[p][i] != P[q][i])
                p = P[p][i], q = P[q][i];
 
            return D[p];
    }
};
 
int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
struct segment
{
    int first, last, diffGcd;
    int lazysum;
};
 
void addSegment(segment &s1, segment &s2, segment &s3)
{
    s3.first = s1.first;
    s3.last = s2.last;
    s3.diffGcd = abs(gcd(s1.diffGcd, gcd(s2.first - s1.last, s2.diffGcd)));
}
void getSegment(int a, segment &s)
{
    s.first = s.last = a;
    s.lazysum = 0;
    s.diffGcd = 0;
}
// void print(segment s)
// {
//     string a;
//     stringstream ss;
//     ss << "First = " << s.first << " Last = " << s.last << " diffGcd = " << s.diffGcd << " lazysum = " << s.lazysum << endl;
//     cout << ss.str();
// }
 
 
struct segtree
{
  int base;
  vector<segment> tree;
  VI A;
  segtree() {}
  
  segtree(VI _A)
  {
      A = _A;
      int N = A.size();
      base = 1;
      while(base < N) base *= 2;
      tree.resize(2*base);
      makeSegment(1);
  }
  
  void makeSegment(int ind)
  {
    if(ind >= base)
        getSegment(A[ind-base], tree[ind]);
    else
    {
        int twice = ind << 1;
        makeSegment(twice);
        makeSegment(twice+1);
        addSegment(tree[twice], tree[twice+1], tree[ind]);
        tree[ind].lazysum = 0;
    }
  }
  
  int lo, hi;
 
  void update(int ind, int beg, int end, int d)
  {
      if( end < lo || beg > hi) return;
      if( lo <= beg && end <= hi)
      {
	  tree[ind].first += d;
	  tree[ind].last += d;
	  tree[ind].lazysum += d;
	  return;
      }
      int twice = ind << 1, mid = (beg + end) >> 1;
      
      update(twice, beg, mid, d);
      update(twice+1, mid+1, end,d);
 
      addSegment(tree[twice], tree[twice+1], tree[ind]);
      tree[ind].first += tree[ind].lazysum;
      tree[ind].last += tree[ind].lazysum;
  }
 
  int query(int ind, int beg, int end, int lazysum)
  {
      if(end < lo || beg > hi) return 0;
      if(lo <= beg && end <= hi)
	  return gcd(tree[ind].first + lazysum, tree[ind].diffGcd);
      
      lazysum += tree[ind].lazysum;
      int twice = ind << 1, mid = (beg + end) >> 1;
      
      return gcd( query(twice, beg, mid, lazysum), query(twice+1, mid+1, end, lazysum));
  }
 
  void update(int u, int v, int d)
  {
      lo = u, hi = v;
      update(1, 0, base -1, d);
  }
 
  int query(int u, int v)
  {
      lo = u, hi = v;
      return query(1, 0, base-1, 0);
  }
};
 
 
/*****************************************************************/
const int maxn = 100005;
VI adjList[maxn];
int dad[maxn], subtree[maxn], level[maxn];
int N;
 
 
int dfs(int u, int p, int l)
{
  if(dad[u] >= 0) return 0;
  dad[u] = p;
  level[u] = l;
  
  int its = 0;
  foreach(it, adjList[u])
    its += dfs(*it, u, l+1);
  return subtree[u] = 1 + its;
}
 
int cnum;
VI chain[maxn];
int chainHead[maxn], chainPos[maxn], chainIndex[maxn];
int A[maxn];
 
 
void HLD(int u)
{
  if(chain[cnum].size() == 0)
    chainHead[cnum] = u;
  
  chain[cnum].pb(u);
  chainPos[u] = chain[cnum].size() - 1;
  chainIndex[u] = cnum;
  
  int most = 0, ind = -1;
  foreach(it, adjList[u])
  {
    int v = *it;
    if(v == dad[u]) continue;
    if(subtree[v] > most)
      most = subtree[v], ind = v;
  }
  
  if(ind >=0) HLD(ind);
  
  foreach(it, adjList[u])
  {
    int v = *it;
    if(v == dad[u] || v == ind) continue;
    ++cnum;
    HLD(v);
  }
}
 
 
vector<segtree> decomp;
 
int hld_find(int u, int l)
{
  int soFar = 0;
  while(true)
  {
    int c = chainIndex[u];
    
    if( c != chainIndex[l])
    {
      soFar = gcd(soFar, decomp[c].query(0, chainPos[u]));
      u = dad[u];
    }
    else
    {
      soFar = gcd(soFar, decomp[c].query(chainPos[l], chainPos[u]));
      break;
    }
  }
  return soFar;
}
 
int hld_change(int u, int l, int d)
{
  while(true)
  {
    int c = chainIndex[u];
    
    if( c != chainIndex[l])
    {
      decomp[c].update(0, chainPos[u], d);
      u = dad[u];
    }
    else
    { 
      decomp[c].update(chainPos[l], chainPos[u], d);
      break;
    }
  }
}
 
void solve()
{
   fill(dad, -2);
   dfs(0, N, 0); 
   dad[0] = -1;
   LCA lca( VI(dad, dad+N), VI(level, level + N));
   cnum = 0;
   HLD(0);
   cnum++;
   forall(c, 0, cnum)
   {
     VI its;
     foreach(it, chain[c])
       its.pb( A[*it]);     
     decomp.pb( segtree(its));
   }
   
   int Q;
   s(Q);
   char cmd[5];
   int u,v,d;
   forall(i, 0, Q)
   {
     ss(cmd);
     s(u); s(v); 
     int l = lca.query(u,v);
     if(cmd[0] == 'F')
     {
       int ans = gcd( hld_find(u, l), hld_find(v, l));
       printf("%d\n", ans);
     }
     
     else
     {
	s(d);
	hld_change(u, l, d);
	hld_change(v, l, d);
	hld_change(l, l, -d);		// we've added a term of d to lca twice, better remove once.
     }
   }
}
 
bool input()
{
  s(N);
  forall(i, 0, N-1)
  {
    int a, b; s(a); s(b);
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  
  forall(i, 0, N)
    s(A[i]);
    return true;
}
 
 
int main()
{
    int T = 1;
    for(testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;
        solve();
    }
}
 
