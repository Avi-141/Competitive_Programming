#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll findSmallestDivisor(ll n){
    if(n%2 == 0){
        return 2;
    }
    for(int j =3;j<=n;j+=2){
        if(n%j == 0)
            return j;
    }
    return n;
}

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
int main()
{
    sieve();
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    ll T,n,k,f;
    cin>>T;
    while(T--){
        cin>>n>>k;
        if(n%2==0){
                ll ans=n+2*k;
                cout<<ans<<"\n";
                continue;
            }
            if(is_prime[n]){
                ll ans=n+n+2*(k-1);
                cout<<ans<<"\n";
                continue;
            }
            int f=0;
            for(ll i=2;i<=sqrt(n);i++){
                if(n%i==0){
                    f=i;
                    break;
                }
            }
            ll ans=n+f+2*(k-1);
            cout<<ans<<"\n";
        }

    return 0;
}