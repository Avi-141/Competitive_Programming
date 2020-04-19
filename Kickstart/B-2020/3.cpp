#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int cc = 1;
  while (t--) {
    cout << "Case #" << cc++ << ": ";
    string s;
    cin >> s;
    ll mod = 1e9;
    ll x = 0, y = 0;
    vector<ll> mul = {1};
    for (char c : s) {
      if (c >= '2' && c <= '9')
	       mul.push_back(mul.back()*(c-'0')%mod);
      else if (c == 'E') x = (x+mul.back())%mod;
      else if (c == 'W') x = ((x-mul.back())%mod+mod)%mod;
      else if (c == 'S') y = (y+mul.back())%mod;
      else if (c == 'N') y = ((y-mul.back())%mod+mod)%mod;
      else if (c == '(') continue;
      else if (c == ')') mul.pop_back();
      else assert(0);
    }
    cout << x+1 << ' ' << y+1 << endl;
  }
}



/*#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;


ll mod=1e9;
pair<ll,ll> solve(string str){

		ll x=1e+9 + 1,y=1e+9 + 1;
		stack <ll> count;
		map <char,ll> cardinal;
		cardinal.insert(make_pair('N',0));
		cardinal.insert(make_pair('E',0));
		cardinal.insert(make_pair('W',0));
		cardinal.insert(make_pair('S',0));
		ll temp = 1;

		for(ll i=0;i<str.length();i++){
			if(str[i]>='2'&&str[i]<='9'){
				temp *= (str[i]-'0');
				count.push(str[i]-'0');
			}
			else if(str[i] == ')'){
				temp /= count.top();
				count.pop();
			}
			else if(str[i] != '('){
				cardinal[str[i]] += temp;
			}
		}
		x = (((x+cardinal['E'])%mod - cardinal['W'])%mod+mod)%mod;
		y = (((y+cardinal['S'])%mod - cardinal['N'])%mod+mod)%mod;
		x %=mod;
		y %=mod;
		if(x==0)
			x = mod;
		if(y==0)
			y = mod;
		pair<ll,ll> fin=make_pair(x,y);
		return fin;
}

int main(){
	ll t;
	string str;
	cin>>t;
	for(ll tt=1;tt<=t;tt++){
		cin>>str;
		pair<ll,ll> ans=solve(str);
		cout<<"Case #"<<tt<<": "<<ans.first<<" "<<ans.second<<endl;
	}
}*/