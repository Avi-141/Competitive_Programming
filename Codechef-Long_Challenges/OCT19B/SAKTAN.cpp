#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include<string.h>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

#define ll long long 

int main(){

	int t;
	cin>>t;
	while(t--){
		int n,m,q;
		ll maxx=0;
		cin>>n>>m>>q;
		int flag=0;
		int row[n],col[m];
		memset(row,0,sizeof(int)*n);
		memset(col,0,sizeof(int)*m);
        for(int i=1;i<=q;i++){
        	int x,y;
        	cin>>x>>y;
            row[x-1]+=1;
            col[y-1]+=1;
        }
	ll rowo=0,colo=0,rowe=0,cole=0;
	for(int i=0;i<n;i++){
		if(row[i]&1)
			rowo++;
		else 
			rowe++;
	}
	for(int i=0;i<m;i++){
		if(col[i]&1)
			colo++;
		else cole++;
	}
	ll ans=rowe*colo + cole*rowo;
	cout<<ans<<"\n";
  }
}