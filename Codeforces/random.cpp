#include<bits/stdc++.h>
using namespace std;

#define print(a) cout << a << endl
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

const int N = 1e5 + 10;

map<pair<int,int>,set<long long> >mp;
int x[N],y[N];

int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}


int main(){
   __;
   int n;
   cin >> n;
   long long res = 0;
   long long total = 0;
   
   
   for(int i=0;i<n;i++){
       cin >> x[i] >> y[i];
   }
   
   for(int i=0;i<n-1;i++){
       for(int j=i+1;j<n;j++){
           int a = y[i]-y[j];
           int b = x[i]-x[j];
           
           int d = gcd(a,b);
           a/=d;
           b/=d;
           
           pair<int,int>slope = make_pair(a,b);
           
           if(a<0 || (a==0 && b<0)){
               a = -a;
               b = -b;
           }
           
           long long c = 1LL*a*x[i] - 1LL*b*y[i]*1LL;
           
           if(!mp[slope].count(c)){
               total++;
               mp[slope].insert(c);
               res+=total - mp[slope].size();
           }
       }
   }
   print(res);
}