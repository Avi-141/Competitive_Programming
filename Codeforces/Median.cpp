#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 100000


int main(){
        ll  i,j,n,a[MAXN+5],x,count;
        cin>>n>>x;
        for (i=0; i<n; i++)
            cin>>a[i];
        count=0;
        sort(a,a+n);
        while (a[(n-1)/2]!=x)
        {
            a[n++]=x;
            sort(a,a+n);
            count++;
        }
        cout<<count;
    }
    