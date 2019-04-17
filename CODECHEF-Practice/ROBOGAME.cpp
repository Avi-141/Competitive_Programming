#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,flag,j;
	cin>>t;
	char robot[50] ;
	while(t--){
		flag=0;
	cin>>robot;
	for(int i=0; robot[i]!='\0';i++){
		for(j=i+1;robot[j]!='\0';j++)
	 	{
	 	int l=isdigit(robot[i]);
	 	int r=isdigit(robot[j]);
	 	if(l&&r)
		{
		int sum=robot[i]-'0'+robot[j]-'0';
		int dots=j-i; // we make them collide , thats how the world works //doesn't it
		if(dots<=sum)
			flag=1;
		}
	}
}
	if(flag==1)
	cout<<"unsafe\n";
	else
	cout<<"safe\n";
	}
	return 0;
	}