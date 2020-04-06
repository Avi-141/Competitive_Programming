#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long 
#define mp make_pair 
#define pb push_back 
const int MAX = 998244353;

int main(){
	int t;
	cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  vector<pair<ld,ld>> curr,newshape;
      ld area=0.0;
      ld x,y;
      for(int i=0;i<n;i++){
      	cin>>x>>y;
      	curr.pb(mp(x,y));
      }
      for(int i=1;i<n;i++){
      	ld midx=(curr[i].first+curr[i-1].first)/2.0;
      	ld midy=(curr[i].second+curr[i-1].second)/2.0;
      	newshape.pb(mp(midx,midy));
     }
     ld modx=(curr[n-1].first+curr[0].first)/2.0;
     ld mody=(curr[n-1].second+curr[0].second)/2.0;

     for(int i=0;i<n-1;i++){
     	area+=(newshape[i].first*newshape[i+1].second -newshape[i+1].first*newshape[i].second);
     }
     area+=(newshape[0].first*newshape[n-1].second-newshape[0].second*newshape[n-1].first);

     area/=2;
     cout<<fixed<<setprecision(16)<<area<<"\n";     
	}
}