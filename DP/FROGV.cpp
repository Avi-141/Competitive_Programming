//this code uses the concept :frogs which can communicate are on the same component of the graph . 
#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<ctype.h>

#define size 100005
#define mod 1000000007 
#define ll long long 
#define ull unsigned long long 

using namespace std;

struct arr
{
    int val;
    int ind;
}a[size];

bool comp(const arr &lhs, const arr &rhs)
{
    return lhs.val<rhs.val;
}

int main()
{ 
    int p,k,n,i,u,v;
    int compo, component[size]={};
    cin>>n>>k>>p;
    
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i].val);
    a[i].ind=i+1;
    }
    
    sort(a,a+n,comp);
    
    compo=1;
    
    component[a[0].ind]=1;
    
    for(i=1;i<n;i++)
    {
        if(a[i].val-a[i-1].val<=k)
        component[a[i].ind]=compo;
        else
        component[a[i].ind]=++compo;
    }
    
    
    while(p--)
    {
        cin>>u>>v;
        
        if(component[u]==component[v])
        puts("Yes");
        else
        puts("No");
    }
    
    return 0;
}