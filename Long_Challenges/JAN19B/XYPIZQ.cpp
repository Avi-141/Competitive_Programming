#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define lli long long int
lli GCD(lli u, lli v)
{
    lli shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v)
        {
            lli t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}
int main()
{
  lli test;
  lli n,x,y,z,t;
  cin>>test;
  while(test--)
  {
     cin>>n>>t>>x>>y>>z;
     lli den=2*n+1;
     lli num;
     lli div;
     if(t==1&&y==0)
     {
      num=1;
     }
      else if(t==1&&y!=0)
      {
      if(x>y&&y>z)
      {
        num=(2*n)+2-y;
       }
      else if(x>y&&y<z)
      {
        num=y+1;
      }
      else if(x<y&&y>z)
      {
        num=y-1;
      }
      else if(x<y && y<z)
      {
        num=(2*n) -y;
      }
     }
    else if(t==2||t==4)
     {
      if((x>y&&y>z)||(x<y&&y<z))
      {
     num=(2*n)+1-(2*y);
     }
    }
     else if(t==3)
     {
       if(x>y&&y>z)
       {
        num=(2*n)-y;
       }
       else if(x>y&&y<z)
       {
         num=y+1;
         }
       else if(x<y&&y<z)
       {
         num=(2*n)+2-y;
       }
       else if(x<y&&y>z)
       {
        num=y-1;
       }
    }
 div=GCD(num,den);
 cout<<(num/div)<<" "<<(den/div)<<"\n";
 }//  EOW
 }//  EOM