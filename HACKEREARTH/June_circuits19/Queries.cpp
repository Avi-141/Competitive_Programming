#include<bits/stdc++.h>
#define ll long long 
#define bigint int64_t
#define pb push_back
#define ld long double
#define ull unsigned long long 
using namespace std;
#define MAXN 100005

ull nn, t[4*MAXN];
ld pref[MAXN+2];
void init()
{
pref[MAXN]={0};
}
void build(ull a[], ull v, ull tl, ull tr) 
{
    if (tl == tr) 
    {
        t[v] = a[tl];
    } else {
        ull tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}


void update(ull v, ull tl, ull tr, ull pos, ull new_val) { //v==1,tl==pos,tr==pos
    //if (tl == tr) 
    //{ since tl=tr always,(we are updating only one position)
        t[pos] = t[pos]*new_val;
    } /*else {
        ull tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }*/
//}

ld prefsum(ld store[],ull n,ld prefix[]){

  
  prefix[0]=store[0];
  for(ll i=1;i<n;i++)
  {
    prefix[i]=prefix[i-1]+store[i];
  }
  ld sum=0;
  for(ll i=0;i<n;i++)
  {
    sum+=prefix[i];
  }
  sum=sum/2;

  return sum;


}


int main()
{

 init();
 
 ull n,m;
 cin>>n>>m;
 ull query[n+2];
 ld store[n+2];
 for(ll i=1;i<=n;i++){
    cin>>query[i];
    store[i]=log10(query[i]);
}

build(query,1,0,n-1);


for(ll i=1;i<=m;i++)
{
    ll pos,val,type;

    cin>>type;
    if(type==2)
    {
      ld ans=prefsum(store,n,pref);
      ll idx=upper_bound(pref,pref+n,ans)-pref;
      cout<<idx<<"\n";
    }
    if(type==1)
    {
     cin>>pos>>val;
     update(1,pos-1,pos-1,pos-1,val);
     store[pos-1]=store[pos-1]*val;
    }

 }
}