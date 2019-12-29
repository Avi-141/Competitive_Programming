
#include<iostream>
using namespace std;

// a^b mod m
long long power(long long a, long long b, long long m)
{
	if (!b) return 1;
	else if (b==1) return a;
	else 
	{
		long long req = power(a, b>>1, m);
		long long ret = (req*req*((b&1LL)?a:1LL))%m;
//		cout << "Power: " << a << ' ' << b << ' ' << m << ' ' << ret << endl;
		return ret;
	}
}
// DONE

long long n; long long m;

// [ 1 p.first  ] ^ power
// [ 0 p.second ]
pair <long long, long long> matrix_power(pair <long long, long long> &p, long long power)
{
	if (power==0LL) return make_pair(0LL, 1LL);
	else if (power==1LL) return p; 
	else
	{
		pair <long long, long long> ret = matrix_power(p, (power>>1));
		ret.first = (ret.first * (1LL + ret.second))%m;
		ret.second = (ret.second*ret.second)%m;
		if (power&1LL)
		{
			ret.first = (p.first + p.second*ret.first)%m;
			ret.second = (ret.second*p.second)%m;
		}
		return ret;
	}
}
// DONE

// (1 + r + r^2 + .. numb terms) mod m
long long gp(long long r, long long numb)
{
	// [1 f(n)] = [1 f(n-1)][1 1]
	//						[0 r]
	// Use matirx exponentiation!!
	if (numb <= 0LL) return 0LL;
	else if (numb == 1LL) return 1LL;
	pair <long long, long long> p = make_pair(1LL, r);
	pair <long long, long long> req = matrix_power(p, numb-1);
	long long ret = (req.first + req.second)%m;
//	cout << "GP: " << r << ' ' << numb << ' ' << ret << endl;
	return ret;
}
// DONE

// (index^index)*(1+index^m+index^2m+...)%m
long long term (long long index)
{
	// numb <= (n - index)/m + 1
	if (index > n) return 0LL;
	long long ret;
	long long first = power(index, (long long)index, m);
	long long second = gp(power(index, m, m), (n-(long long)index)/(long long)m+1LL);
	ret = (first*second)%m;
//	cout << "Term: " << index << ' ' << m << ' ' << ret << endl;
	return ret;
}
// DONE

// (1^1 + 2^2 + 3^3 + ... n^n) mod m
long long ans()
{
	long long ret = 0;
	for (long long i = 1; i < m; i++)
		ret = (ret + term(i))%m;
//	cout << "Ans: " << n << ' ' << m << ' ' << ret << endl;
	return ret;
}
// DONE

int main ()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	long long t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << ans() << endl;
	}
	return 0;
}
// DONE
