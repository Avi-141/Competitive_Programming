#include<bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fl(i,a,b,c) for(int i=a;i<b;i+=c)
#define rl(i,a,b,c) for(int i=a;i>b;i-=c)

const ll N=1e6;

vector<ll> vec;
vector<char> is_prime(N+1, true);


void sieve(){
    is_prime[0] = false;
    is_prime[1] = false;
for (int i = 2; i <= N; i++) {
    if (is_prime[i] && (long long)i * i <= N) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
 }
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(vector<ll> a, ll n) {
  ll res = 1, i;
  for (i = 0; i < n; i++) {
    res = res*a[i]/gcd(res, a[i]);
  }
  return res;
}

//sum of gcd of all pairs // number from 1 to n 
ll calculate(int N)
{
    vector<ll> a(N,0);
    fl(i,1,N,1)
        fl(j,i,N,i)
            a[i]++;
    fl(i,1,N,1)
        a[i] = (a[i] * (a[i]-1))/2;
    rl(i,N,0,1)
        fl(j,2*i,N,i)
            a[i] -= a[j];
    ll sum = 0;
    fl(i,1,N,1){
        sum += a[i]*i;
        vec.push_back(a[i]*i);
    }
    return sum;
}


int main(){
    sieve();
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
        ll n;
        cin>>n;
        vector<ll> a(n);
        ll i;
            for(i=0;i<n;i++)
                cin>>a[i];
            ll left[n],right[n];
            left[0]=0;
            for(i=1;i<n;i++)
                left[i]=__gcd(left[i-1],a[i-1]);
            right[n-1]=0;
            for(i=n-2;i>=0;i--){
                right[i]=__gcd(right[i+1],a[i+1]);
            }
            ll ans=0;
            for(i=0;i<n;i++){
                ll g1=__gcd(left[i],right[i]);
                ll g2=__gcd(g1,a[i]);
                ll lcm=(g1*a[i])/g2;
                ans=__gcd(ans,lcm);
            }
            cout<<ans<<"\n";
}