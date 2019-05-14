#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
lli t;
	cin>>t;
	while(t--)
	{
		lli a,z;
		long long int arr1[10000005];
		lli count1=0,count0=0;
		vector<int>vec;
		
		cin>>a>>z;
	//	lli countmiddle=(a/2)-1;
	//	lli countmids=z-1;

        for(int i=0;i<a;i++)
        {
        	cin>>arr1[i];
        	if(arr1[i]==1)
        	count1++;
        	else count0++;
        }
  
  if(a<=z)
  { 
  for(int i=0;i<count1;i++)
  	cout<<"1"<<" ";
  for(int i=0;i<count0;i++)
  	cout<<"0"<<" ";
 cout<<endl;
}
else if(count1==a)
{
    for(int i=0;i<a;i++)
    cout<<"1"<<" ";
}
else if(count0==a)
{
    for(int i=0;i<a;i++)
    cout<<"0"<<" ";
}
if(z<a){
	labels:
	while(z--)
	{
	
	for(int i=0;i<a;i++)
	{
		if(arr1[i]==0&&arr1[i+1]==1&&i+1!=a)
		{
			arr1[i]=1;
			arr1[i+1]=0;
			i++;
		}

	}
	goto labels;
	}
for(int i=0;i<a;i++)
cout<<arr1[i]<<" ";
cout<<endl;
}


}
}