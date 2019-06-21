#include<bits/stdc++.h>
#define ll long long
#define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
#define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define clr(x) memset((x), 0, sizeof((x)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
#define mp make_pair
#define rep(i, a,b) for(int i=(a);i<=(b);++i)
#define _rep(i, a,b) for(int i=(a);i>=(b);--i)
#define iter(it) begin(it),end(it)
#define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
using namespace std;
typedef long double ld;
typedef long int li;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
typedef pair<ll,long int> PIII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define MOD 1000000007
#define INF 999999999

/*const li N=102;
li arr[N];
int main(int argc, char const *argv[])
{
	
	li n,M;
	scanf("%ld,%ld",&n,&M);
	li time;
	forn(i,n)
	{
	 scanf("%ld",&time);
	 li left=M-time;
	 li ans=i;
	 for(int y=1;y<N;y++)
	 {
	 	int take=min(left/y,arr[y]);
	 	ans=ans-take;
	 	left=left-y*take;
	 }
    printf("%ld",ans);
    arr[time]++;
}
printf("\n");
}*/
/*int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, M;
    cin >> n >> M;

    int t[n];
    rep(i, 0,n-1)
     cin >> t[i];

    int total = 0;
    rep(i, 0,n-1) 
    {
        sort(t,t+i);
        int atmost = M- t[i];
        int t_ =total;
        int c =0;
        int j = i-1;
        while(j >= 0 && t_ > atmost)
         {
            t_ -= t[j];
            c++;
            j--;
        }

        total += t[i];

        cout << c << " ";
    }

    cout << "\n";

    return 0;
}*/



int main() 
{ 
    ll n,m;
    cin>>n>>m;
    int t[103];
    int a[103];
    a[0]=0;
    for(int i=0;i<n;i++)
        cin>>t[i],a[i+1]=a[i]+t[i];
    int y = lower_bound(a+1,a+n+1,m)-(a+1);
    //cout<<"Y "<<y<<endl;
    if(a[y+1] == m)
        y++;
    for(int i=0;i<y;i++)
        cout<<"0 ";
    for(int i = y;i<n;i++)
    {
        sort(t,t+y);
        ll sum = a[y+1];
        //cout<<sum<<endl;
        for(int j = y-1;j>=0;j--)
        {
            
            sum-=t[j];
            //cout<<"SUM : "<<sum<<endl;
            if( sum<=m)
            {
                cout<<y-j<<" ",y++;
                break;
            }
        }
    }

}