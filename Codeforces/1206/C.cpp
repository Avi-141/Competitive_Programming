    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define pb push_back
     
     
    int main(int argc, char const *argv[])
    {
    	
    	ll n;
    	cin>>n;
    	vector<ll> a(n+1);
     
        if(n%2==0)
        {
        	cout<<"NO\n";
        }
        else 
        {
        	cout<<"YES\n";
        	for(ll i=1;i<=n;i++)
        	{
        		if(i%2){
        			cout<<2*i-1<<" ";
        			a[i]=2*i;
        		}
        		else if(i%2==0)
        		{
        			cout<<2*i<<" ";
        			a[i]=2*i-1;
        		}
        	}
     
        for(ll i=1;i<=n;i++)
        	cout<<a[i]<<" ";
        }
    	return 0;
    }