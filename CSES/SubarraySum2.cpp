//PARTIALLY CORRECT
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
#define ll long long 

void findSubarrays(ll arr[], ll n, ll sum)
{
	// create an empty map of vectors for storing end index of all
	// subarrays with sum of elements so far
	unordered_map<int, vector<int>> map;

	// To handle the case when the subarray with given sum starts
	// from 0th index
	map[0].push_back(-1);

	ll sum_so_far = 0;
    ll count=0;
	// traverse the given array
	for (ll index = 0; index < n; index++)
	{
		// sum of elements so far
		sum_so_far += arr[index];

		// check if there exists at-least one sub-array with given sum
		auto itr = map.find(sum_so_far - sum);
		if (itr != map.end())
		{
			
			count++;
			
		}

		// insert (sum so far, current index) pair into the map of vectors
		map[sum_so_far].push_back(index);
	}
	cout<<count;
}
int main()
{
	ll n,sum;
	cin>>n>>sum;
	ll arr[n];
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	findSubarrays(arr, n, sum);

	return 0;
}