#include<bits/stdc++.h>
using namespace std;
     
    const int N = 7005, NMAX = 2e5;
     
    queue <int> Q;
    int d[N], n, m, bp[NMAX], LV[N], L[N], R[N], val[N], liminf[N], limsup[N];
    bool POW[NMAX];
     
    int main() {
    	cin >> n >> m;
    	for (int i = 0; (1 << i) < NMAX; ++i)
    		POW[1 << i] = true;
    	for (int i = 1; i < NMAX; ++i)
    		bp[i] = bp[i - 1] + POW[i];
    	for (int i = 0, type; i < m; ++i) {
    		cin >> type;
    		if (type == 1)
    			cin >> LV[i] >> L[i] >> R[i] >> val[i];
    		else {
    			LV[i] = -1;
    			cin >> L[i] >> R[i];
    			int level = L[i], nod1 = R[i], nod2 = R[i];
    			for (int j = level; j <= n; ++j) {
    				liminf[j] = nod1;
    				limsup[j] = nod2;
    				nod1 += bp[nod1-1];
    				nod2 += bp[nod2-1] + POW[nod2];
    			} 
    			set <int> s;
    			for (int j = 0; j < i; ++j)
    				if (LV[j] != -1 && LV[j] >= level) {
    					int lim1 = max(liminf[LV[j]], L[j]);
    					int lim2 = min(limsup[LV[j]], R[j]);
    					if (lim1 <= lim2)
    						s.insert (val[j]);
    				}
    			cout << s.size() << "\n";
    		}
    	}
    }