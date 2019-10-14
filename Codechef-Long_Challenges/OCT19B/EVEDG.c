#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bint int64_t
#define ll long long 
#define cout(x) printf("%lld\n",x)
#define print(x) printf("%lld\t",x)


void iseven(ll n){
			cout(1);		
			for(int ver=1; ver<=n; ver++) 
				cout(1);
			printf("\n");
}


int main(){
	ll  t;
	scanf("%lld",&t);
	while(t--){
        ll  n,m,x,y;
		scanf("%lld %lld",&n,&m);		
		ll degree[n+1];
		memset(degree,0,sizeof(ll)*(n+1));

		for(int ver=1; ver<=m; ver++) {
		    scanf("%lld %lld",&x,&y);		
			degree[x]++;
			degree[y]++;
		}	
		if(m%2==0){
			iseven(n);
			continue;
		}
		ll  flag = -1;
		for(int ver=1; ver<=n; ver++) {
			if(degree[ver]%2 == 1) {
				flag = ver;
				break;
			}
		}
		if(flag == -1) {
			cout(3);
			for(int ver=1; ver<=n; ver++) {
				if(ver == x) 
					print(3);
				else if(ver == y)
					print(2);
				else
					print(1);
			}
			printf("\n");
		}
		else {
			cout(2);
			for(int ver=1; ver<=n; ver++) {
				if(ver == flag) 
					print(2);
				else
				    print(1);
			}
		printf("\n");
		}
   }
  return 0;
}