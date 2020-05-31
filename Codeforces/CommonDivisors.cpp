#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()

/*const ll N=5e5;
vector<bool> is_prime(N+1, true);
void sieve(){
is_prime[0] = false;
is_prime[1] = false;
	for (int i = 2; i <= N; i++) {
    	if (is_prime[i] && (long long)i * i <= N) {
        	for (int j = i * i; j <= N; j += i)
            	is_prime[j] = false;
    	}
	}
}*/
int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    ll curr=arr[0];
    for(int i=1;i<n;i++){
    	curr=__gcd(curr,arr[i]);
    }
    //ans is divisors of curr=gcd(a0,a1...an)
    int ans=1;
    for(ll div = 1; div*div <=curr; div++) {
        if(curr%div == 0) {
            ans++;
            if(div*div!= curr) 
            {
                ans++;
            }
        }
    }
    cout << ans-1;
}