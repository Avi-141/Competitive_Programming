#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

int solve(vector<int> a,vector<int> b){
		int n=a.size();
		int xor_[n];
		int i,count;
		for(i=0;i<n;i++){
			xor_[i]=a[i]&b[i];
			a[i]=a[i]^b[i];
		}
		int max=0;
		count=0;
		for(i=0;i<n;i++){
			if(xor_[i]==1){
				count=1;
				for(int j=i+1;j<n;j++){
					if(a[j]==0)
						break;
					else 
						count++;
				}
				if(count>max)
					max=count;
			}
			if(count>max)
				max=count;
		}
		return max;
}

bool check(vector<int> a,vector<int> b){
		int flag=1;
		int len=a.size();
         
		for(int i=0;i<len;i++){
			if(((a[i]^b[i])==1)|| a[i]==0)
				continue;
			else{
				flag=0;
				break;
			}
		}
		return flag;
}

int main(){
		
		int t,x,n,min,i;
		scanf("%d",&t);
		while(t--){
			string A,B;
			cin>>A;
			cin>>B;
			string z="0";
			if(B.compare(z)==0){
				printf("%d\n",0);
				continue;
			}
			if(B.compare(A)==0){
				printf("%d\n",2);
				continue;
			}
			int maxlen=max(A.size(),B.size());
			vector<int> a(maxlen),b(maxlen);
			x=0;
			for(i=A.length()-1;i>=0;i--)
				a[x++]=A[i]-'0';
			x=0;
			for(i=B.length()-1;i>=0;i--)
				b[x++]=B[i]-'0';

			if(check(a,b)){
				cout<<1<<"\n";
				continue;
			}
			int count=1;
			count+=solve(a,b);
			printf("%d\n",count);;
		}
  }