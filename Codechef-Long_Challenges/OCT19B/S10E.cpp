#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include<string.h>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

#define ll long long 

void stupidshit(int arr[],int n){
	    int count=0;
	    int five;
        int i,j;
		for(i=n-1;i>=5;i--){
			five=0;
			for(j=i-1;j>=i-5;j--){
			if(arr[i]<arr[j]){
				five++;
			}

			if(five==5){
				 count++;
			}
		}
	}
	int zero=arr[0];
	int fif=arr[4],chouka=arr[3],theen=arr[2],dusra=arr[1];
	if(fif<chouka && fif<theen && fif<dusra&& fif<zero)
		count++;
	if(chouka<theen && chouka<dusra && chouka<zero)
		count++;
    if(theen<dusra && theen<zero)
    	count++;
    if(dusra<zero)
    	count++;

   cout<<count+1<<"\n";
 }

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		stupidshit(arr,n);
    }
return 0;
}