#include<bits/stdc++.h>
using namespace std;
#define chefing long long int 
const int MAX_CHAR = 26; 


int commonCharacters(vector<string> &str, int n,int count) 
{ 
	bool prim[MAX_CHAR]; 
	memset(prim, true, sizeof(prim)); 
	for (int i = 0; i < n; i++) {
		bool sec[MAX_CHAR] = { false };  
		for (int j = 0; str[i][j]; j++) { 
			if (prim[str[i][j] - 'a']) 
				sec[str[i][j] - 'a'] = true; 
		} 
		memcpy(prim, sec, MAX_CHAR); 
	} 
	for (int i = 0; i < 26; i++) {
		if (prim[i]) {
			count++;
		}
	}
return count;
} 
int main()
{
	
chefing t,n;
chefing i;
cin>>t;
while(t--)
{
  cin>>n;
 std::vector<string> str;
 string ip;
 for(int i=0;i<n;i++)
 { 
 	cin>>ip;
 	str.push_back(ip);
 }
 int ret=commonCharacters(str,n,0);
 cout<<ret<<endl;
}
}
 