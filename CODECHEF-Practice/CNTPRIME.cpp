#include <bits/stdc++.h> 
using namespace std; 

#define MAX 100000001
long int prefix[MAX]; 

void buildPrefix() 
{ 
	bool prime[MAX]; 
	memset(prime, true, sizeof(prime)); 

	for (long int p = 2; p * p <= MAX; p++) { 
		if (prime[p] == true) { 

			for (long int i = p * 2; i <= MAX; i += p) 
				prime[i] = false; 
		} 
	} 
	prefix[0] = prefix[1] = 0; 
	for (long int p = 2; p <= MAX; p++) { 
		prefix[p] = prefix[p - 1]; 
		if (prime[p]) 
			prefix[p]++; 
	} 
} 
 
long long query(long int L, long int R) 
{ 
	return prefix[R] - prefix[L - 1]; 
}  
int main() 
{ 
	buildPrefix(); 
    long int t,N,M;
    cin>>t;
	while(t--)
	{
		cin>>M>>N;
		cout<<query(M,N)<<endl;
	}
	return 0; 
} 