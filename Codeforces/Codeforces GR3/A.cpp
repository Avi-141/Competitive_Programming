#include<bits/stdc++.h>
#define uint unsigned long int
using namespace std;

    int main()
    {
        uint a,b,ab ;
        cin>> a >> b >> ab ;
        if(a==b)
        {
            cout<<a+b+(ab *2);
        }
        else if(a>b)
        {
            cout<<(b*2)+(ab *2)+1;
        }
        else if(b>a)
        {
            cout<<(a*2)+(ab *2)+1;
        }
    }