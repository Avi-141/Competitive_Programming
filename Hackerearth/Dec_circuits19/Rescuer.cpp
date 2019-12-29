#include<bits/stdc++.h>
using namespace std;
#define ld long double

int main(){

   int t;
   cin>>t;
   while(t--){

	 ld x1,x2,y1,y2,v1,v2;
	 cin>>x1>>y1>>x2>>y2>>v1>>v2;
	 ld l=min(x1,x2);
	 ld r=max(x1,x2);
	 ld minn = 1e-9;

	 while(r - l > minn){
		ld low = l + (r - l)/3;
		ld high = r - (r - l)/3;
		   ld ans1=sqrt(abs(low - x1)*abs(low - x1) + y1*y1)/v1 + sqrt(abs(low- x2)*abs(low - x2)+y2*y2)/v2;
		   ld ans2=sqrt(abs(high - x1)*abs(high - x1) + y1*y1)/v1 + sqrt(abs(high - x2)*abs(high - x2)+y2*y2)/v2;
		if(ans1>ans2)
			l = low;
		else
			r = high;
  }
  	ld fin=sqrt(abs(l - x1)*abs(l - x1) + y1*y1)/v1 + sqrt(abs(l - x2)*abs(l - x2)+y2*y2)/v2;
  	//cout<<fixed<<setprecision(6)<<fin<< "\n";
  	cout<<fixed<<setprecision(5)<<fin<< "\n";
 }
}
/*
1
3 -20 3 25 40 5
5.5000

*/