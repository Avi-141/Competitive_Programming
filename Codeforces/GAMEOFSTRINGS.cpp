#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> sta;
	int n = s.length(), count = 0;
	for (int i = 0; i < n; i++)
	{
		if (sta.empty())
			sta.push(s[i]);
		else if (s[i] == sta.top())
		{
			sta.pop();
			count ++;
		}
		else
			sta.push(s[i]);
	}

	if (count%2 == 0)
		cout << "No";
	else
		cout << "Yes";
}