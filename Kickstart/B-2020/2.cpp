#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
 
    ll t;
    cin>>t;
    for(int ii=1;ii<=t;ii++){

    ll n,d;
    cin>>n>>d;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
     arr[n-1]=(d/arr[n-1])*arr[n-1];
     for(int i=n-2;i>=0;i--){
        arr[i]=(arr[i+1]/arr[i])*arr[i];
       }
       cout << "Case #" << ii<< ": ";
       cout<<arr[0]<<"\n";
    }
}