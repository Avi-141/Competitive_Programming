#include <bits/stdc++.h>
using namespace std;
 
 #define ll long long 


int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin>>T;
    ll N,X,M;
    while(T--){
       cin>>N>>X>>M;
        //ll count=0;
        ll minx=X;
        ll maxx=X;
        while(M--){
            ll l,r;
            cin>>l>>r;
            if((r>=minx &&r<=maxx)||(maxx>=l &&maxx<=r)){
                minx=min(minx,l);
                maxx=max(r,maxx);
            }
        }
        ll ans= maxx-minx+1;
        cout<<ans<<"\n";
	}
}
