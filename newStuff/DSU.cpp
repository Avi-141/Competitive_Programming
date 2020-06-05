#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int parent[600000];
int rankDsu[600000];
int children[600000];

void initialize(){
    for( int i = 0 ; i < 600000 ; i++ ){
        parent[i] = i;
        children[i] = 0;
        rankDsu[i] = 0;
    }
}

int find_dsu(int x){
    if (parent[x] != x)
        parent[x] = find_dsu(parent[x]);
    return parent[x];
}

void union_dsu(int x, int y){
    int x_ = find_dsu(x);
    int y_ = find_dsu(y);
    if (x_ == y_)
        return;
    if (rankDsu[x_] > rankDsu[y_]){
        parent[y_] = x_;
        children[x_] += children[y_] + 1;
    }
    else{
        parent[x_] = y_;
        children[y_] += children[x_] + 1;
    }
    if (rankDsu[x_] == rankDsu[y_])
        rankDsu[y_]++;
}

void sieve(int n, bool primes[]) { 

    for(int i=0;i<=n;i++)
        primes[i] = true;

    for (int p=2; p*p <= n; p++)
        if (primes[p] == true) 
            for (int i=p*p; i <= n; i += p) 
                primes[i] = false; 

}