#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
int t;
cin>>t;
int l;
for(l=1;l<=t;l++)
{
 lli num;
 cin>>num;
 string temp=to_string(num);
 string str=to_string(num); 
 int len=str.size();
for(int i=0;i<len;i++)
{  
   if(str[i]=='4')
	{  

		str[i]='2';
	}
}
cout<<"Case #"<<l<<":"<<" "<<num<<" "<<change<<endl;
}
}