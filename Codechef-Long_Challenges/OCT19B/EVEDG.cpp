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
#define all(x) x.begin(),x.end()
 
ll bfs(list<ll> *adj,bool visited[],ll u,vector<ll> &temp,ll deg[]){
        ll total=0;
        queue<ll > q;
        list<ll >::iterator it;
        q.push(u);
        visited[u]=true;
        temp.push_back(u);
        total+=deg[u];
        while(!q.empty()){
            ll front=q.front();
            q.pop();
            for(it=adj[front].begin();it!=adj[front].end();it++){
                if(!visited[*it]){
                    visited[*it]=true;
                    q.push(*it);
                    temp.push_back(*it);
                    total+=deg[*it];
                }
            }
        }
return total;
}
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        ll n,M;
        int odd_degree,K;
        int flag=0,complete=0;
        cin>>n>>M;

        if(M%2==0){
            for(ll i=0;i<M;i++){
            ll u,v;
            cin>>u>>v;
        }
        cout<<1<<"\n";
        for(ll i=0;i<n;i++)
            cout<<1<<" ";
        cout<<"\n";
        continue;
       }
    list<ll > *adj = new list<ll >[n+1]; 
    vector<vector<ll> >g(n+1); 
    ll degree[n+1]={0};
    
    for(ll i=0;i<M;i++){
        ll u,v;
        cin>>u>>v;
        degree[v]++;
        degree[u]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    odd_degree=0;
    ll edge_count,c1=0,c2=0;
    ll val;
    vector<ll> odd;
    bool ok=false;
    bool visited[n+1]={false};
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
             vector<ll> temp;
             edge_count=bfs(adj,visited,i,temp,degree);
             edge_count/=2;
             if(edge_count%2==1 && !ok){
                for(ll j=0;j<temp.size();j++){
                    val=temp[j];
                    if(degree[val]%2==1){
                        odd_degree=val;
                        ok=true;
                        break;
                    }
                }
                if(!ok)
                    odd=temp;
             }
         }
     }
     K=2;
     if(!ok){
        K=3;
        c1=odd[0];
        c2=odd[1];
     }
     cout<<K<<"\n";
     for(ll i=1;i<=n;i++){
        if(K==2 && i==odd_degree)
            cout<<2<<" ";
        else if(K==3 && c1==i)
            cout<<2<<" ";
        else if(K==3 && c2==i)
            cout<<3<<" ";
        else cout<<1<<" ";

     }
     cout<<"\n";
 }
}

