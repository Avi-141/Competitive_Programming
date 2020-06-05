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
	}
	for(int i=1;i<=n;i++){
		if (b[i]>=0) 
			V.pb(mp(a[i],b[i]));
	}
	sort(all(V));
	for (int i=0;i<V.size();++i){
		if (r<V[i].first){
			cout<<"NO";
			return 0;
		}
		r+=V[i].second;
	}
	int cnt=V.size();//completed till now.
	if (cnt==n){
		cout<<"YES";
		return 0;
	}
	V.clear();
	for(int i=1;i<=n;i++){
		if (b[i]<0) 
			r+=b[i];
	}
	if (r<0){
		cout<<"NO";
		return 0;
	}
	while(true){
		bool bad=1;
		for(int i=1;i<=n;i++)
			if (b[i]<0 && !vis[i] && r-b[i]>=a[i])
			{
				r-=b[i];
				vis[i]=1;
				cnt+=1;
				bad=0;
			}
		if (bad) break;
	}
	if (cnt<n) 
		cout<<"NO";
	else 
		cout<<"YES";
	return 0; 
}


/*
Let's first focus on two adjacent projects i,j in the current arrangement (supposing j=i+1
), and see when we should swap them.(Obviously, the swap will not affect other projects.)
 That's to say, we should see which way will make completing both projects "easier".

I.
If we can take both of them by taking i first, 
that means our initial rating r satisfies both r≥ai & r+bi≥aj, which is equivalent to r≥max(ai,aj−bi)
II.
If we can to take both of them by taking j first, 
that means our initial rating r satisfies both r≥aj & r+bj≥ai, which is equivalent to r≥max(aj,ai−bj)
We wonder which constraint is weaker. We already have aj−bi>aj,ai−bj>ai
, so we just need to compare I. aj−bi and II. ai−bj. 
The smaller, the weaker. 
Note that I.<II. <=> aj−bi<ai−bj <=> ai+bi>aj+bj. 
So, for every pair of adjacent projects, we should determine whether to swap them or not by the value ai+bi. 
In other words, we have the sequence sorted in the order of ai+bi.*/

