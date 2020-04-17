/*input
5
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
2 2 2
1 2
5 4
6 7
2 2 2
1 2
3 4
6 7
3 4 1
3 2 1
7 3 3 4
6
*/
 
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll ret = 6e18;
 
ll calc(ll r, ll g, ll b) {
	return (r-g)*(r-g) + (g-b)*(g-b) + (b-r)*(b-r);
}
 
vector<int> neighbors (int x, set<int>& s) {
	auto it = s.lower_bound(x);
	vector<int> ret;
	if(it != s.end()) {
		ret.emplace_back(*it);
		if(next(it) != s.end())
			ret.emplace_back(*next(it));
	}
	if(it != s.begin())
		ret.emplace_back(*prev(it));
	return ret;
}
 
void check(set<int> &ar, set<int> &ag, set<int> ab) {
	for(auto it1 : ar) {
		ll r = it1;
		vector<int> G = neighbors(r, ag);
		vector<int> B = neighbors(r, ab);
		for(auto x : G) {
			vector<int> tmp = neighbors(x, ab);
			B.insert(B.end(), tmp.begin(), tmp.end());
		}
		for(auto g : G)
			for(auto b : B)
				ret = min(ret, calc(r, g, b));
	}
}
 
void run() {
	int nr, ng, nb, i, j, k;
	cin >> nr >> ng >> nb;
	set<int> ar, ag, ab;
	ret = 6e18;
	for(i=0; i<nr; i++) {
		int x;
		cin >> x;
		ar.insert(x);
	}
	for(i=0; i<ng; i++) {
		int x;
		cin >> x;
		ag.insert(x);
	}
	for(i=0; i<nb; i++) {
		int x;
		cin >> x;
		ab.insert(x);
	}
	check(ar, ag, ab);
	check(ag, ab, ar);
	check(ab, ar, ag);
	cout << ret << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);		
	int t = 1;
	cin >> t;
	while(t--)
		run();
}