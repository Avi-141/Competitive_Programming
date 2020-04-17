/* 
    __gcd(x, y); log10(N); log2(N); floor(K); pow(10, K); modi = pow(a,m-2,m);
    emplace_back(); num_of_digits = floor(log10(N)) + 1; isPowerOfTwo --> x && (!(x&(x-1)));
    all_of(); any_of(); none_of(); copy_n(); iota() increasing list;
    auto num = 0b111; initialization in binary form
    insert(); 1ll << x; acos(); cos();
    nth_element(a.begin(), a.begin()+K-1, a.end());
    reverse/(next/prev)_permutation/random_shuffle( begin() , end() ) , accumulate( begin() , end() , initval )
    binary_search/lower_bound/upper_bound/count( begin() , end() , x )
    lower_bound >= , upper_bound >
    ld pi = atan( (ld)1 )*4 , e = 2.71828
    Min Heap : priority_queue<int,vector<int>,greater<int>> q; push(x); pop(); top();
 
    stack<type> name empty(),size(),pop(),top(),push(x)
    queue<type> name empty(),size(),pop(),front(),back(),push(x)
    priority_queue <type> name default max, min priority_queue <int, vector<int>, greater<int> > pq; empty(),size(),pop(),top(),push(x)
    deque<type> name pop_front(),pop_back(),push_front(),push_back(),size(),at(index),front(),back()
    set/multiset/map/multimap<type>name begin(),end(),size(),empty(),insert(val),erase(itr or val),find(val)
*/ 
#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mkpa make_pair
#define ull unsigned long long 
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define i64 int64_t

#define pb push_back
#define mp make_pair
 
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
//typedef unsigned long long ull;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll modm = 1e9+7;


int main(){

    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<b<<" "<<c<<" "<<c<<"\n";
    }
}