#include<bits/stdc++.h>
#define lli long long int;
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
 	lli n;
 	cin>>n;
 	string str;
 	cin>>str;
 	lli len=str.length();
 	for(int i=0;i<len;i++)
 	{ 
 		if(str[i]=='E')
 			str[i]='S';
 		if(str[i]=='S')
 			str[i]='E';

 	}

cout<<str<<endl;

 	}
 }