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

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n+1];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int minval = 0, minDiff = 1e9;
        for(int i=0;i<n-k;i++)
        {
            int temp = a[i + k] - a[i];
            if(minDiff > temp)
            {
                minDiff = temp;
                minval = (a[i] + a[i + k])/2; //Average lete raho.
                // average of points which have k-1 integers between them .
                //decrease the distances of the k consecutives elements.
            }
        }
        cout << minval << endl;
    }

}