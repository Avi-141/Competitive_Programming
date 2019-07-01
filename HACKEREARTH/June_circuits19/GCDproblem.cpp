    #include<bits/stdc++.h>
    #define bint int64_t
    #define For(i,st,en) for(bint  (i) = (bint )(st); (i) <= (bint )(en); ++(i))
    #define forn(i, n) for(bint  (i) = 0; (i) < (bint )(n); ++(i))
    #define clr(x) memset((x), 0, sizeof((x)))
    #define pb push_back
    #define abint (x) (x).begin(), (x).end()
    #define remin(a, b) ((a) = (((a) > (b)) ? (b) : (a)))
    #define mp make_pair
    #define fori(it, a) for(auto (it) = (a).begin(); (it) != (a).end(); ++(it))
    using namespace std;
    typedef long double ld;
    typedef unsigned long long ull;
    typedef pair<bint , bint > PII;
    typedef vector<bint > VI;
    typedef vector<VI> VVI;
    #define MODD 1000000007
    #define INF 999999999
    #define MAX 100000 + 5
    #define ll long long
   
   

ll mpow(ll n, ll p, ll m) 
{
	if(!p) return 1; 
	else if(p & 1) return ((__int128)n * mpow(n, p-1, m)) % m;
	else 
	{
		ll v = mpow(n, p/2, m); 
		return ((__int128)(v*v)) % m;
	}
}

     
    // Returns nCr % p. In this Lucas Theorem based program, 
    // this function is only caull ed for n < p and r < p. 
    ull  nCrModpDP(ull  n, ull  r, ull  p) 
    { 
    	// The array C is going to store last row of 
    	// pascal triangle at the end. And last entry 
    	// of last row is nCr 
    	ull  C[r+1]; 
    	memset(C, 0, sizeof(C)); 
     
    	C[0] = 1; // Top row of Pascal Triangle 
     
    	// One by constructs remaining rows of Pascal 
    	// Triangle from top to bottom 
    	for (ull  i = 1; i <= n; i++) 
    	{ 
    		// Fiull  entries of current row using previous 
    		// row values 
    		for (ull  j = min(i, r); j > 0; j--) 
     
    			// nCj = (n-1)Cj + (n-1)C(j-1); 
    			C[j] = (C[j] + C[j-1])%p; 
    	} 
    	return (__int128)(C[r]); 
    } 
     
    // Lucas Theorem based function that returns nCr % p 
    // This function works like decimal to binary conversion 
    // recursive function. First we compute last digits of 
    // n and r in base p, then recur for remaining digits 
    ull  nCrModpLucas(ull  n, ull  r, ull  p) 
    { 
    // Base case 
    if (r==0) 
    	return 1; 
     
    // Compute last digits of n and r in base p 
    ull  ni = n%p, ri = r%p; 
     
    // Compute result for last digits computed above, and 
    // for remaining digits. Multiply the two results and 
    // compute the result of multiplication in modulo p. 
    return ((((__int128)nCrModpLucas(n/p, r/p, p))%p) * // Last digits of n and r 
    		((__int128)(nCrModpDP(ni, ri, p)))% p)%p; 
    		

    		}
    		// Remaining digits 
  
     
     
     
    ull  combi(ull  n,ull  k)
    {
        ull  ans=1;
        if(k>n)
        	return 0;
        	
        k=k>n-k?n-k:k;
        ull  j=1;
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


    /*bool isPrime(int n) 
    { 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
    } */
    bool prime[MAX]; 
    void SieveOfEratosthenes() 
    { 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    ull n=MAX;
  
    memset(prime, true, sizeof(prime)); 
  
    for (ull p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            
            for (ull i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
   } 
    /*bool isPrime(ull n)
    {
	if(n<2) return false;
	for(ull i=2;i<100000;++i) 
		if(n%i==0) return false;
	ull i = rand()%(n-1)+1;
	if(mpow(i,n-1,n)!=1) 
		return false;
	return true;
    }*/
    int mobius(ull  N)  
    { 
        
        SieveOfEratosthenes();
        if (N == 1) 
            return 1; 
      
        
        ull  p = 0; 
        for (ull i = 1; i <= N; i++) { 
            if (N % i == 0 && prime[i]==true) { 
      
               
                if (N % (i * i) == 0) 
                    return 0; 
                else
      
                    p++; 
            } 
        } 
      
        // Aull  prime factors are contained only once 
        // Return 1 if p is even else -1 
        return (p % 2 != 0)? -1 : 1; 
    }  
     
    ull  ans(ull  n)
    {
         	
     
    	ull  p = 1000000007; 
        
    		ull  ret=0;
            ull  i=1;
    	while(n/i>=4)
    	     {
     
    		   ull  temp=0;
    		   //cout<<mobius<<" ";
               temp=mobius(i)*nCrModpLucas(n/i,4,p);
               ret+=temp;
               i+=1;
               }
     
       return (__int128)(ret);
    }
     

    int main()
    {	

    	
    	ull  p = 1000000007; 
    	
    	ull  t;
    	cin>>t;
    	while(t--)
    	{
    		ull  n;
    		cin>>n;
    		bint sum=0,temp=0;
            ull  i=1;
            while(n/i>=4)
            {
            	temp=0;
            	temp=(ans(n/i))*(mpow(i,4,p));
            	sum+=temp;
            	i+=1;
            }
            sum=sum%p;
    		cout<<sum<<"\n";
    	}
    }

//Language: C++