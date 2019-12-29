#include<bits/stdc++.h>
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define out(x) cout<<x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define forloop(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define GREATEST_COMMON_DIVISOR(x,y) __gcd(x,y)
#define f first 
#define s second
#define dd double
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int long long n,m,i,j,k,l,w;
    cin>>n>>m;
    int long long x[n],y[n],x1[m],y1[m]; 
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(i=0;i<m;i++){
        cin>>x1[i]>>y1[i];
    }
    int long long num[n]={0};
    l=0;
    for(i=0;i<m;i++){
        k=0;
        for(j=n-1;j>=0;j--){
            if(abs(y[j]-y1[i])<=x1[i]-x[j]){
                k++;
                w=j;
            }
            if(k>1){
                break;
            }
        }
        if(k==1&&num[w]==0){
            l++;
            num[w]++;
        }
    }
    
    
    cout<<n-l<<endl;
}