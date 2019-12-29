

    #include<bits/stdc++.h>
    #define ll long long
    #define For(i,st,en) for(ll (i) = (ll)(st); (i) <= (ll)(en); ++(i))
    #define forn(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
    #define clr(x) memset((x), 0, sizeof((x)))
    #define pb push_back
    #define all(x) (x).begin(), (x).end()
    #define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
    #define mp make_pair
    #define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
    using namespace std;
    typedef unsigned long long ull;
    typedef pair<ll, ll> PII;
    typedef pair<ll,long int> PIII;
    typedef vector<ll> VI;
    typedef vector<VI> VVI;
    #define MOD 1000000007
    #define INF 999999999
     
     
    	//	ull  n, k, x, gr = 0;
    	//	cin>>n>>k;
    	//		gr = gr ^ grundy[x][min(x,k)];
     
     
    /*int main()
    {
     
      ull t;
      cin>>t;
      while(t--)
      {
    	ull n,k;
    	cin>>n>>k;
    	if(k==n-1)
    		cout<<"Dishant"<<"\n";
    	else if(n%2==1)
    	{
    		if(k==n-1)
    			cout<<"Dishant"<<"\n";
    		else cout<<"Arpa"<<"\n";
    	}
    	else if(n%2==0)
    	{
    	    
    	    if(2*k>=n&& k!=n-1)
    		{
    			cout<<"Arpa"<<"\n";
    		}
    	    else if(n%12==0&&(k==2||k==3||k==5||k==7||k==11))
    	      cout<<"Dishant"<<"\n";
    	      
    		else if(k==1)
    		{
    			cout<<"Dishant"<<"\n";
    		}
    		else if(n==k)
    		{
    			cout<<"Arpa"<<"\n";
    		}
    		else if(2*k==n-2)
    		{
    			//cout<<"SHH";
    			cout<<"Dishant"<<"\n";
    		}
    		else if(2*k==n-4)
    		{
    			cout<<"Arpa"<<"\n";
    		}
    		    else cout<<"Arpa"<<"\n";
         }
     }
    }
     
    //36 5 
    //36 7 
    //36 11
    //
    //
    //*/
        int main() {
        	ull t;
        	ull n,k;
        	cin>>t;
        	while(t--)
            {
        		cin>>n>>k;
        		if(n%(k+1)==0) printf("Dishant\n");
        		else printf("Arpa\n");
        	}
        }

//Language: C++14
