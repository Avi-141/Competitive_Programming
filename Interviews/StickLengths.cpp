#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void merge(ll  arr[], ll  l, ll  m, ll  r) 
{ 
    ll  i, j, k; 
    ll  n1 = m - l + 1; 
    ll  n2 =  r - m; 
  
    ll  L[n1], R[n2]; 
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back ll o arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
 
void mergeSort(ll  arr[], ll  l, ll  r) 
{ 
    if (l < r) 
    { 
        ll  m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}




int main()
{
	ll n;
	cin>>n;
	ll vec[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
	cin>>vec[i];
	sum+=vec[i];  
     }
	mergeSort(vec,0,n-1);
//for odd
	ll mid=vec[n/2];

    ll cost=0;
	for(ll i=0;i<n;i++)
	{
		cost+=abs(vec[i]-mid);
	}
	ll temp=0;
	if(n%2==0)
	{
     mid =vec[n/2-1];
     for(ll i=0;i<n;i++)
     	temp+=abs(vec[i]-mid);
     cost=min(cost,temp);
	}
cout<<cost;
}