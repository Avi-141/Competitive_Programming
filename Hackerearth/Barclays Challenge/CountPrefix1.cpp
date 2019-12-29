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
typedef vector<ll> VI;
typedef vector<VI> VVI;


VI p[100002];


int main()
{
    ios_base::sync_with_stdio(0);

    ll n, q;
    cin >> n;
    ll arr[n];
    //forn(i,n)
    //cin>>arr[i];

    forn(i, n)
    {
        ull a;
        cin >> a;
        arr[i]=a;

        For(j, 1, sqrt(a) + 1)
        {
            if (a % j == 0)
            {
                if (p[j].empty() || p[j].back() != i)
                    p[j].pb(i);
                if (p[a/j].empty() || p[a/j].back() != i)
                    p[a/j].pb(i);
            }
        }
    }
    cin>>q;
 
    while(q--)
    {
        ull l, r, k;
        cin >> l >> r >> k;
        ll end=r;
        ll start=l;
        --l; --r;

        ll range=r-l+1;
       // cout<<range<<"ndsjkf"<<endl;
        ll check=upper_bound(all(p[k]), r) - lower_bound(all(p[k]), l);
        //cout<<check<<"heeje"<<endl;
        ll temp=range-check;
        ll flag=0,flag1=0;
        if(check!=0)
          flag=1;
         if(flag==1&&((range-check)>0))
         flag1=1;
        //cout<<temp<<"bdhfb"<<endl;
        ll mid=(l+r)/2;
        //cout<<temp<<" "<<range<<" "<<check<<endl;
        
        //cout<<check<<" "<<range;
        ll init=(arr[l]%k);
        ll sucessor=arr[l+1]%k;
       // ll idx2=l+2;
       // cout<<init<<" "<<sucessor<<endl;
      // cout<<range<<"hello"<<check;
       if(init==0&&sucessor>0)
        cout<<start<<"\n";
       else if(range==check&&init==0&&sucessor==0)
                cout<<end<<"\n";
        else if(init!=0||check==0)
        {
          cout<<-1;
         }
        /*else if(range==check+1){
            cout<<end<<"\n";
           
        }*/
        ll i;
        else if(init==0&&sucessor==0)
            {
                ll pos=0;
                   for(i=l+2;i<r;i++)
                   {
                    if((arr[i]%k)==0)
                     continue;
                    else 
                    break;
                   }
            i--;
            cout<<i+1<<"\n";
           } 
      }

    return 0;
}
