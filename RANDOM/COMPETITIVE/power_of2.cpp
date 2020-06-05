#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	unsigned int n,bit;
	cout<<"enter any number: ";
	cin>>n;
	int count=0;
	int arr[2];
	for(int i=31;i>=0;i--)
	{
		bit =(n&(1<<i))>>i;
		if(bit!=0)
		{
			count++;
			if(count<3)
			{
				arr[count-1]=i;
			}
			else
			{
				cout<<"incorrect input\n";
				exit(0);
			}
			//arr[count]=i;
		}
	}
	cout<<"x="<<arr[0]<<"\t y="<<arr[1]<<endl;
	return 0;
}