#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 100005

int main()
{
    
    ll test;
    cin>>test;
while(test--)
{

     string str;
     cin>>str;
     ll len=str.size();
  
     ll count=0;
     for(ll i=0;i<len;i++)
     {
        if(str[i]=='1')
            count++;
     }
     if(count%2==1)
        cout<<"WIN\n";
     else cout<<"LOSE\n";

}
}