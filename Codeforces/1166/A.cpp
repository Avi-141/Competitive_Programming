#include<bits/stdc++.h>
#define lli long long int
#define vtr vector<int>
#define mp make_pair
#define pb push_back 
using namespace std;

int main()
{
lli n;
cin>>n;
string str;
int arr[26],arr1[26];
int temp,temp1,temp2;
char f[26]={0};
char s;
for(int i=0;i<n;i++)
{
	cin>>str;
	 s=(str.front());
	f[s-'a']++;
}
for(int i=0;i<26;i++)
{
    temp=ceil(f[i]/(double)2);
    arr[i]=temp;
    f[i]=f[i]-temp;
    arr1[i]=f[i];
}
int store=0;
for(int i=0;i<26;i++)
{
    
    temp1=(arr[i]*(arr[i]-1))/2;
    temp2=(arr1[i]*(arr1[i]-1))/2;
    if(temp1>0)
      store=store+temp1;
     if(temp2>0)
      store=store+temp2;
}
cout<<store<<endl;
}