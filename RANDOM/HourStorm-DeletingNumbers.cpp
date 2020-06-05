#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define v vector<int>



/*long long int getClosest(long long int val1, long long int val2,  
               long long int target) 
{ 
    if (target - val1 >= val2 - target) 
        return val2; 
    else
        return val1; 
} 

 
long long int findClosest(long long int arr[], long long int n, long long int target) 
{ 
    if (target <= arr[0]) 
        return arr[0]; 
    if (target >= arr[n - 1]) 
        return arr[n - 1]; 
  
 
    long long int i = 0, j = n, mid = 0; 
    while (i < j) { 
        mid = (i + j) / 2; 
  
        if (arr[mid] == target) 
            return arr[mid]; 
  
        if (target < arr[mid]) { 
  
            if (mid > 0 && target > arr[mid - 1]) 
                return getClosest(arr[mid - 1], 
                                  arr[mid], target); 
  
  
            j = mid; 
        } 
        else { 
            if (mid < n - 1 && target < arr[mid + 1]) 
                return getClosest(arr[mid], 
                                  arr[mid + 1], target); 
            // update i 
            i = mid + 1;  
        } 
    } 
    return arr[mid]; 
} */



int main()
{

long long int n,k;
cin>>n>>k;
long long int sum=0,sum1=0;
long long int pos;
v arr(n+1);
long long int arr2[n+1];
for(int i=1;i<=n;i++){
	cin>>arr[i];
	sum+=arr[i];
    arr2[i]=arr[i];
}
sort(arr2+1,arr2+n+1);
long long int mid=(n+1)/2;
long long max=0;
long long i;
if(k==n-1)
cout<<arr2[n];
else
{
for(i=mid;i>=1&&i>=(mid-k+1);i--)
{
	if(arr[i]>max)
		max=arr[i];
}
for(i=mid;i<=n&&i<=(mid+k-1);i++){
			if(arr[i]>max)
				max=arr[i];
		}

cout<<max<<endl;
}
}