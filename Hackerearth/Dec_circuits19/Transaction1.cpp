#include<bits/stdc++.h>
using namespace std;

vector<int> trans;

int NthTransac(int m,int n,int t){
    int i,cnt=0;
    for(i=0;i<t;i++){
        if(trans[i]>=m)
            cnt++;
        if(cnt==n)
            return trans[i];
    }
    
    return -1;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,q,m,n;
    int i,j;
    int minimum=INT_MIN;
    int maximum=INT_MAX;
    scanf("%d %d",&t,&q);
    trans.resize(t);
    for(i=0;i<t;i++){
        minimum=min(minimum,trans[i]);
        maximum=max(maximum,trans[i]);
        scanf("%d",&trans[i]);
    }

    for(j=0;j<q;j++)
    {

        scanf("%d %d",&m,&n);
        if(m<=minimum)
            if(n<t)
               printf("%d\n",trans[n-1]);
            else 
                printf("-1\n");
            else if(m>=maximum+1)
                printf("-1\n");
            else 
                printf("%d\n",NthTransac(m,n,t));
    }
}