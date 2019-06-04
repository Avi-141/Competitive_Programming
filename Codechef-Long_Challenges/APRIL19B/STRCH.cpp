#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull t;
    cin >> t;
    while(t--) {
        ull n;
        cin >> n;
        string s;
        cin >> s;
        char x;
        cin >> x;
          ull count=0;
          ull perm;
              perm=(n+1)*(n);
              perm=perm/2;
        for(ull i = 0; i < n; i++) 
        {
            if(s[i]!=x)
            {
            count++;
            }
        else if(s[i]==x)
        {
            count=(count+1)*count;
            count=count/2;
            perm=perm-count;
            count=0;
         
        }
       }
     if(count==0)
    cout<<perm<<endl;
    else{
        count=(count+1)*count;
        count=count/2;
        cout<<perm-count<<endl;
    }
    }
    }