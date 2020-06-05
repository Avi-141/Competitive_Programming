#include<bits/stdc++.h>
using namespace std; 
 
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef vector<vector<int> > g;
typedef pair<int, int> pi;

int main(){

 	#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    map<int,int> mp1,mp2;
    int move;
    string S,T;
    cin>>S>>T;
    for(int i=0;i<S.length();i++){
    	mp1[S[i]]++;
    }
    for(int i=0;i<T.length();i++){
    	mp2[T[i]]++;
    }
    cin>>move;
    int k;
    int Slen=S.size(),Tlen=T.size();
    for(k=0;k<min(Slen,Tlen);k++){
    	if(S[k]!=T[k])
    		break;	
    }
    int change=Slen-k + Tlen -k;
    //x+2*i
    if(move>=Slen+Tlen || (move>=change && (move-change)%2==0) ){
    	cout<<"Yes\n";
    }
    else cout<<"No\n";
}
