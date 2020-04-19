#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
 
 
int main(){
 
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i<< ": ";
        
        int n;
        cin>>n;
        vector<ll> arr(n);
        int count=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
                count++;
        }
        cout<<count<<"\n";
    }
}
      