#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long 
#define uos unordered_set
#define bint int64_t
#define all(x) x.begin(),x.end()
ll popcount(ll x)
{
    ll temp=x;
    x -= (x >> 1) & 0x5555555555555555;
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f;
   ((x * 0x0101010101010101) & 0xffffffffffffffff ) >> 56;
   return (x%2);
  
}

int main(int argc, char const *argv[])
{
	
	ll test;
	cin>>test;
	while(test--)
	{
	    
	   	ll odd=0,even=0;
	   	uos<ll> s1,s2;    
        uos<long long>::iterator it;
        ll q;
		cin>>q;
   for(ll i=0;i<q;i++){
			ll num;
			cin>>num;
	if(s1.find(num)==s1.end())
	{
  	 if(popcount(num)==1)
  	 {
			odd++;}
		else {
			even++;}
			
  for(it = s1.begin(); it != s1.end(); ++it){
  	ll itr=(*it);
  	ll ans=itr^num;
  	if(popcount(ans)==1)
  	{
  		odd++;}
  	else {
  		even++;}
  		
  	s2.insert(ans);}
  s1.insert(all(s2));
  s1.insert(num);
    } 
  cout<<even<<" "<<odd<<"\n";
	}
	}
}