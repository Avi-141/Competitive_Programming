#include <bits/stdc++.h>
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
using namespace std;
typedef pair<ll,ll>pairs;

int main(int argc, char const *argv[]){
	ll n,k,temp,sum=0,back,forw,t1,rightsum,leftsum,left,right,dist,pos,min,i;

	 cin>>n>>k;
	 vector<ll>vec(n);
     vector<pairs>pvec;
  for(i=0;i<n;i++)
  {
  	cin>>vec[i];
     pvec.pb(mp(vec[i],i));
   }
  sort(pvec.begin(), pvec.end()); 
  for(i=0;i<n;i++)
  sum+=pvec[i].first;
  
   ll mid1=ceil(n/2.0);
   ll mid=pvec[mid1].first;
   ll mididx=pvec[mid1].second;

   if(n==1){
			cout<<1<<" "<<k%2;
			exit(0);
		}
		
		rightsum=sum;
		leftsum=0;
		left=0;
		right=0;
		pos=n+1;
		min=LLONG_MAX;
		dist=0;
		for(i=0;i<n;i++){
			rightsum=rightsum-pvec[i].first;
			forw=pvec[i].first*(n-i-1);
			back=pvec[i].first*i;
			right=rightsum-forw;
			left=back-leftsum;
			temp=abs(left)+abs(right);
			leftsum=leftsum+pvec[i].first;
			if(temp>=k)
				dist=temp-k;
			else if(temp<k){
				temp=k-temp;
				dist=temp%2;
			}
			if(dist<min){
				min=dist;
				pos=pvec[i].second;
			}
			else if(dist==min){
				if(pvec[i].second<pos)
					pos=pvec[i].second;
			}
		}
		cout<<pos+1<<" "<<min;

	}

