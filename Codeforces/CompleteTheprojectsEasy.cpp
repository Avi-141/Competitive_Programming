#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front

int n,r;
int a[102],b[102];
vector<pii> V;
priority_queue<pii> pq;
bool vis[102];

int main(){
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]>=0)
			V.pb(mp(a[i],b[i]));
	}
	sort(all(V));
	int count=V.size();
	//cout<<count<<"\n";
	for(int i=0;i<V.size();i++){
		if(V[i].first>r){
			cout<<"NO\n";
			return 0;
		}
		r+=V[i].second;
	}
	if(count==n){
		cout<<"YES\n";
		return 0;
	}
	V.clear();
	for(int i=1;i<=n;i++){
		if(b[i]<0){
			r+=b[i];
		}
	}
	if(r<0){
		cout<<"NO\n";
		return 0;
	}
	while(true){
		//order of projects matters
		bool bad=1;
		for(int i=1;i<=n;i++)
			if(b[i]<0 && !vis[i] && r-b[i]>=a[i]){
				//cout<<"before  "<<r<<"\n";
				r=r-b[i];
				//cout<<b[i]<<" "<<a[i]<<"\n";
				//cout<<"after  "<<r<<"\n";
				vis[i]=1;
				count+=1;
				//cout<<count<<"\n";
				bad=0;
			}
		if(bad)
			break;
	}
	if(count<n)
		cout<<"NO\n";
	else 
		cout<<"YES\n";
	return 0;

}
/*
9 4
3 3
7 0
2 0
5 4
7 -3
7 -7
7 -6
6 5
5 0
YES
*///
//https://cp-algorithms.com/schedules/schedule-with-completion-duration.html
//https://codeforces.com/contest/1203/submission/60304846
//https://codeforces.com/contest/1203/submission/58753048
//https://codeforces.com/contest/1203/submission/58774527

/*    #include "bits/stdc++.h"
    using namespace std;
    typedef pair<int, int> ii;
    #define fi first
    #define se second
     
    void ex(string S) {
      cout << S << endl;
      exit(0);
    }
     
    int main() {
      ios::sync_with_stdio(false);
     
      int N, R;
      cin >> N >> R;
     
      vector<ii> P, Q;
      for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (b >= 0) {
          P.emplace_back(a, b);
        } else {
          Q.emplace_back(a, -b);
        }
      }
     
      sort(P.begin(), P.end());
      sort(Q.begin(), Q.end(),
           [](ii a, ii b) { return a.fi - a.se > b.fi - b.se; });
     
      for (auto [a, b] : P) {
        if (a > R) {
          ex("NO");
        }
        R += b;
      }
      for (auto [a, b] : Q) {
        if (a > R) {
          ex("NO");
        }
        R -= b;
      }
     
      if (R >= 0) {
        ex("YES");
      } else {
        ex("NO");
      }
     
      return 0;
    }
    */