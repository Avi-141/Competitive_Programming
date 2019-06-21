#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef pair<ll,long int> PIII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999



int main()
{

 ll arr[3],d;
 for(int i=0;i<3;i++)
 	cin>>arr[i];
    cin>>d;
    sort(arr,arr+3);
    long int tot=0;

  if(arr[2]-arr[1]<d)
  {
  	tot=tot+(d-(arr[2]-arr[1]));
  }
  if(arr[1]-arr[0]<d)
  {
  	tot+=d-(arr[1]-arr[0]);
  }

 printf("%ld",tot);
}