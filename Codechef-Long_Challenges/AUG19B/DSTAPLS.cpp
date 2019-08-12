#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define bint int64_t
#define ld long double
#define MAX 100005

bool isexp(bint  x, bint y) 
{ 
    bint res1 = log(y) / log(x); 
    ld res2 = log(y) / log(x); 
    //cout<<res1<<" "<<res2;
  
   if(res1==res2)
   return true;
  return false;
} 
int main(int argc, char const *argv[])
{
	bint t;
	cin>>t;
    while(t--)
	{

		bint n,k;
		cin>>n>>k;
		bint div=n/k;
		bint ans=div%k;
      
       if(k==1||ans==0)
	   {
			cout<<"NO\n";
		}
		else cout<<"YES\n";
	  }
 }