#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
#define REP(i, n) for(int i = 0;i < (n);i++)
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=998244353;
const llint inf=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

llint ax,ay,ar;
string out_in(llint x,llint y){
	string str;
	cout<<x<<" "<<y<<endl;
	cin>>str;
	return str;
	/*cerr<<x<<" "<<y<<endl;
	if(abs(x)>1000000000LL){return "WRONG";}
	if(abs(y)>1000000000LL){return "WRONG";}
	if(x==ax&&y==ay){cerr<<"center"<<endl;return "CENTER";}
	if((x-ax)*(x-ax)+(y-ay)*(y-ay)<=ar*ar){cerr<<"hit"<<endl;return "HIT";}
	cerr<<"miss"<<endl;return "MISS";*/
}
int main(void){
	llint T,A,B,i;cin>>T>>A>>B;
	llint M=1000000000LL;
	mt19937 engine(A);
	
	while(T--){
		std::uniform_int_distribution<llint> dist(0,M/2);
		ar=dist(engine)+M/2;
		std::uniform_int_distribution<llint> eist(ar-M,M-ar);
		ax=eist(engine);
		ay=eist(engine);
		//9本の矢を打つ
		llint L,R,U,D;
		string str;
		for(i=0;i<9;i++){
			L=500000000*(1-i%3);
			U=500000000*(1-i/3);
			str=out_in(L,U);
			if(str=="CENTER"){goto cen;}
			if(str=="WRONG"){return 0;}
			if(str=="HIT"){break;}
		}
		//左端限界を調べる
		for(i=35;i>=0;i--){
			llint z=L-(1LL<<i);
			if(abs(z)>M){str="MISS";}
			else{str=out_in(z,U);}
			if(str=="CENTER"){goto cen;}
			if(str=="WRONG"){return 0;}
			if(str=="HIT"){L=z;}
		}
		R=L;//右端限界を調べる
		for(i=35;i>=0;i--){
			llint z=R+(1LL<<i);
			if(abs(z)>M){str="MISS";}
			else{str=out_in(z,U);}
			if(str=="CENTER"){goto cen;}
			if(str=="WRONG"){return 0;}
			if(str=="HIT"){R=z;}
		}
		D=U; //Lはこのままで上端と下端を調べる
		for(i=35;i>=0;i--){
			llint z=U-(1LL<<i);
			if(abs(z)>M){str="MISS";}
			else{str=out_in(L,z);}
			if(str=="CENTER"){goto cen;}
			if(str=="WRONG"){return 0;}
			if(str=="HIT"){U=z;}
		}
		for(i=35;i>=0;i--){
			llint z=D+(1LL<<i);
			if(abs(z)>M){str="MISS";}
			else{str=out_in(L,z);}
			if(str=="CENTER"){goto cen;}
			if(str=="WRONG"){return 0;}
			if(str=="HIT"){D=z;}
		}
		
		str=out_in((L+R)/2,(U+D)/2);
		if(str!="CENTER"){return 0;}//絶対の自信
		
		cen:
		;
	}
}


/*

*/