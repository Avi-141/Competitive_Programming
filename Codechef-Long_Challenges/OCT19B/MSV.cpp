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
		ll n;
		cin>>n;
		vector<ll> arr(n);
		map<ll,vector<ll>> um;
		vector<ll> idx;
		ll maxm=INT_MIN;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			maxm=max(maxm,arr[i]);
		}
		std::map<ll,vector<ll> >::iterator it,nextit;
		for(ll i=0;i<n;i++){
           if (um.find(arr[i]) == um.end()) {              
            idx.push_back(i);
            um.insert(make_pair(arr[i],idx));            
            idx.clear();
        }
        else if(um.find(arr[i])!=um.end()){
            it = um.find(arr[i]);
            it->second.push_back(i);
        }
    }
    ll  maxx=INT_MIN;
    ll curr=0;
    for(it=um.begin();it!=um.end();it++){
           curr=0;
           ll f=it->first;
           ll last=it->second.size()-1;
           ll occ=it->second[last];
           for(ll j=it->first;j<maxm+1;j=j+it->first){    
                nextit=um.find(j);
                if(nextit!=um.end()){

                    ll sz=nextit->second.size();
                    for(ll fin=0;fin<sz;fin++){
                        if(occ>nextit->second[fin])
                            curr+=1;
                }
            }
        }
        maxx=max(maxx,curr);
    }
    cout<<maxx<<"\n";
  }
}