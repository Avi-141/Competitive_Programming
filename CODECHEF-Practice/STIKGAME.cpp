#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,count=0,i,j,k;
    long a[2000];
    while(cin>>n)
    {
    if(n==0)    break;
    count=0;
        for(i=0;i<n;i++)
        scanf("%ld",&a[i]); 
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(a[i]+a[j]<a[k])
                    count++;
                    if(a[i]+a[k]<a[j])
                    count++;
                    if(a[j]+a[k]<a[i])
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
