#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
 
int n;
int a[502];
int b[502];
int main()
{
	//#ifdef ONLINE_JUDGE
        //freopen("inp.txt","r", stdin);
       // freopen("out.txt", "w", stdout);
    //#endif
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool check = 1;
		int zer = 0, one = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(i >= 2 && a[i] < a[i - 1])
				check = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> b[i];
			if(b[i])
				one = 1;
			else
				zer = 1;
		}
		if((zer&&one) || check)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}