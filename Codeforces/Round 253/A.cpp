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



int main()
{
    fast

    string s;
    getline ( cin, s );
    int n = s.size();
    set < char > sc;

    for ( int i = 1; i < n-1; i += 3 ) {
        sc.insert ( s[i] );
    }

    cout << sc.size();

    return 0;
}