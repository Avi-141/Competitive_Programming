#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair <char, int> ci;

const int N = 1e4;

bool comp(const ci &a, const ci &b)
{
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;	cin >> T;

	for (int case_no = 1; case_no <= T; case_no++)
	{
		unordered_map <char, int> freq;
		unordered_set <char> chars;

		int U;	cin >> U;

		for (int i = 0; i < N; i++)
		{
			string num, s; cin >> num >> s;

			freq[s[0]] += 1;

			for (auto c: s)	chars.insert(c);
		}

		vector <ci> arr;

		for (auto c: chars) arr.push_back({ c, freq[c] });

		sort(all(arr), comp);

		cout << "Case #" << case_no << ": " << arr.back().first;

		for (int i = 0; i < 9; i++)	cout << arr[i].first;

		cout << "\n";
	}

	return 0;
}