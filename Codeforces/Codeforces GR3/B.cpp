#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int n, m, k; 
        ll ta, tb;
        cin >> n >> m >> ta >> tb >> k;
        ll a[n];
        ll b[m];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<m; i++){
            cin >> b[i];
        }
        if(min(n,m)<=k){
            cout << -1 << endl;
            return 0;
        }
        int point = 0;
        ll ans = 0LL;
        for(int i = 0; i<=k; i++){
            ll getb = a[i]+ta;
            while(point<m && b[point]<getb){
                point++;
            }
            if(point+(k-i)>=m){
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans,b[point+(k-i)]+tb);
        }
        cout << ans << endl;
    }