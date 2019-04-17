#include<bits/stdc++.h>
using namespace std;
double precision = 1e-4;

int main()
{

  long long dh,dl,dr,k;
  cin >> dh >> dl >> dr >> k;
  while(dh!=0 || dl!=0 || dr!=0 || k!=0)
  {
    double start = 0;
    double end = dr*1.0;
    double ans=-1.0;
    for(int i=0;i<100;i++)
    {
      double x = (start+end)/2.0;
      double dist = x+precision;
      double x1 = sqrt(x*x + dh*dh*1.0) + k*sqrt((dr-x)*(dr-x) + dl*dl*1.0);
      double x2 = sqrt(dist*dist + dh*dh*1.0) + k*sqrt((dr-dist)*(dr-dist) + dl*dl*1.0);
    
      if(x1<x2)
      	{
      		ans=x;
      		end=x;
      	}
      else
      {
      	ans=dist;
      	start=dist;
      }
    }
    double final = sqrt(ans*ans + dh*dh*1.0) + sqrt((dr-ans)*(dr-ans) + dl*dl*1.0);
    cout << final << endl;
    cin >> dh >> dl >> dr >> k;
  }
  
  return 0;
}