#include <bits/stdc++.h>
using namespace std;

    int n,s,p0,p1;
    int main()
    {
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
            if(s[i]=='0') p0++;
        else p1++;
        if(p0==p1) {cout<<2<<endl<<s[0]<<' ';for(int i=1;i<n;i++) cout<<s[i];}
        else cout<<1<<endl<<s;
        return 0;
    }