#include <bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;

	bool f = 0;
	while (1)
	{
		if (a == b)
		{
			f = 1;
			break;
		}

		if (a == x || b == y)
			break;

		a %= n;
		a += 1;

		b -= 1;
		if (b <= 0)
			b += n;
	}

	if (f)
		cout << "YES"<<endl;

	else
		cout << "NO"<<endl;

	return 0;
}