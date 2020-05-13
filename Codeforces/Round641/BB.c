#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long 

ll max(ll a,ll b){
	if(a<b)
		return b;
	return a;
}

int main(){

int t;
scanf("%d",&t);
while(t--){
		ll n;
		scanf("%lld",n);
		ll a[n+1],lis[n+1];
		for(ll i=1;i<=n;i++){
		    scanf("%lld",&a[i]);
		    lis[i]=1;
		}
		    ll step;
		    ll max1=1,i,j;
		    for(i=1;i<=n;i++){
		        //step=1;
		        for(j=2*i;j<=n;j+=i)
		        {
		            if(a[j]>a[i]&& lis[j]<lis[i]+1)
		            {
		                lis[j]=lis[i]+1;
		          //      step=j;
		            }
		        }
		    }
		 for(i=1;i<=n;i++)
		   max1=max(max1,lis[i]);

		printf("%lld\n",max1);
    }
}