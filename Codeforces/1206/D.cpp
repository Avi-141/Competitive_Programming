    #include <iostream>
    #include <algorithm>
    #include <fstream>
    #include <vector>
    #include <deque>
    #include <assert.h>
    #include <queue>
    #include <stack>
    #include <set>
    #include <map>
    #include <stdio.h>
    #include <string.h>
    #include <utility>
    #include <math.h>
    #include <bitset>
    #include <iomanip>
    #include <complex>
     
    using namespace std;
     
    #define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
    #define debug(...) fprintf(stderr, __VA_ARGS__)
    #define mp make_pair
    #define x first
    #define y second
    #define pb push_back
    #define SZ(x) (int((x).size()))
    #define ALL(x) (x).begin(), (x).end()
     
    template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
    template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
    template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
    template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }
     
    typedef long long LL;
    #define int long long
    const int N = (int) 1e5 + 5, K = 130, mod = (int) 0;
    int a[N], d[K][K];
    int32_t main() {
        int m, n = 0;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x) a[n++] = x;
        }
        if (n >= K - 1) {
            cout << 3 << endl;
            return 0;
        }
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y) {
                d[x][y] = 1e9;
                if (x != y && (a[x] & a[y])) {
                    d[x][y] = 1;
                }
            }
        int res = 1e9;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < k; ++i)
                for (int j = 0; j < k; ++j)
                    if (i != j) {
                        res = min(res, d[i][j] + d[i][k] + d[j][k]);    
                    }
            for (int i = 0; i <= k; ++i)
                for (int j = 0; j <= k; ++j)
                    d[k][i] = d[i][k] = min(d[k][i], d[k][j] + d[j][i]);
            for (int i = 0; i <= k; ++i)
                for (int j = 0; j <= k; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        cout << (res > K ? -1 : res) << '\n';
                    
        
    }
     
     
     


    /*#include <bits/stdc++.h>
    using namespace std;
     
    vector<vector<bool> > matrix;
    int min_weight;
     
    void bfs(int start, int end){
    	bool visited[matrix.size()];
    	for(int i = 0; i < matrix.size(); i++) visited[i] = false;
    	queue<pair<int,int> > q;
    	visited[start] = true;
    	q.push(make_pair(start,0));
    	while(q.size()){
    		int top = q.front().first;
    		int dis = q.front().second;
    		q.pop();
    		for(int i = 0; i < matrix.size(); i++){
    			if(matrix[top][i] == false || visited[i]) continue;
    			if(i == end){
    				min_weight = min(min_weight, dis + 2);
    				return;
    			}
    			else{
    				q.push(make_pair(i,dis + 1));
    				visited[i] = true;
    			}
    		}
    	}
    }
     
    int main() {
    	long long int n,k;
    	cin >> n;
    	vector<long long int> arr;
    	for(int i = 0; i < n; i++){
    		cin >> k;
    		if(k != 0) arr.push_back(k);
    	}
    	if(arr.size() > 128){
    		cout << 3 << endl;
    	}
    	else{
    		min_weight = INT_MAX;
    		vector<bool> temp;
    		for(int i = 0; i < arr.size(); i++){
    			temp.push_back(0);
    		}
    		for(int i = 0; i < arr.size(); i++){
    			matrix.push_back(temp);
    		}
    		for(int i = 0; i < arr.size(); i++){
    			for(int j = i + 1; j < arr.size(); j++){
    				if( (arr[i]&arr[j]) != 0){
    					matrix[i][j] = true;
    					matrix[j][i] = true;
    				}
    			}
    		}
    		for(int i = 0; i < arr.size(); i++){
    			for(int j = i + 1; j < arr.size(); j++){
    				if(matrix[i][j]){
    					matrix[i][j] = 0;
    					matrix[j][i] = 0;
    					bfs(i,j);
    					matrix[i][j] = 1;
    					matrix[j][i] = 1;
    				}
    			}
    		}
    		if(min_weight == INT_MAX){
    			cout << -1 << endl;
    		}
    		else{
    			cout << min_weight << endl;
    		}
    	}
    	return 0;	
    }*/

    /*    include <bits/stdc++.h>
    using namespace std;
    #define int long long
    #define pb push_back
    const int N = 2e5 + 5, MOD = INT_MAX;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    vector<int> v;
    int n;
    vector<int> adj[150];
    vector<pair<int, int> > edge;
    int dist[150];
    queue<pair<int, int> > q;
     
    int bfs(int source, int desti) {
        for(int i = 0; i < n; i++)  dist[i] = INT_MAX;
        while(!q.empty()) q.pop();
     
        q.push({source, 0});
        dist[source] = 1;
     
        while(!q.empty()) {
            int u = q.front().first, d = q.front().second;
            q.pop();
            for(auto v : adj[u]) {
                if(u == source and v == desti)  continue;
                if(dist[v]  == INT_MAX) {
                    q.push({v, d + 1});
                    dist[v] = d + 1;
                }
            }
        }
        return dist[desti];
    }
     
    signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
     
        int tmp;
        cin>>n;
        while(n--) {
            cin>>tmp;
            if(tmp != 0)  v.pb(tmp);
        }
        n = v.size();
        if(n > 122) {
            cout<<3<<endl;
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)  continue;
                int res = v[i] & v[j];
                if(res > 0) {
                    adj[i].pb(j);
                    adj[j].pb(i);
                    edge.pb({i, j});
                }
            }
        }
        for(auto e : edge) {
            int u = e.first, v = e.second;
            int res = bfs(u, v);
            if(res != INT_MAX)  ans = min(ans, res + 1);
        }
        if(ans == INT_MAX)  ans = -1;
        cout<<ans<<endl;
        
        return 0;
    }

*/