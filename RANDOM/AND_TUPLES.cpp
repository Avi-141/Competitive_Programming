#include<stdio.h>
#include<map>
using namespace std;
map<long long,long long> m;
long long calc(long long n)
{
    if(m[n]!=0){
        return m[n];
    }
    if(n<=1){
       m[n]=1;
        return 1;
    }
    if(n<=3){
        m[n]=2;
        return 2;
    }
    if(n%2==1){
        m[n] = (calc((n/2))%1000000009+calc((n/2) - 1)%1000000009)%1000000009;
        return m[n];
    }
    if(n%2==0){
        m[n] = (calc((n/2))%1000000009 +calc((n/2) - 1)%1000000009 + calc((n/2)-2)%1000000009)%1000000009;
        return m[n];
    }
    return m[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        int k;
        cin>>k>>n;
        if(k==3){
            cout<<((n/2)+1)%1000000009<<endl;
        }
        else{
        cout<<calc(n);
        }
    }
}