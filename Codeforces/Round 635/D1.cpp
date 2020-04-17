#include<bits/stdc++.h>
using namespace std;
#define ll long long
//https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/


ll square(ll x){
    return x*x;
}
 
void solve(){
    ll ans;
    int reds, greens, blues;
    cin>>reds>>greens>>blues;
    vector<ll> red(reds);
    vector<ll> green(greens);
    vector<ll> blue(blues);
    for(int i=0; i<reds; ++i){
        cin>>red[i];
    }
    for(int i=0; i<greens; ++i){
        cin>>green[i];
    }
    for(int i=0; i<blues; ++i){
        cin>>blue[i];
    }
    sort(red.begin(),red.end());
    sort(green.begin(),green.end());
    sort(blue.begin(),blue.end());
    int i=0, j=0, k=0;
    ll ans1, ans2, ans3, check;
  
    ans=square(red[0]-green[0])+square(blue[0]-green[0])+square(red[0]-blue[0]);
    while (i<reds-1 || j<greens-1 || k<blues-1){
        ans1=LLONG_MAX;
        ans2=LLONG_MAX;
        ans3=LLONG_MAX;
        if (i<reds-1) ans1=square(red[i+1]-green[j])+square(blue[k]-green[j])+square(red[i+1]-blue[k]);
        if (j<greens-1) ans2=square(red[i]-green[j+1])+square(blue[k]-green[j+1])+square(red[i]-blue[k]);
        if (k<blues-1) ans3=square(red[i]-green[j])+square(blue[k+1]-green[j])+square(red[i]-blue[k+1]);
        check=min(ans1, min(ans2,ans3));
        if (check<ans){
            ans=check;
       
        }
        if (ans1==check) i++;
        else if (ans2==check) j++;
        else k++;
    }
    cout<<ans<<"\n";
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; ++i){
        solve();
    };
    return 0;
}