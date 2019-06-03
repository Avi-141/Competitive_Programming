#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define v vector<int>
#define mp0 make_pair
#define pb push_back
#define mp map<double,long long int>
#define d double


long combi(int n,int k)
{
    long ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

int main()
{


	lli n,k;
	cin>>n>>k;
	int flag-0;
	if(n==2)
		cout<<k*k<<endl;
    else
	cout<<k<<endl;
}
