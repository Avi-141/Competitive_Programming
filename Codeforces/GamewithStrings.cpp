#include<bits/stdc++.h>
using namespace std;

int ans=0;
char a[1000009];
int main(){
	int i=0;
	while(cin>>a[++i]){
		if(a[i]==a[i-1]){
			i-=2;ans++;
		}
	}
	if(ans%2==1) cout<<"Yes";
	else cout<<"No";
	return 0;
}