#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
    int main()
    {
    	int sz;
    	cin>>sz;
    	int a[sz];
    	bool flag=true;
    	for(int i=0;i<sz;i++)
    	{
    		cin>>a[i];
    	}
    	sort(a,a+sz);
    	swap(a[sz-1],a[sz-2]);
    	for(int i=1;i<sz;i++)
    	{
    	//cout<<(a[(i-1)%t]+a[(i+1)%t])<<endl;
    		if((a[(i-1)%sz]+a[(i+1)%sz])<=a[i])
    		flag=false;
    	}
    	if(flag==true)
    	{
    		cout<<"YES"<<endl;
    			for(int i=0;i<sz;i++)
    		cout<<a[i]<<" ";
    	}
    	else
    	cout<<"NO"<<endl;
    }