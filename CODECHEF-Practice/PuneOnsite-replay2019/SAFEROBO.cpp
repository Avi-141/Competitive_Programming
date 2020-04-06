#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int sa,sb;
		cin>>sa>>sb;
        int xa,xb;
		for(int i=0;i<s.size();i++){
			if(s[i]=='A') xa=i;
			if(s[i]=='B') xb=i;
		}
        int d=xb-xa;
        if(d%(sa+sb)==0){
        	cout<<"unsafe"<<"\n";
        	continue;
        }
        cout<<"safe"<<"\n";
		/*while(true){
			int flag=0;
			if(xa+sa<s.size())
				xa=xa+sa,flag=1;
			if(xb-sb>=0) xb=xb-sb,flag=1;
			if(xa==xb){
				cout<<"unsafe"<<"\n";
		        continue;
			}
			if(flag==0)
				break;

		}
	cout<<"safe"<<"\n";*/
 }
}