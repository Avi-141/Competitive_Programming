#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200002
#define pb push_back

 
vector<int> primes;
unordered_map<int, int> k_cnt, current_map, cnts[MAX];

void sieve()
{

	int prime[MAX];

	prime[0] = prime[1] = 1;

	for(int i = 2; i < MAX; i++)

		if(prime[i] == 0)

			for(int j = i * 2; j < MAX; j += i)

				if(prime[j] == 0)

					prime[j] = i;

	for(int i = 2; i < MAX; i++)

		if(prime[i] == 0)

		{

			prime[i] = i;

			primes.pb(i);

		}

}

 

ll countSubarrays(int* arr, int n, int k){

	if(k == 1)
		return (1LL * n * (n + 1)) / 2;

	vector<int> k_primes;

	for(auto p : primes)

		while(k % p == 0)

		{

			k_primes.pb(p);

			k /= p;

		}

	if(k > 1)

		k_primes.pb(k);

	for(auto num : k_primes)

		k_cnt[num]++;

	int l = 0, r = 0;

	ll ans = 0;

	while(r < n)

	{

		for(auto& it : k_cnt)

		{

			int p = it.first;

			while(arr[r] % p == 0)

			{

				current_map[p]++;

				cnts[r][p]++;

				arr[r] /= p;

			}

		}

		int flag = 0;

		for(auto& it : k_cnt)

		{

			int p = it.first;

			if(current_map[p] < k_cnt[p])

			{

				flag = 1;

				break;

			}

		}

		if(!flag)

		{

			ans += n - r;

			for(auto& it : k_cnt)

			{

				int p = it.first;

				current_map[p] -= cnts[l][p];

			}

			l++;

		}

		else

			r++;

	}

	return ans;

}

 

int main(){
	int n, k;

	cin>>n>>k;

	int arr[n];
    for(int i = 0; i < n; i++)cin>>arr[i]; 
    	sieve();
    cout<<countSubarrays(arr, n, k);

	return 0;

}