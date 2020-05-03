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
#define ll long long 
#define ull unsigned long long 
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;


int main(){

    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        string s;
        cin>>s;
        int n=s.length();
        int a[n];
        for(int i=0;i<s.size();i++){
            a[i]=s[i]-'0';
        }
        int count=a[0];
        vector<char> str;
        for(int i=1;i<=count;i++)
            str.pb('(');
        str.pb(s[0]);
        int curr;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                curr=a[i-1]-a[i];
                for(int j=1;j<=curr;j++){
                    str.pb(')');
                }
                str.pb(s[i]);
                count-=curr;
            }
            else if(a[i]>a[i-1]){
                curr=a[i]-a[i-1];
                for(int j=1;j<=curr;j++){
                    str.pb('(');
                }
                str.pb(s[i]);
                count+=curr;
            }
            else
                str.pb(s[i]);
        }
        for(int i=1;i<=count;i++)
            str.pb(')');
        cout<<"Case #"<<tt<<": ";
        for(int i=0;i<str.size();i++){
            cout<<str[i];
        }
        cout<<"\n";
    }
} 


