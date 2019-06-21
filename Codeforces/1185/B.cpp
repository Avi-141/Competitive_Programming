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
  int n,i,j;
  string s,s1;
  bool ok;

    cin>>n;
    while(n--)
    {
      cin>>s>>s1;
     int l=s.size();
     int l1=s1.size();
       ok=0;
        for( i=0,j=0;i<l1;i++)
        {
              if(s1[i]==s[j])
                j++;
              else if (s1[i]!=s[j]&&s1[i]!=s[j-1])
                ok=1;
        }
       if(j==l&&ok==0)cout<<"YES\n";
       else cout<<"NO\n";
    }
}

/*int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    string s1,s2;
    cin >> s1 >> s2;
    int i,j;
    for(i=0,j=0;s2[j];j++)
    {
      if(s1[i]==s2[j])
        i++;
      else if(s2[j]!=s2[j-1])
        break;
    }
    if(s2[j]=='\0' && s1[i]=='\0')
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}*/