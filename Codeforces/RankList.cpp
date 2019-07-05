#include<bits/stdc++.h>
#define ll long long
using namespace std;

    vector<pair<ll,ll> >v;
    map<pair<ll,ll>,ll>m;
    bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
    {
        if(p1.first==p2.first) return p1.second<p2.second;
        return p1.first>p2.first;
    }
    int main()
    {
        int x,y,n,i,j,k,l,b,a;
    	cin>>n>>k;
        for(i=0;i<n;i++) 
        {
            cin>>a>>b;
            v.push_back({a,b});
            m[{a,b}]++;
        }
    	sort(v.begin(),v.end(),cmp);
    	cout<<m[v[k-1]];
    }