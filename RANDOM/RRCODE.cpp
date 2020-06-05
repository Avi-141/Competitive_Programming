#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {return a<b?a:b;}
void xorop(int& a, int b) { a^=b; }
void andop(int& a, int b) { a&=b; }
void orop(int& a, int b) { a|=b; }
int main () {
    int T;
    cin>>T;
    while(T--) 
    {
        int N, K, Ans;
        cin>>N>>K>>Ans;
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];
        string opr;cin>>opr; 

        auto op=xorop;

        if(opr[0]=='A'){
            op=andop;
            K=min(K,1); }
        else if(opr[0]=='O'){
            op=orop;
            K=min(1, K); }
       else K&=1;
        while(K--)
            for(int i=0; i<N; i++)
                op(Ans, A[i]);
        cout<<Ans<<endl;

    }
}
