#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main()
{
  map<char, string> mp;
 
  mp['0'] = mp['1'] = "";
  mp['2'] = "2";
  mp['3'] = "3";
  mp['4'] = "223";
  mp['5'] = "5";
  mp['6'] = "35";
  mp['7'] = "7";
  mp['8'] = "2227";
  mp['9'] = "2337";
 
  int n;
  string str;
 
  cin>>n>>str;
 
  string res;
 
  for(int i = 0; i < str.size(); ++i)
    res += mp[str[i]];
 
  sort(res.rbegin(), res.rend());
 
  cout<<res;
 
  return 0;
}