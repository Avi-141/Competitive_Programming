#include<bits/stdc++.h>
using namespace std; 
 
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef vector<vector<int> > g;
typedef pair<int, int> pi;

ll ans=-1;
void solution(ll a,ll b,ll d) 
{ 
    for (ll i = 0; i * a <= d; i++) { 
        if ((d - (i * a)) % b == 0) { 
            //cout << "x = " << i << ", y = " 
                 ans=(d - (i * a)) / b; 
            return; 
        } 
    } 
} 
int main(){

     #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    ll q,a,b,d;
    cin>>q;
    //move from xi yi to xj yj iff euc(p1,p2)=a or b
    //0,0 to d,0 min steps
    for(ll i=1;i<=q;i++){
        cin>>a>>b>>d;
        //solution(a,b,d);
        if(d==0)
            cout<<0<<'\n';
        else if(d==a)
            cout<<1<<"\n";
        else if((d==a-1 && d!=0) || (d < b && d!=0))
            cout<<2<<"\n";
        else if(d%b)
            cout<<d/b +1<<"\n";
        else if(!(d%b))
            cout<<d/b<<"\n";
    }
}