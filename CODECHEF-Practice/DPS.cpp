#include <bits/stdc++.h>
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
#define mp(x,y) make_pair(x,y)
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
using namespace std;

int main(int argc, char const *argv[]){
int t;
cin>>t;
while(t--)
    {
        string strings;
         ip(strings);
         ll n = strings.length();
         if(n%2==0)
         {
             ll letterhash[26]={0};
             forloop(i,n)
                 letterhash[strings[i]-97]++;
             ll count = 0;
             forloop(i,26)
                 if(letterhash[i]%2)
                     count++;
             if(count == 2)
                 op("DPS");
             else
                 op("!DPS");
         }
         else
         {
             ll letterhash[26]={0};
             forloop(i,n)
                 letterhash[strings[i]-97]++;
             ll count = 0;
             forloop(i,26)
                 if(letterhash[i]%2)
                     count++;
             if(count == 1 || count == 3)
                 op("DPS");
             else
                 op("!DPS");
         }
}
}