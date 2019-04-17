#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,A[100005],B[100005],j,t;
    int T,N;
 
    cin>>T;
    while(T--)
    { t=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>A[i];
            B[i]=A[i];
        }
        for(i=0;i<N;i++)
        { 
            if(A[i]==B[i])
           {
            for(j=0;j<N;j++)
            {
               if(i!=j)
                {if(B[j]!=A[i]&&B[i]!=A[j])
                    {
                        int temp=B[i];
						B[i]=B[j];
						B[j]=temp;
                    }
                }
            }
           }
 
        }
         for(i=0;i<N;i++)
         {
           if(A[i]!=B[i])
                t++;
         }
         cout<<t<<"\n";
         for(i=0;i<N;i++)
            cout<<B[i]<<" ";
         cout<<"\n";
 
        }
        return 0;
    }
 
 