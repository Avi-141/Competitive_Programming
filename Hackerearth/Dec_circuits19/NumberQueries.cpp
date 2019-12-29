#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
	ll n,q;
	cin>>n>>q;
	ll vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	sort(vec.begin(),vec.end());

	int offset=0;
	for(ll i=0;i<q;i++){
		int t;
		cin>>t;
		if(t==1){
			ll x;
			cin>>x;
			auto curr=lower_bound(vec.begin(),vec.end(),x+offset);
			ll it=curr-vec.begin();
			//cout<<curr-vec<<"lower bnd index\n";
			if(it>=n/2){
				for(ll i=it;i<n;i++)
					vec[i]-=x;
			}else{
				offset+=x;
				///cout<<"Offset\t"<<offset<<"\n";
				for(ll i=0;i<it;i++)
					vec[i]-=x;
			}
			//cout<<"Index\t"<<it<<"\n";
			if(it==0||it==n||vec[it-1]<=vec[it])
				continue;
			sort(vec.start(),vec.end());
		}
		else if(t==2){
            ll l,r,x;
            cin>>l>>r>>x;
            l+=offset;
            r+=offset;
            auto curr=lower_bound(vec.begin(), vec.end(),l);
           // cout<<curr-vec<<"lower bnd type 2 index\n";
            ll it=curr-vec.begin();
            ll i=it+x-1;
            //cout<<"new index type2\t"<<i<<"\n";
            if(i>=n||vec[i]>r)
            	cout<<l-offset<<"\n";
            else
            	cout<<vec[i]-offset<<"\n";
		}
	}	
}