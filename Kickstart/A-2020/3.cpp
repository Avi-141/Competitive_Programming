#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;


// halving doesnt always work. 
//will not always yield minimum.
int main(){
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
		ll n,k;
		cin>>n>>k;
		ll arr[n];
		vector<ll> diff;
		priority_queue<ll> pq;
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		for(ll i=1;i<n;i++){
			diff.pb(arr[i]-arr[i-1]);
            pq.push(arr[i]-arr[i-1]);
		}
	    while(k>0){
	    	ll top=pq.top();
	    	cout<<top<<"\n";
	    	pq.pop();
	    	k--;
	    	ll temp1=(ll)ceil(top/2.0);
	    	ll temp2=(ll)floor(top/2.0);
	    	cout<<temp1<<" "<<temp2<<"\n";
	    	pq.push(temp1);
	    	pq.push(temp2);
	    }
	    ll ans=pq.top();
		cout << "Case #" << i<< ": ";
		cout<<ans<<"\n";
		
	}
}

/*For this test case, we cannot perform such direct splits because repeatedly splitting the maximum difference into halves is not optimal. For example, given a sequence [2, 12] and K = 2, splitting into halves will result in [2, 12] → [2, 7, 12] → [2, 7, 9, 12]. This way, the difficulty would be 5. However, if we perform [2, 12] → [2, 5, 12] → [2, 5, 8, 12], the difficulty would be 4. This clearly demonstrates that continuous halving of the maximum difference is sub-optimal. Okay, so how do we do this?

Consider the i-th adjacent pair of training sessions with an initial difference di. If we want to insert some number of training sessions in between this pair such that the maximum difference among those is at most a certain value, let's say doptimal, then how many training sessions can be inserted in between? The answer to this is ceiling(di / doptimal)-1. Let's call that k'i. Doing this for all N-1 adjacent pairs in the given array would give us k'[1, ..., N-1]. Let's denote k'sum = k'1+k'2+ ....+k'N-1. From the constraints, we can insert at most K training sessions. Therefore, we need to make sure k'sum ≤ K while minimizing doptimal as much as possible.

If you observe, doptimal can lie anywhere between [1, max(di)] (1 ≤ i ≤ N-1). Linear search would be to check every value here starting from 1 and output the first value that satisfies the above condition. A quicker way to do this is using binary search. On closer observation, you can see that increasing the value of doptimal decreases the value of ceiling(di / doptimal)-1 and hence smaller is the value of k'sum. Therefore, we can perform a binary search in the range [1, max(di)] to find the least value of doptimal that makes k'sum ≤ K. That is our answer.

Since the max(di) could be as much as 109, we might have to search [1, 109] making time complexity of the solution is O(log(109)*N).*/



/*
correct code which passes all cases


#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N];

bool check(int x)
{
	int reqd = 0;
	for(int i = 1; i + 1 <= n; i++)
	{
		int diff = a[i + 1] - a[i];
		reqd += (diff - 1) / x;
		if(reqd > k)
			return 0;
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	int tc = 0; 
	while(t--)
	{
		tc++;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = binsearch(1, 1e9);
		cout << "Case #" << tc << ": " << ans << endl;
 	}	
	return 0;
}
*/