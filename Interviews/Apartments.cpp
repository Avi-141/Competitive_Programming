#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void merge(ll arr[],int mid,int l,int r)
{
	ll sz1=mid-l+1;
	ll sz2=r-mid;


	ll left[sz1],right[sz2];
	for(ll i=0;i<sz1;i++)
	left[i]=arr[l+i];

	for(ll i=0;i<sz2;i++)
	right[i]=arr[mid+i+1];


	ll i,j,k;
	i=0,j=0;
	k=l;
	while(i<sz1&&j<sz2)
	{
	   if(left[i]<=right[j])
	   {
	   arr[k]=left[i];
	   i++;
	   }
	   else if(left[i]>right[j])
	   {
          arr[k]=right[j];
          j++;
	    }
     k++;
     }
    while(i<sz1)
    {
      arr[k]=left[i];
      i++;
      k++;

    }
    while(j<sz2)
    {
      arr[k]=right[j];
      j++;
      k++;
    }
  }

void mergesort(ll arr[],ll l,ll r)
{
  if(l<r)
  {
	ll mid=l+(r-l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);

	merge(arr,mid,l,r);
  }
}


int  main()
{
  ll n,m,k;
  cin>>n>>m>>k;
  ll mem[n],apart[m];
  for(ll i=0;i<n;i++)
  	cin>>mem[i];
  for(ll i=0;i<m;i++)
  	cin>>apart[i];

  mergesort(mem,0,n-1);
  mergesort(apart,0,m-1);
  ll i=0,j=0,count=0;
  while(i<n&&j<m)
  {
  	if(mem[i]+k<apart[j])
  	{
  		i++;

  	}
  	else if(mem[i]>apart[j]+k)
  	{
      j++;
  	}
  	else {
  		i++;
  		j++;
  		count++;
  	}
  }
 cout<<count;
}