#include <bits/stdc++.h> 
using namespace std;

const int N = 1000 + 7;
int n, k;
int a[N];

void solve() {
	cin>>n>>k;
	for(int  i=0;i<n;i++)
		scanf("%d", &a[i]);
	int sum = accumulate(a, a + k, 0);
	bool o = false;
	bool e = false;
	for(int  i=0;i<n;i++){
		o |= a[i] % 2 == 1;
		e |= a[i] % 2 == 0;
	}
	if (sum % 2 == 1 || (o && e && k < n))
		puts("Yes");
	else
		puts("No");
}
 
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {	
		solve();
	}
}