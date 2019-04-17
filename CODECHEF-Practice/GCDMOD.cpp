#include <stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
/* geeks for geeks function*/
cpp_int power(long long int x, long long int y, long long int p)
{
 cpp_int res=1;
 cpp_int i=x;
   // int res = 1;
       // Initialize result

    i=i%p;

    //x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*i) % p;

        // y must be even now
        y = y>>1; // y = y/2
        i = (i*i) % p;
    }
    return res;
}

 int main()
 {
  long long int t;
  long long int a,b,n,m;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>n;
   cpp_int temp,q;
    long int w,e=1000000007;
   cpp_int z,x,y;
    m=a-b;

    if(m==0)
    {
     z=power(a,n,e);
     x=power(b,n,e);
     y=z+x;
     cout<<y%e<<endl;

}
else
{
  z=power(a,n,m);
  x=power(b,n,m);
  y=z+x;
  q=m;

while(y%q!=0)
{
 temp=q;
 q=y-q*(y/q);
 y=temp;


 if(q==0)
 {
  break;
 }
 }
 q%=e;
 cout<<q<<"\n";
 }
  }
 return 0;
 }
