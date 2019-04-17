#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n;

int MIN(int a,int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int MAX(int a,int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int i;
    int test;

    cin>>t;

    while(t--)
    {
        cin>>n;

        int pos = 0;
        int neg = 0;

        for (i=1;i<=n;i++)
        {
            int a;

            cin>>a;

            if (a < 0)
                neg++;
            else
                pos++;
        }

        if (neg == 0)
            cout<<pos<<" "<<pos<<endl;
        else if (pos == 0)
           cout<<neg<<" "<<neg<<endl;
        else
            cout<<MAX(neg,pos)<<" "<<MIN(neg,pos)<<endl;
    }

    return 0;
}