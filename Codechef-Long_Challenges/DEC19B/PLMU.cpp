#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()



int main(int argc, char const *argv[])
{
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int zr=0,tw=0;
		int f1=0,f2=0;
		vector<ll>vec(n);
		for(int i=0;i<n;i++){
			cin>>vec[i];
			if(vec[i]==0)
				zr++;
			else if(vec[i]==2)
				tw++;
		}
		if(tw==1)
			f1=1;
		if(zr==1)
			f2=1;
		if(f1==1 && f2!=1){
			cout<<(zr*(zr-1))/2<<"\n";
			continue;
		}
		if(f2==1 && f1!=1){
			cout<<(tw*(tw-1))/2<<"\n";
			continue;
		}
		if(tw==1&&zr==1){
			cout<<0<<"\n";
			continue;
		}

		ll sum=(tw*(tw-1))/2+(zr*(zr-1))/2;
        cout<<sum<<"\n";
    }

	return 0;
}