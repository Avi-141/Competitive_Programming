    #include <bits/stdc++.h>
    using namespace std;
     
    string X, Y;
     
    int main() {
        
        ios::sync_with_stdio(0);
        cin.tie(NULL), cout.tie(NULL);
     
        int T;
        cin >> T;
     
        while(T--)
        {
            cin >> X >> Y;
     
            reverse(X.begin(), X.end());
            reverse(Y.begin(), Y.end());
     
            int ptr = 0, ans = 0;
     
            while(Y[ptr] == '0')
                ptr++;
            while(X[ptr] == '0')
                ptr++, ans++;
            
            cout << ans << "\n";
        }
     
        return 0;
    }