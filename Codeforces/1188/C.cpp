#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN=1e5;
     
int main() 
{
	    ll  n,x,quer;
	    ll i,l,r;
	    vector<ll> sum(MAXN+5),candies(MAXN+5);
        cin >> n;
        for (i=1;i<=n;i++)
        { 
        	 cin >> candies[i];
             sum[i]=sum[i-1]+candies[i];
         }
         for(i=0;i<=n;i++)
         	cout<<sum[i]<<" ";
        cin >> quer;
        while (quer--)
        {
            cin >> l >> r;
            l--; //r-l+1
            //cout<<sum[r]<<" "<<sum[l];
            cout << (sum[r]-sum[l])/10 <<"\n";;
        }
    }