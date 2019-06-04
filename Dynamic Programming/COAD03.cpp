#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
#define pb push_back
#define v vector<int>

lli dp(lli i,lli n){
    lli mov[n+1];
    mov[1]=1;
    mov[2]=2;
    for(int i=3;i<=n;i++){
        if(i%2==0){
            mov[i]=min(mov[i/2]+2,mov[i-1]+1);
            
        }
        else{
            mov[i]=mov[i-1]+1;
        }
    }
    return mov[n];
}
int main()
{
	
int t;
cin>>t;
while(t--)
{

 int n;
 cin>>n;
 lli ans=dp(1,n);
cout<<ans<<endl;
}
}