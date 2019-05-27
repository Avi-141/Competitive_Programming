#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         string A;
         int s=0,j;
         cin>>A;
         j=A.size();
         if(A.size()==1)
         {
             cout<<A<<endl;
         }
         else
         {
             if(A[0]!='1')
             {
                 for(int i=1;i<A.size();i++)
                 {
                     if(A[i]!='9')
                     {
                         A[i]='9';
                         s=1;
                     }
                 }
                 if(s==1)
                 A[0]=char(int(A[0]) - 1);
             }
             else
             {
                 for(int i=1;i<A.size();i++)
                 {
                     if(A[i]!='0')
                     {
                         j=i;
                         break;
                     }
                 }
                 for(int i=j+1;i<A.size();i++)
                 {
                     if(A[i]!='9')
                     {
                         A[i]='9';
                         s=1;
                     }
                 }
                 if(s==1)
                 A[j]=char(int(A[j]) - 1);
             }
             if(A[0]=='1' && j==A.size() && s==0)
             {
                 string ans="";
                 for(int i=1;i<A.size();i++)
                 {
                    ans=ans + "9";
                 }
                 cout<<ans<<endl;
             }
             else
             cout<<A<<endl;
                 
             
         }
         
    }
    return 0;
}