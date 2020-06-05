#include<bits/stdc++.h>
using namespace std;
int main()
{ 
int t;
long long int n;
int k;
cin>>t;
while(t--)
{
cin>>n>>k;
if(n<k) cout<<0;

else if(k==1)
cout<<2*n;
else if(n==k)
{
cout<<2<<endl;
}
else if(n>=2*k-1&&n>1)
{
cout<<4*(n-k+1)%((long long)(pow(10,9)+7));}
else
{ 
cout<<(2*n)%((long long)(pow(10,9)+7));}
}
}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{ 
int t;
long long int n;
int k;
cin>>t;
while(t--)
{
cin>>n>>k;
//if(n<k)
//cout<<0;
if(n==k){
cout<<2<<endl;}
else if(k==1)
{
cout<<(2*n)%((long long)(pow(10,9)+7))<<endl;
}
//right till here . 
else if (n<=4)
{
cout<<(4*(n-k+1))%((long long)(pow(10,9)+7));
}
else if(n>5){
cout<<(4*(n-k+1)+(2*(n-1)))%((long long)(pow(10,9)+7));}
}
}
*/