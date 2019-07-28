#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair


int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
      ll n;
      cin>>n;
      ll state[n];
      //arr(n+1);

      for(ll i=0;i<n;i++)
      	cin>>state[i];
//      for(ll i=1;i<=n;i++)
  //    	arr[i-1]=i;
    ll count=0;  
      bool chaotic=false;
      ll i,j;
      for(i=0;i<n;i++)
      {
      	
       	//ll temp=state[i]-2;
       	ll zero=0;
       	//ll maxx=max(0,temp);

       	if(state[i]-(i+1)>2)
       	{
       		chaotic=true;
       		break;
       	}
       	for(j=max(zero,state[i]-2);j<i;j++)
       	{
       		if(state[j]>state[i])
       			count++;
       	}
       }
       if(chaotic)
       	cout<<"Too chaotic"<<"\n";
       else cout<<count<<"\n";
   }
}
