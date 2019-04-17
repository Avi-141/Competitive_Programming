#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int r=0;
        vector<string> jain(n);
        vector<long long int> c(32,0);
        for(int ii=0;ii<n;ii++)
        {
            cin>>jain[ii];
            int sum=0,a=0,e=0,i=0,o=0,u=0;
            
            for(int j=0;j<jain[ii].size();j++)
            {
                if(jain[ii][j]=='a' && a==0)
                {
                    a=1;
                    sum+=16;  // bitmasks powers of 2 
                }
                if(jain[ii][j]=='e' && e==0)
                {
                    e=1;
                    sum+=8;
                }
                if(jain[ii][j]=='i' && i==0)
                {
                    i=1;
                    sum+=4;
                }
                if(jain[ii][j]=='o' && o==0)
                {
                    o=1;
                    sum+=2;
                }
                if(jain[ii][j]=='u' && u==0)
                {
                    u=1;
                    sum+=1;
                }

            }
            c[sum]++;
        }
        if(c[31]!=0)
            r+=c[31]*(c[31]-1)/2;  //nc2 pairs
        
        for(int j=0;j<32;j++) 
        {
            for(int k=j+1;k<32;k++)
            {
                if( c[j]!=0 && c[k]!=0 && (j|k)==31)
                    r+=c[j]*c[k];
            }
            
        }
    
        cout<<r<<endl;
    }
    return 0;
}
