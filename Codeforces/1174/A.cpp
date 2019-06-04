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
 ll n;
 cin>>n;
 ll k=n;
 vector<ll>v1(2*n),v2,v3;
 n=2*n;

 int count=0;
 ll sum1=0,sum2=0;
 for(ll i=0;i<2*n;i++)
 {
  	cin>>v1[i];
     
   }
  sort(v1.begin(),v1.end());

 for(ll i=0;i<n;i++)
 {
 	if(v1[i]==v1[i+1])
 		count++;
 }
 if(count==(n-1))
 {
 	cout<<-1;
    exit(0);
  }
  for(ll i=0;i<n;i++){
  	v2.pb(v1[i]);
  sum1+=v2[i];
}
  for(int i=k;i<n;i++){
  	v3.pb(v1[i]);
  	sum2+=v1[i];}
 if(sum1!=sum2)
 {
 	for(ll i=0;i<k;i++)
 		cout<<v2[i]<<" ";
 	for(ll i=0;i<k;i++)
 		cout<<v3[i]<<" ";
 	exit(0);

 }
}