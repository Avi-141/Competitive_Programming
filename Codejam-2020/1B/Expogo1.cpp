#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ar array
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

char dir[4]={'S','N','W','E'};
string ans;

//subtracting from x position is actually going 'E'
//adding to   x position is actually going 'W'
//subtracting from  y position is actually going  'N'/
//adding to  y position is actually going 'S'


ll transX(ll N,ll x,ll i){
     
     if(i==2)
     	x+=1LL<<N;
     if(i==3)
     	x-=1LL<<N;
     return x;
}

ll transY(ll N,ll y,ll i){
     
     if(i==0)
     	y+=1LL<<N;
     if(i==1)
     	y-=1LL<<N;
     return y;
}

void find(ll N,ll x,ll y){
	if(N==-1)
		return;
	for(int i=0;i<4;++i){
		ll next_x=transX(N,x,i),next_y=transY(N,y,i);
		//check sum
		//2^N -1 >= sum
		if((1LL<<(N))-1>=(abs(next_x)+abs(next_y))){
			find(N-1,next_x,next_y);
			ans+=dir[i];
			break;
		}
	}
}

void solve(){
	ans="";
	ll x,y;
	cin >> x >> y;
	ll curr=x+y;
	if(curr%2==0){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	//Lets fix number of moves K Then,
	//N+S+E+W=2^K−1
	ll sum=abs(x)+abs(y);
	ll N=0;
	while((1LL<<N)-1<sum)
		++N;
	find(N-1,x,y);
	cout<< ans <<"\n";

}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<< "Case #" << i <<": ";
		solve();
	}
}