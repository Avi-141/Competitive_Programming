#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll inf=1e9+1;
int s[N],p[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]==-1)s[i]=inf;
		s[p[i]]=min(s[p[i]],s[i]);
	}
	int mark=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==inf)s[i]=s[p[i]];
		else if(s[i]<s[p[i]])mark=1;
		if(mark)break;
		ans+=s[i]-s[p[i]];
	}
	if(mark)printf("-1\n");
	else printf("%I64d\n",ans);
}