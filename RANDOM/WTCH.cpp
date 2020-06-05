#include<iostream>
using namespace std;
int main()
{
    int t;
    char A[1000000];
    cin>>t;
    for(long long int j=0;j<t;j++)
    {
        long long int n,count=0;
        cin>>n;
        
        for(long long int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        
        for(long long int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(A[i+1]=='0')
                {
                    A[i]='1';
                    count++;
                }
            }
            else if(i==(n-1))
            {
                if(A[i]=='0')
                {
                    if(A[i-1]=='0')
                    {
                        A[i]='1';
                        count++;
                    }
                }
            }
            else
            {
                if(A[i]=='0')
                {
                    if((A[i-1]=='0')&&(A[i+1]=='0'))
                    {
                        A[i]='1';
                        count++;
                    }
                }
            }

        }
        cout<<count<<"\n";
    }
    return 0;

}
