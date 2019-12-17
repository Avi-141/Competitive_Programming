#include<bits/stdc++.h>
using namespace std;


#define ll long long 
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
int main(int argc, char const *argv[]){
	
 
    int t;
    cin>>t;
    while(t--){
    	vector<pair<int,int>> vec;
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++){
    		int p,s;
    		cin>>p>>s;
    		if(p>=9)
    			continue;
    		
    	    vec.pb(mp(p,s));
     }
     sort(all(vec));
     for(int i=0;i<vec.size();i++){
     	for(int j=i+1;j<vec.size();j++){
     		if(vec[i].first==vec[j].first){
     			if(vec[i].second<vec[j].second)
     				vec[i]={0,0};
     			else 
     				vec[j]={0,0};
     		}
     	}
     }

    int sum=0;


    for(int i=0;i<vec.size();i++)
    	sum+=vec[i].second;
    cout<<sum<<"\n";
    }

}