#include <bits/stdc++.h>
using namespace std;

const int N = 0;
int n;
vector < string > v;
set < string > s;
map < int , string > mp;
int main()
{
	cin >> n;
	string z;
	for(int i=0;i<n;i++)
	{
		cin >> z;
		s.insert(z);
	}
	
	mp.clear();
	mp[1] = "1";
	mp[2] = "2";
	mp[4] = "3";
	mp[8] = "4";
	mp[16] = "5";
	mp[32] = "B";
	mp[64] = "G";
	mp[128] = "W";
	mp[256] = "Y";
	mp[512] = "R";
	
	for(set<string>:: iterator it = s.begin();it!=s.end();it++)	v.push_back(*it);
	
	int mn = 10;
	n = v.size();
	for(int i=0;i<1024;i++)
	{
		vector < string > potato;
		potato.clear();
		potato.resize(n , "");
		int tmp = i;
		while(tmp)
		{
			string str = mp[tmp & -tmp];
			tmp = tmp - (tmp & -tmp);
			for(int j=0;j<n;j++)
			{
				if(v[j][0] == str[0] || v[j][1] == str[0])
				{
					potato[j] += str;
				}
			}
		}
		bool ok = true;
		for(int j=0;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(potato[j] == potato[k]) ok = false;
			}
		}
		if(ok) mn = min(mn ,  __builtin_popcount(i));
	}
	
	cout << mn;
}