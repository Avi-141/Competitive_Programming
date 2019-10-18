#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int l[n], r[n], v[n];
        for(int i=0; i<n; i++)
            cin>>l[i]>>r[i]>>v[i];
        
        set<int> a[n];
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(v[i] == v[j]) {
                    if((l[j] >= l[i] && l[j] <= r[i]) || 
                    (r[j] >= l[i] && r[j] <= r[i]) || 
                    (l[i] >= l[j] && l[i] <= r[j]) || 
                    (r[i] >= l[j] && r[i] <= r[j])) {
                        a[i].insert(j);
                        a[j].insert(i);
                    }
                }
            }
        }
        string ans = "YES";
        
        for(int i=0; i<n; i++) {
            if(a[i].size() > 1) {
                for(auto j: a[i]) {
                    for(auto k: a[j]) {
                        if(a[i].find(k) != a[i].end()) {
                            ans = "NO";
                            goto end;
                        }
                    }
                }
            }
        }
end:        
        cout<<ans<<endl;
    }
    return 0;
}