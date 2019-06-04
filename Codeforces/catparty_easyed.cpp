#include <bits/stdc++.h>
using namespace std;
int a[100001];
int u[11];
int main() {
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int j=1;j<=n;j++) {
        u[a[j]]++;
        int one=0,sum=0,maxx=0,s=0,flag=0;
        for(int i=1;i<=10;i++) {
            if(u[i]) {
                flag++;
                if(u[i]==1) one++;
                if(u[i] > maxx) maxx=u[i];
            }
        }
        for(int i=1;i<=10;i++) {
            if(u[i]==maxx) sum++;
        }
        for(int i=1;i<=10;i++) {
            if(u[i]==maxx-1) s++;
        }
        if(one == flag) ans=j;
        if(sum==1 && s==flag-1) ans=j;
        if(one==1 && sum==flag-1) ans=j;
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{

    long int a[100010],b[1000010],n,s=1,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]++;
        b[a[x]]++;
        if(a[x]*b[a[x]]==i && i!=n) s=i+1;
        else if(a[x]*b[a[x]]==i-1) s=i;
    }
    cout<<s;
}