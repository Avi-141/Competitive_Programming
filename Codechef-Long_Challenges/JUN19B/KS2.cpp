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
//ull arr[]={20,30,40,50,60,70,80,90,100,130,

ull cnst_time(ull n) 
{ 
    ull req = 19 + (n - 1) * 9; 
    ull cnt = (ull)log10(req) - 1; 

    req += 9 * cnt; 
    return req; 
} 

  
int main(int argc, char const *argv[])
{
   ull t;
   cin>>t;
   lab:
   while(t--)
   {
     ull n;
     cin>>n;
     ull flag=0;
     ull pos=0;
     if(n==1)
     {
     cout<<19<<"\n";
    goto lab;
     }
     for(ull i=0;i<=9;i++)
     { 
       ull nth=n*10+i;
       ull sum=0;
        while (nth!=0) 
       { 
        sum = sum + (nth%10); 
        nth/=10; 
       }
      // if(sum<10)
      // continue;
       if(sum%10==0)
        {
            flag=1;
            pos=i;
            //flag=1;
            break;
        }
      //  else continue;
     }
if(flag==1)
cout<<(n*10+pos)<<"\n";
}
}