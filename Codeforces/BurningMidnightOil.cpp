#include<bits/stdc++.h>
#define ll long long 
#define bigint int64_t
#define pb push_back
#define ld long double
#define ull unsigned long long 
using namespace std;
#define MAXN 100005


bool possible(ll n, ll k, ll v) 
{ 
    ll done = 0; 
    ll div = 1; 
    while (n > done) { 
        ll tadd = v / div; 
        if (tadd == 0) { 
            break; 
        } 
        done += tadd; 
        div *= k;  
    } 
    return (done >= n); 
} 
 
ll solve(ll n, ll k) 
{ 
    ll hi = 10000000000ll; 
    ll lo = 0; 
     
    while (lo + 1 < hi ) { 
        ll ha = (hi + lo) / 2; 
         
        if (possible( n, k, ha ) ) { 
            hi = ha; 
        } else { 
            lo = ha; 
        } 
    } 
    return hi; 
     
} 


int main()
{
    ll n,k;
    cin>>n>>k;

    cout<<solve(n,k);
    
    
}