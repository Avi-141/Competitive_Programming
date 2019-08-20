    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define pb push_back
     
    int main(int argc, char const *argv[])
    {
    	
    	ll n;
    	cin>>n;
    	vector<ll> a(n);
    	ll zero=0,pos=0,flag=0,neg=0;
    	ll sum=0;
    	for(ll i=0;i<n;i++)
    	{
    		cin>>a[i];
    		sum+=abs((abs(a[i]))-1);
    		if(a[i]<0)
    		{
    			neg+=1;
    		}
            if(a[i]==0)
            {
            	flag=1;
            	zero+=1;
            }
         }
         if(neg%2 && flag==0)
         {
         	sum=sum+2;
         }
         cout<<sum<<"\n";
     
    	
    	return 0;
    }