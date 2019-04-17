#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define LL long long 
using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
    long long num;
    int flag;
    cin>>num;
    long long quo=(num-1)/26;
    long long  mod=(num-1)%26;
    if(mod==0)
    {
     flag=1;
     cout<<(long long)(pow(2,quo))<<" "<<0<<" "<<0<<endl;
     }
      else if(mod>=2&&mod<=9)
    {
     flag=2;
     cout<<0<<" "<<(long long)(pow(2,quo))<<" "<<0<<endl;
     }
      else if(mod>=10&&mod<=25)
    {
     flag=3;
     cout<<0<<" "<<0<<" "<<(long long)(pow(2,quo))<<endl;
     }
     else
     {
         cout<<(long long)(pow(2,quo))<<" "<<0<<" "<<0<<endl;
     }
    
   }
   }