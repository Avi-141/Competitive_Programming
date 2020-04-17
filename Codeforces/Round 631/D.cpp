#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() int t;cin>>t;while(t--)
#define pb push_back
#define nl cout<<endl
// #define MOD 1000000007
#define loop(i,start,end) for(int i=start;i<end;i++)
#define N 100001
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
#define vinn(n,v) int n;cin>>n;vector<int>v(n);loop(i,0,n)cin>>v[i];
#define vinm(n,m,v) int n,m;cin>>n>>m;vector<int>v(n);loop(i,0,n)cin>>v[i];
#define debug(x) cerr<<#x<<" : "<<x<<endl;
mt19937 rd(time(0)); // i = rd%n
int MOD;
void solve()
{
    int d,m;
    cin>>d>>m;
    MOD = m;
    int ans = 1;
    for(int i = 1;;i*=2)
    {
        int cnt = 0;
        if(i>d)break;
        if(i==d)
        {
            cnt = 1;
        }
        else if(2*i>d)cnt = d-i+1;
        else cnt = i;
        ans*=(1+cnt);
        ans%=m;
        ans+=m;
        ans%=m;
    }
    cout<<((ans-1+m)%m+m)%m<<endl;
}
signed main() 
{
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    test() solve();
 
    return 0;
}