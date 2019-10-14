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
#include <list>
using namespace std;
#define bigint int64_t
#define ll long long 

//list<ll> * adj;

void ans(ll spread[],bool vis[],int sz,list<ll> * adj){
	if(sz==1)
		return;
	vector<ll> clone;
	for(ll i=0;i<sz;i++)
		clone.push_back(spread[i]);
	queue<ll> qu;
	qu.push(0);
	while(!qu.empty()){
		list<ll >::iterator ele;
		ll top=qu.front();
		qu.pop();
		vis[top]=true;
		ll val=clone[top];
		for(ele=adj[top].begin();ele!=adj[top].end();ele++){
			if(!vis[*ele]){
				if(adj[*ele].size()==0){
					//cout<<*ele<<" "<<val<<"\n";
					spread[*ele]+=val;
				}
				else{
					spread[*ele]=val;
				}
				qu.push(*ele);
				//cout<<qu.front()<<" ";
			}
		}
	}
	spread[0]=0;
}

int main(){
	int n,q;
	cin>>n>>q;
	list<ll> *adj =new list<ll>[n];
	
    bool vis[n];
	queue<ll> path;
    ll spread[n];
    vector<pair<ll,ll> > bac_node;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin>>x>>y;
    	x--;
    	y--;
    	if(x==0||y==0){
    		if(y==0)
    			adj[0].push_back(x);
    		else 
    			adj[x].push_back(y);
    		continue;
    	}
    	
    	bac_node.push_back(make_pair(x,y));
    }
    path.push(0);
    vector<pair<ll,ll> >::iterator p;
    //check(path,vis,bac_node,adj);
    memset(vis,false,sizeof(bool)*n);
    while(!path.empty()){
		int top=path.front();
		path.pop();
		vis[top]=true;
		for(ll ele:adj[top]){
			if(!vis[ele]){
				path.push(ele);
				for(p=bac_node.begin();p!=bac_node.end();p++){
					std::list<ll>::iterator it,it2; 
					it = std::find (adj[p->second].begin(),adj[p->second].end(),ele); 
					it2= std::find (adj[p->first].begin(),adj[p->first].end(),ele); 
					if(p->first==ele && !(it!=adj[p->second].end()))
						adj[ele].push_back(p->second);
					else if(p->second==ele && !(it2!=adj[p->first].end()))
						adj[ele].push_back(p->first);
				}
			}
		}
	}
    for(int i=0;i<n;i++)
    	cin>>spread[i];
    
    bool visi[n]; 
    while(q--){
    	memset(visi,false,sizeof(bool)*n);

    	ans(spread,visi,n,adj);
    	char ch;
    	cin>>ch;
    	if(ch=='+'){
    		int s;
    		cin>>s;
    		s=s-1;
    		ll val;
    		cin>>val;
    		spread[s]+=val;
    	}
    	else{
    		int s;
    		cin>>s;
    		s=s-1;
    		cout<<spread[s]<<"\n";
    	}
    }
}