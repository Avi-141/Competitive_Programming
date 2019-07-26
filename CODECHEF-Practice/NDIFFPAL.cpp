//CODECHEF - NDIFFPAL
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bits/stdc++.h>
#define ll long long
#define rep(x,a,b,c) for(int x=a;x<=b;x+=c)
#define repp(x,a,b) rep(x,a,b,1)
#define rev(x,a,b,c) for(int x=a;x>=b;x-=c)
#define revv(x,a,b) rev(x,a,b,1)
using namespace std;


int main(){
	ll t,n,a,b;

	cin>>t;;
	while(t--)
	{
		cin>>n;
		a=n/3;
		b=n%3;
		if(b==1)cout<<"z";
		if(b==2)cout<<"yz";

		repp(i,1,a)
		cout<<('a'+((i-1)%26));
		revv(i,a,1)
		cout<<('a'+((i-1)%26));
		printf("\n");
	}
}
