#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll  gcd(ll  a, ll  b)
{
  return b == 0 ? a : gcd(b, a % b);
}

vector<ll > tobinary(ll  n)
{
  vector<ll > bin;
  while (n > 0)
   {
    bin.push_back(n % 2);
    n /= 2;
  }
  reverse(bin.begin(), bin.end());
  return bin;
}

ll  solve(ll  n)
 {
  vector<ll> a = tobinary(n);
  ll  fone = -1;
  for (ll  i = 0; i < a.size(); i++) {
    if (a[i] == 1) {
      fone = i;
      break;
    }
  }
  vector<ll > b(a);
  ll  ones = 0;
  for (ll  i = 0; i < b.size(); i++) 
  {
    if (i < fone) 
    {
      b[i] = 0;
      continue;
    }
    b[i] = !a[i];
    ones += !a[i];
  }
  if (ones == 0) 
  {
    ll  ld = 1;
    for (ll  i = sqrt(n); i > 1; i--) 
    {
      if (n % i == 0) 
      {
        ld = max(i, n / i);
      }
    }
    b = tobinary(ld);
  }
  ll  m = 0;
  for (ll  i = b.size() - 1; i > -1; i--) 
  {
    m += b[i] * pow(2, b.size() - 1 - i);
  }
  return gcd(n ^ m, n & m);
}

int main() {
  
  ll  q;
  cin >> q;
  vector<ll> a(q);
  for (ll  i = 0; i < q; i++)
       cin >> a[i];

     for (auto val: a) {
    cout << solve(val) << endl;
  }
}