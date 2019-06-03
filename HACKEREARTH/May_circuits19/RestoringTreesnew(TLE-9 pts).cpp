#include <bits/stdc++.h>
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
using namespace std;
#define ll long long int

void print(ll a[], ll n)
{
    for(ll i = 0;i < n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void pairsort(ll a[], ll b[], ll c[], ll n)
{
    pair<ll, ll> p[n], q[n];
    for(ll i = 0;i < n;i++)
    {
        p[i].first = a[i];
        q[i].first = a[i];
        p[i].second = b[i];
        q[i].second = c[i];
    }
    sort(p, p + n);
    sort(q, q + n);
    for(ll i = 0;i < n;i++)
    {
        a[i] = p[i].first;
        b[i] = p[i].second;
        c[i] = q[i].second;
    }
}

int main(int argc, char const *argv[])
{
    ll n; //num of vertices
    cin >> n;
    ll a[n], b[n], c[n]; //start time, end time, indices
    for(ll i = 0;i < n;i++)
    {
        cin >> a[i];
        c[i] = i;
    }
    for(ll i = 0;i < n;i++)
    {
        cin >> b[i];
    }
    pairsort(a, b, c, n); //sort as per start time
    ll result[n];
    memset(result, -1, n);
    result[c[0]] = 0; //root
    stack<ll> parent;
    parent.push(c[0]);
    ll chlidren[n];
    for(ll i = 0;i < n;i++)
    {
        chlidren[c[i]] = b[i] - a[i] - 1; //calculate number of children and grand children
    }
    for(ll i = 1;i < n;i++)
    {
        result[c[i]] = parent.top(); //assign last seen parent as parent
        ll temp = parent.top();
        while(1)
        {
            chlidren[temp]--; //subtract 1 child for parent and all grand parents
            if(temp != 0)
            {
                temp = result[temp];
            }
            else
            {
                break;
            }
        }
        if(chlidren[parent.top()] == 0)
        {
            parent.pop(); //pop if seen all children
        }
        if(chlidren[c[i]] > 0)
        {
            parent.push(c[i]); //push if it has children
        }
    }
    for(ll i = 0;i < n;i++)
    {
        result[i] += (result[i] > 0 ? 1 : 0); //make everything one based index
    }
    print(result, n);
    return(0);
}