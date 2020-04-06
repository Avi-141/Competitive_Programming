/* 
    __gcd(x, y); log10(N); log2(N); floor(K); pow(10, K); modi = pow(a,m-2,m);
    emplace_back(); num_of_digits = floor(log10(N)) + 1; isPowerOfTwo --> x && (!(x&(x-1)));
    all_of(); any_of(); none_of(); copy_n(); iota() increasing list;
    auto num = 0b111; initialization in binary form
    insert(); 1ll << x; acos(); cos();
    nth_element(a.begin(), a.begin()+K-1, a.end());
    reverse/(next/prev)_permutation/random_shuffle( begin() , end() ) , accumulate( begin() , end() , initval )
    binary_search/lower_bound/upper_bound/check( begin() , end() , x )
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
    int k=1;
    for(int tt=1;tt<=t;tt++){
      int n;
      cin>>n;
      vector<pair<int,int>>vec;
      int ansss[n];
      vector<pair<pair<int,int>,int>> triple,tup2;
     
      for(int i=0;i<n;i++){
         int l,r;
        cin>>l>>r;
        vec.pb(mkpa(l,r));
        triple.pb(mkpa(mkpa(l,1),i));
        triple.pb(mkpa(mkpa(r,0),i));
      }
      
      
      sort(triple.begin(),triple.end());
    
      int check=0;
      bool firstP=true,secondP=true;
      int ec=0,ej=0;
      int flag=0;
      for(int i=0;i<triple.size();i++){
         if(triple[i].first.first>=ec)
            firstP=true;
        if(triple[i].first.first>=ej)
            secondP=true;
        if(triple[i].first.second==1)
            check++;
        else 
            check--;
            
        if(check<=2&&triple[i].first.second==1){
            if(firstP){
                ansss[triple[i].second]=1;
                ec=vec[triple[i].second].second;
                firstP=false;
            }
            else if(secondP){
                ansss[triple[i].second]=2;
                ej=vec[triple[i].second].second;
                secondP=false;
            }
        }
        else if(check>2){
            flag=1;
            break;
        }
     }
     if(flag==1){
        cout<<"Case #"<<tt<<": IMPOSSIBLE\n";
        continue;
     }
     string str;
     for(int i=0;i<n;i++){
        str+=(ansss[i]==1?"C":"J");
     }
     cout<<"Case #"<<tt<<": "<<str<<"\n";
}
}


      

     

/*
8
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
3
1 100
2 4 
5 6 
3
1 3 
2 4 
5 6 
3
1 7 
2 4 
5 8 
4
1 3 
4 8 
5 10
2 4  
*/