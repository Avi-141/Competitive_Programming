#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,zalgo[100000];
    string str;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> str;
		for (int i = 1, l = 0, r = 0; i < n; i++)
		{
			zalgo[i] = max(0, min(zalgo[i - l], r - i));
			while (i + zalgo[i] < n && str[i + zalgo[i]] == str[zalgo[i]])
				zalgo[i]++;
			// z array is being created.
			// credits : codeforces 
			if (i + zalgo[i] > r)
			{
				l = i;
				r = i + zalgo[i];
			}
		}
		int res = 1000000000;
		zalgo[0] = 0;
		for (int i = 0; i < n; i++)
			if (zalgo[i] != 0)
			res = min(res, zalgo[i]);
		if (res == 1000000000)
			cout << str;
		else
	for (int i = 0; i < res; i++)
				cout << str[i];
		cout << '\n';
	}
	return 0;
}