#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    

    ll  q;
    cin >> q;
    ll  a[323][323];    
    while(q--)
    {
        ll  n;
        cin >> n;
        
        for(ll  i=0;i<2*n;i++)
            for(ll  j=0;j<2*n;j++)
                cin >> a[i][j];
            
        ll  sum = 0;
        for(ll  i=0;i<n;i++){
            for(ll  j=0;j<n;j++){

                sum += max(max(a[i][j], a[i][2*n-j-1]), max(a[2*n-i-1][j], a[2*n-i-1][2*n-j-1]));
            }
        }
        
        cout << sum << endl;
    }
    return 0;
}