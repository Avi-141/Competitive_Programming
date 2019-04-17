#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N  100005

int main()
{
	ios_base::sync_with_stdio(false);
	//int TESTS=1;
	long long  zeck[80],j,i;
	zeck[1]=1;
	zeck[2]=2;
	//ZECKENDORF REPRESENATION OF NUMBERS .
	for(i=3;i<70;i++)
		zeck[i]=zeck[i-1]+zeck[i-2];
	//calculate all fiboannci numbers.
	//THE GAME IS BASED ON FIBONACCI NIM , WHICH USES THE ZECKENDORF REPRESENTATION OF NUMBERS. 
	// REF: SPRAGUE-GRUNDY THEOREM AND zeckONACCI NIM.
	while(1)
	{
		long long  i,j,k,l,m,n;
		cin>>n;
		l=n;
		//base cases.
		if(n==0)
			break;
		if(n==1)
		{
			cout<<"D"<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<"L\n";
			continue;
		}
		//end of base cases.
		if(n>=3)
		{
			for(i=1;i<60;i++)
				if(zeck[i]>=n)
					break;
			k=i;
			if(zeck[i]==n)// if it is a number from the fibonacci sequence .
			{
				cout<<"L\n";
				continue;
			}
			for(;i>=1;i--)
			{
				if(n==zeck[i])
					break;
				if(n>=zeck[i])
					n=n-zeck[i];//remove from the deck.
			}
		}

		cout<<zeck[i]<<endl;
	}
	return 0;
}