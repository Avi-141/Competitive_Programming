#include<bits/stdc++.h>
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
#define dd double
using namespace std;

vector<ll> veccoprime(100005);
int main()
{
    ll n,c=0;
     cin>>n;
    ll i,j;
    for (i=2;i<=n;i++)
    {
        if (!veccoprime[i])
        {
            veccoprime[i]=++c;
            for (j=i;j<=n;j+=i)
            veccoprime[j]=veccoprime[i];
        }
      cout<<veccoprime[i]<<" ";
    }
}