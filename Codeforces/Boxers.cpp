#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    ll  n;
    cin>>n;
    vector<ll > wt(n);
    set<ll > s;
    map<ll ,ll > mp;
    for(ll  i=0;i<n;i++){
    	cin>>wt[i];
    	s.insert(wt[i]);
    	mp[wt[i]]++;
    }
    sort(wt.begin(), wt.end());
    if(s.size()==n){
    	cout<<n<<'\n';
    	return 0;
    }
    //dec same inc
   int last = 0, ans = 0;
   for (int i = 0; i < n; i++){
     for (int d : {-1,0,1}) {
       if (wt[i]+d > last) {
			last = wt[i]+d;
			ans++;
			break;
      	}
      }
  	}
	cout << ans << endl;
}