#include<bits/stdc++.h> 
using namespace std; 
int mindistance(int arr[], int n) 
{ 
	unordered_map<int, int> dict; 

	int min_dist = n; 
	for (int i=0; i<n; i++){

		if (dict.find(arr[i]) == dict.end()){
			dict[arr[i]] = i;
			
		}
		else{
           
		      min_dist = min(min_dist, i - dict[arr[i]]);
                      dict[arr[i]] = i;
		}
	} 

	return min_dist; 
} 

int main() {
 
	int t;
	cin>>t;
	while(t--){
		int n;string s;
		cin>>n;
		cin>>s;
		int arr[n];
		memset(arr,0,sizeof arr);
		for(int i=0;i<n;i++)
			arr[i]=s[i]-'a';
       
        int ans=mindistance(arr,n);
        cout<<n-ans<<"\n";
	}
	
} 
