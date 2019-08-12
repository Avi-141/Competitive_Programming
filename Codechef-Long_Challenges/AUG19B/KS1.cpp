#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mod7 1000000007
#define mod9 1000000009
#define fp(i,a,b) for(i=(a); i<(b); i++)
#define fip(it,a) for(it=(a.begin()); it!=(a.end()); it++)
#define fm(i,a,b) for(i=(a); i>(b); i--)
#define fim(it,a) for(it=(a.end()); it!=(a.begin()); it--)
#define pv(v) for(int print: v) { cout<<print<<endl;}
#define vl vector<ll>
#define vi vector<int>
// namespace mpc = boost::multiprecision;
using namespace std;

bool cmpf(float a,float b,float epsilon){return(fabs(a-b)<=epsilon*max(fabs(a),fabs(b)));}
ll fpow(ll n,ll k,ll p){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%p;n=n*n%p;}return r;}
ll inv(ll a, ll p){return fpow(a,p-2,p);}


// use mpc::cpp_int for big integers
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t,n,m,k,d,di,ti,si,cnt,temp,i,j;

    cin>>t;
    while(t--)
    {
        cin>>n;
        vl v;
        map<ll, vl> mv;
        map<ll, vl>::iterator it;
        mv.insert(mp(0, v));
        mv[0].pb(0);
        d = 0;
        fp(i, 0, n) {
            cin>>m;
            d ^= m;
            it = mv.find(d);
            if(it == mv.end()) {
                mv.insert(mp(d, v));
            	mv[d].pb(i + 1);
            }
            else
                mv[d].pb(i + 1);
        }
        
        // fip(it, mv) {
        // 	vl vv = it->second;
        // 	cout<<it->first<<": ";
        //     fp(i, 0, vv.size())
        //         cout<<vv[i]<<" ";
        //     cout<<endl;
        // }
        
        cnt = 0;
        fip(it, mv) {
        	k = it->second.size();
        	if(k > 1) {
        		vl vv = it->second;
        		temp = 0;
        		fp(i, 1, k) {
        			if(i > 1)
	        			temp += (vv[i] - vv[i-1] - 1) * (i - 1) + (i - 2);
        			cnt += (vv[i] - vv[0] - 1) + temp;
        // 			cout<<(vv[i] - vv[0] - 1)<<"+"<<temp<<" ";
        		}
        	}
        }
        cout<<cnt<<endl;
        
    }
	return 0;
}
