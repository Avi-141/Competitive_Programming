#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define f first 
#define s second
using namespace std;
typedef pair<ll,ll> pairs;

template<typename T1, typename T2, typename T3>
struct triplet
{
    T1 first; 
    T2 second;
    T3 third;
};

template<typename T1, typename T2, typename T3>
triplet<T1,T2,T3> make_triplet(const T1 &m1, const T2 &m2, const T3 &m3) 
{
    triplet<T1,T2,T3> ans;
    ans.first = m1;
    ans.second = m2;
    ans.third = m3;
    return ans;
}
struct triplevec
{ 
   ll x, y, z; 
}; 

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	vector<ll> st(n),ft(n),t1(n+1),t2(n);
	vector<triplevec> tree1;
	vector<pair<ll,pairs> >tree; 
	stack<pair<ll,pairs>> stk;
	pair<ll,pairs> iter;
  

forloop(i,n)
  	cin>>st[i];
forloop(i,n)
   {
     cin>>ft[i];
     tree.pb(mp(st[i],(mp(ft[i],i))));
     }
    sort(tree.begin(),tree.end());
    ll siz=tree.size();

    stk.push(tree[0]);
    t1[tree[0].s.s]=0;
    for(ll i=1;i<n;i++)
    {
    	iter=stk.top();
    	while(true)
    	{
    		if(iter.f<=tree[i].f&&tree[i].s.f<=iter.s.f)// v is an ancestor of u iff stv<=stu<=ftu<=ftv
    			//here st and ft stand for start and finish time
    		{
    			stk.push(tree[i]);
    			t1[tree[i].s.s]=(iter.s.s+1);
    			break;
    	     }
    	else
    	{
    		stk.pop();
    		iter=stk.top();
    	}
    }
}
/*for(ll i=0;i<n;i++){
if(t1[i]!=0)
t1[i]+=1;
}*/
for(ll i=1;i<=n;i++){
	cout<<t1[i]<<" ";
    }
}