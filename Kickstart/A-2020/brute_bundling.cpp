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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        vector<string> v;
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            v.pb(s);
        }
          int ans = 0;
          sort(all(v));
          string maxx=v[n-1];
          int max_len=maxx.size();
          for (int l = 1; l <= max_len; l++){
              map<string, int> freq;
              for (auto s : v) {
              string pref = s.substr(0, l);
              if (pref.length() < l) continue;
              freq[s.substr(0, l)]++;
       }
        map<string, int>::iterator itr=freq.begin();
        while (itr!= freq.end())
        ans += (itr->second/ k);
    }
       //for (auto cnt : freq) 
    cout << "Case #" << i << ": " << ans << endl;
  }
}

/*
2
2 2
KICK
START
8 2
G
G
GO
GO
GOO
GOO
GOOO
GOOO
*/

/*1
6 3
RAINBOW
FIREBALL
RANK
RANDOM
FIREWALL
FIREFIGHTER
*/