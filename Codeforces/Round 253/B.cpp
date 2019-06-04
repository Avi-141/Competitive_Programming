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

int ans = INT_MIN;
bool func(string s)
{
	if(s.size() % 2 == 1) return false;
	int n = s.size();
	int flag = 0;
	for(int i = 0 ; i < n/2 ; i++){
		if(s[i]=='?' && s[i+n/2]=='?'){
			continue;
		}else if(s[i]=='?' && s[i+n/2]!='?'){
			continue;
		}else if(s[i]!='?' && s[i+n/2]=='?'){
			continue;
		}else if((s[i]!='?' && s[i+n/2]!='?') && s[i]!=s[i+n/2]){
			flag = 1;
			break;
		} 
	}

	if(flag) return false;
	else return true;
}
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	while(k--)
		s.push_back('?');
	int n = s.size();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			string temp = s.substr(i,j-i+1);
			if(func(temp))
			{
				int t = temp.size();
				ans = max(ans,t);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}