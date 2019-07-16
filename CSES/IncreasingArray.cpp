#include<bits/stdc++.h>
#include<cstring>
typedef long long ll;
using namespace std;
int main(){
	ll n,diff; //dif is difference from the last max that has occurred
	ll turns=0; ll max=0; //Turns is sum of all the dif
	cin>>n;
	ll x[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		if(x[i]>max){diff=0;max=x[i];}else{diff=max-x[i];}; 
		//Check if max -> reset dif & update max, if not -> find dif
		turns+=diff;										
		//Update turns
	}
	cout<<turns;
}



