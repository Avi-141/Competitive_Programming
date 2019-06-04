#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
lli power(lli x, int y) 
{ 
    lli temp; 
    if( y == 0) 
       return 1; 
    temp = power(x, y/2);        
    if (y%2 == 0) 
        return temp*temp; 
    else
    { 
        if(y > 0) 
            return x*temp*temp; 
        else
            return (temp*temp)/x; 
    } 
}   
int main()
{
	lli n,p;
	lli i,j,k;
	lli t;
	cin>>t;
	while(t--)
	{
	  cin>>n>>p;
	  lli rem=n%((n/2)+1);
	  lli same=p*p*p;
	  lli c1=power((p-n),2);
	  lli c2=power((p-rem),2);
	  lli c3=(p-rem)*(p-n);
	  if(n==1||n==2)
	  {
	      cout<<p*p*p<<endl;
	  }
	 else
	  {
	    cout<<c1+c2+c3<<endl;  
	  }
	  
	  /*{
	  cout<<(lli)(pow((p-n),2)+pow((p-rem),2)+(p-rem)*(p-n))<<endl;
	}*/
	  /*else if (n==p)
	  {
	  	cout<<pow((n+1-(n/2)),2)<<endl;
	  }*/
}
}