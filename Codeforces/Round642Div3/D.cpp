#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
#define all(x)  x.begin(),x.end()
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;
const int MAX=200010;

pair<int, int> a[MAX];
void rec(int left, int right) {

	if (left>right) 
		return;
	int mid = (left+right-1)/2;
	//odd 
	if ((right-left+1)&1) 
		mid = (left+right)/2;
	a[mid].first = -(right-left+1);//for order
	
	//like merge sort
	rec(left, mid-1);
	rec(mid+1, right);
}

int main() {

	int t, n, b[MAX];

	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
	fast_io

	for(scanf("%d", &t); t--; )
	{
		scanf("%d", &n);
		rec(1, n);
		for(int i=1; i<=n; i++) 
			a[i].second=i;
		sort(a+1, a+n+1);
		for(int i=1; i<=n; i++) 
			b[a[i].second]=i;
		for(int i=1; i<=n; i++) 
			printf("%d ", b[i]); 
			puts("");
	}
}