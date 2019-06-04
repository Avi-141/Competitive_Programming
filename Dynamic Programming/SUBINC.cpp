#include <bits/stdc++.h>
#define lli long long
#define int ll
#define mod 1000000007
using namespace std;

int test_cases, N;
int A[100010];

main(){
	ios::sync_with_stdio(0);
	cin>>test_cases;
	while(test_cases--) {
		cin>>N;
		for(int i = 0; i < N; i++)
		     cin>>A[i];
		int answer = 1, next = 1;
		for(int i = 1; i < N; i++) {
			next++;
			if(A[i] < A[i-1])
				next = 1;
			answer += next;
		}
		cout<<answer<<endl;
	}	
}
