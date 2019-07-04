// this is not my code 
// simplest solution i found    

    #include <bits/stdc++.h>
    using namespace std;
    const int N = 1e5 + 9, M = 1e7 + 9;
    const int Msqrt=int(sqrt(M));
    vector<int> d[M];
    pair<int, int> a[N];
    int n, k;
    int main()
    {
    	scanf("%d%d", &n, &k);
    	for (int i = 0; i < n; ++i)
    	{
    		scanf("%d", &a[i].first), a[i].second = i;
    		for (int j = 2, e = a[i].first; j * j <= e; ++j)
    			if (a[i].first % j == 0)
    			{
    				for (d[j].push_back(i); a[i].first % j == 0;)
    					a[i].first /= j;
    				if (d[j].size() == k)
    				{
    					for (auto t : d[j])
    						printf("%d ", t + 1);
    					return 0;
    				}
    			}
    	}
    	sort(a, a + n);
    	for (int i = 0; i < k; ++i)
    		printf("%d ", a[n - i - 1].second + 1);
    }