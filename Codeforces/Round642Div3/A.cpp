#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("ip.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
	
    int t;
    cin >> t;
 
    for(int i = 1; i <= t; ++i){
    int n, m;
    cin >> n >> m;
 
    if(n == 1) cout << 0 << '\n';
    else if(n == 2) cout << m << '\n';
    else cout << 2 * m << '\n';
    } 
}