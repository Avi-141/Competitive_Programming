#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

const ull MOD=1000000007;

ull powr(ull base,ull exp){

	ull res=1;
	while(exp>0){
		if(exp&1)
			res=((res%MOD)*(base%MOD))%MOD;
		exp=exp>>1;
		base=((base%MOD)*(base%MOD))%MOD;
	}
  return res%MOD;
}

int main()
{
	ull  t;
	cin>>t;
	while(t--){
		ull  n;
		string A,B;
		ull  az=0,a1=0,bz=0,b1=0;
		ull ans;
		cin>>n;
		cin>>A>>B;

		for(ull  i=0;i<n;i++){
			if(A[i]=='1')
				a1++;
			else 
				az++;
		}
		for(ull  i=0;i<n;i++){
			if(B[i]=='1')
				b1++;
			else 
				bz++;
		}
        
	    ull  maxones=min(az,b1)+min(a1,bz);
	    ull  minones=n-(min(bz,az)+min(a1,b1));
	    ull  lo=min(minones,maxones);
	    ull  hi=max(minones,maxones);

	    ull table[n+1];
	    memset(table,0,sizeof table);
	    table[0]=1;
	    table[1]=1;
	    ull rv=0;
	    for(ull i=2;i<=n;i++)
	       table[i]=((table[i-1]%MOD)*(i%MOD))%MOD;

	   for(ull i=lo;i<=hi;i+=2){

          ans=(table[i]*table[n-i])%MOD;
          ans=powr(ans,MOD-2);
          ans=(table[n]*ans)%MOD;
          rv=((rv%MOD)+(ans%MOD))%MOD;

	   }

	   cout<<rv<<"\n";
    }
	//return 0;
}