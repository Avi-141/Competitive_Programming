
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0) 

int main()
{
	fast;
	cin.tie(0);
std::cout << std::fixed<<std::setprecision(12);
	int t,cameras;
	cin>>t;
	while(t--)
	{
		cin>>cameras;
		vector <int> xaxis(cameras);
		double xcord,ycord;
		for(int i=0;i<cameras;i++)
		{
			cin>>xaxis[i];
		}
		sort(xaxis.begin(),xaxis.end());
		cin>>xcord>>ycord;

		double x1,x2,angle1,angle2;
		double angle,sum=0,hght1,hght2;

		for(int i=0,j=cameras-1;i<j;i++,j--)
		//pair up;
		//only need to check x coordinates. 
		//The variation with x will maximize the sum.
		{
			x1=xaxis[i];
			x2=xaxis[j];
			hght1=abs(x1-xcord);
			hght2=abs(x2-xcord);
			
			if(xcord<=x2 && xcord>=x1)
			{
				angle1=atan(hght1/ycord);
				angle2=atan(hght2/ycord);
				angle=angle1+angle2;
			}
			else
			{
				angle1=atan(hght1/ycord);
				angle2=atan(hght2/ycord);
				angle=abs(angle1-angle2);
			}
			sum+=angle;
		}
		cout<<sum<<endl;
	}
}
