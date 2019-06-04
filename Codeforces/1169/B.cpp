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
#define mp(x,y) make_pair(x,y)
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define N 300010
using namespace std;

ll n,m,a[N],b[N],harkioccurence[N];
bool func(ll t)
{
    for(int i=1;i<=n;i++)harkioccurence[i]=0;
    ll gencnt=0;
    for(int i=0;i<m;i++){
  if(a[i]==t||b[i]==t)continue;
  gencnt++;
  harkioccurence[a[i]]++,harkioccurence[b[i]]++;
    }
    for(int i=1;i<=n;i++){
  if(harkioccurence[i]==gencnt)return 1;
    }
    return 0;
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
      cin>>a[i]>>b[i];
  }
  bool ans=0;
  ans|=func(a[0]);
  ans|=func(b[0]);
  cout<<(ans?"YES":"NO")<<endl;
  return 0;
}