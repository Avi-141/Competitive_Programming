#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int r,c,k;
cin>>r>>c>>k;
int top,bottom,left,right;
int visited;

if(r+k>8)
	bottom=8;
else bottom=r+k;

if(r-k<=0)
	top=1;
else top=r-k;

if(c+k>8)
	right=8;
else right=c+k;

if(c-k<=0)
	left=1;
else left=c-k;

visited=(right-left+1)*(bottom-top+1);
cout<<visited<<endl;
}
return 0;
}