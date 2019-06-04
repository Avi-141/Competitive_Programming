#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main()
{

lli n;
cin>>n;
lli arr[i];
lli count=0;
for(int i=0;i<n;i++)
{
   cin>>arr[i];
	if(arr[i]<0)
     arr[i]=-arr[i];
}

sort(arr,arr+n);

for(int i=0;i<n;i++){
	temp=2*arr[i]; //symmetry for x,-x y,-y
	count+=upper_bound(arr,arr+n,temp)-arr-i-1;
}
cout<<count<<endl;
}