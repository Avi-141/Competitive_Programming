#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		int cnt=0;
		fr(i,0,9)
			fr(j,0,9)
			{
				cin>>a;
				if(a<=30) cnt++;
			}
		if(cnt>=60) cout<<"yes\n";
		else cout<<"no\n";		
	}
	
	return 0;
}
