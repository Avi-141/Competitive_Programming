#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


int main(){

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int x,y;
		string st;
		cin>>x>>y>>st;
		string pr="IMPOSSIBLE";
		int ans=INT_MAX;
		int time=0;
		for(int i=0;i<st.size();i++){
			if(st[i]=='S')
				y--;
			else if(st[i]=='N')
				y++;
			else if(st[i]=='E')
				x++;
			else x--;
			time++;
			ll sum=abs(x)+abs(y);
			if(sum<=time)
				ans=min(ans,time);
		}
		if(ans==INT_MAX){
			cout<<"Case #"<< tt <<": "<<pr<<"\n";
		}
		else cout<<"Case #"<< tt <<": "<<ans<<"\n";
	}
}