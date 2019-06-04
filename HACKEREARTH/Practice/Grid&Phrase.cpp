#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int Max=1e3+123;
    
string s[Max];
string saba="saba";
int main()
{
    
    ll n,m;
    ll ans=0;
    cin>>n>>m;
    ll temp=m/4;
    for(int i=0;i<n;i++)
    cin>>s[i];
    for(int i=0;i<n-3;i++){
    for(int j=0;j<m-3;j++){
      bool b=true;
      for(int k=0;k<4;k++){
	if(s[i+k][j+k]!=saba[k])b=false;
      }
      if(b)ans++;
    }
  }
  for(int i=0;i<n-3;i++){
    for(int j=0;j<m;j++){
      bool b=true;
      for(int k=0;k<4;k++){
	if(s[i+k][j]!=saba[k])b=false;
      }
      if(b)ans++;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m-3;j++){
      bool b=true;
      for(int k=0;k<4;k++){
	if(s[i][j+k]!=saba[k])b=false;
      }
      if(b)ans++;
    }
  }
  for(int i=3;i<n;i++){
    for(int j=0;j<m-3;j++){
      bool b=true;
      for(int k=0;k<4;k++){
	if(s[i-k][j+k]!=saba[k])b=false;
      }
      if(b)ans++;
    }
  }
    
    
}