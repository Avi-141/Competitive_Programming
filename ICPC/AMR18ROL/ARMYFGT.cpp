#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include<string.h>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;



const int maxn = 0;
const ll bound = 1000000000;
const int M=500;
int divisors[M+1];
bool f;

/*ll lcm(ll a,ll b){
	return (a/__gcd(a,b))*b;
}*/

void divsieve(){
for (int i = 1; i <= M; ++i)
 for (int j = i; j <= M; j += i)
  ++divisors[j];
  }

ll lcm(ll a, ll b){
    ll g = __gcd(a,b);
    a /= g;
    if (((bound * bound) / a) < b)
     f = true;
    if (((bound * bound) / b) < a)
     f = true;
    return a*b;
}

int main (){

    ll test;

    cin>>test;

    while(test--){

        ll n;

        cin>>n;
        ll l = 1;
        f = false;
        for(ll i = 0; i < n; i++){
            ll tmp;
			cin>>tmp;
			l = lcm(tmp,l);
        }

        ll lo,up;

        cin>>lo>>up;

        ll temp=up-lo+1;

        ll ans = ((up)/l) - ((lo-1)/l);

        if(!f){
            cout<<temp-ans<<"\n";
        }
        else{
            cout<<temp<<"\n";;
        }
    }
    return 0;
}
