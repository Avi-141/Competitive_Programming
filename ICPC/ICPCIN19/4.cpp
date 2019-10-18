#include <bits/stdc++.h>
using namespace std;
 
int pos[(1 << 20)];
int ans[1000006];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
 
    while(t--){
        memset(pos, -1, sizeof pos);
 
        int n, k;
        cin >> n >> k;
 
        string s;
        cin >> s;
 
//        vector< string > vs{};
//        vector< int > bm{};
        string now;
 
        for(int i = 0; i < k; ++i){
            cin >> now;
 
//            vs.push_back(now);
            int b = 0;
 
            for(auto &c: now){
                b |= (1 << (c - 'a'));
            }
 
//            bm.push_back(b);
            if(pos[b] == -1){
                pos[b] = i + 1;
            }
        }
 
        for(int i = (1 << 20) - 1; i >= 0; --i){
            if(pos[i] == -1){
                for(int j = 0; j < 20; ++j){
                    if((1 & (i >> j)) == 0 and pos[i | (1 << j)] != -1){
                        pos[i] = pos[i | (1 << j)];
                        break;
                    }
                }
            }
        }
 
 
        int l = 0;
        int cnum = 0;
        int cval = -1;
        int nextnum;
 
        for(int i = 0; i < n; ++i){
            nextnum = cnum | (1 << (s[i] - 'a'));
            if(pos[nextnum] == -1){
                for(int j = l; j < i; ++j){
                    ans[j] = cval;
                }
                cnum = (1 << (s[i] - 'a'));
                cval = pos[(1 << (s[i] - 'a'))];
                nextnum = 0;
                l = i;
            } else {
                cval = pos[nextnum];
                cnum = nextnum;
            }
        }
 
        if(l < n){
            for(int j = l; j < n; ++j){
                ans[j] = cval;
            }
        }
 
        for(int i = 0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << "\n";
 
    }
 
    return 0;
}

/* greedy approach to assign the largest segment till it could be served by a single element.
Now, how do we know if there is a single element that can serve a particular set. 
I used dp with bitmasks where each bit represents the characters that could be written.
Now, use dp where each dp[i] is -1 if that set can’t be served by a single element (i is the bitmask).
Else, it is the index of the element that can serve the subset.*/