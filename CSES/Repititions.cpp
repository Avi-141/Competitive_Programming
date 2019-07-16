#include<bits/stdc++.h>
#include<cstring>
typedef long long ll;
using namespace std;

ll maxRepeating(string str) 
{ 
    ll n = str.length(); 
    ll count = 0; 
    ll cur_count = 1; 
    for (ll i=0; i<n; i++) 
    { 
        if (i < n-1 && str[i] == str[i+1]) 
            cur_count++; 
        else
        { 
            if (cur_count > count) 
            { 
                count = cur_count; 
               
            } 
            cur_count = 1; 
        } 
    } 
  
  return count;
} 
  

int main()
{
    string s;
    cin>>s;
    cout<<maxRepeating(s);
}