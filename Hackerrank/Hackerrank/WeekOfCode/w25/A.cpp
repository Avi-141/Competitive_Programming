#include<bits/stdc++.h>
using namespace std; 
 
typedef vector<vector<int> > g;
typedef pair<int, int> pi;

int main(){

 	#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    int a[100], b[100];
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<m; i++)
        cin>>b[i];
    int cnt = 0;
    for (int k=1; k<=100; k++)
    {
        int flag = 1;
        for (int i=0; i<n; i++)
            if (k % a[i] != 0)
                flag = 0;
        for (int i=0; i<m; i++)
            if (b[i] % k != 0)
                flag = 0;
        if (flag == 1)
            cnt ++;
    }
    cout << cnt << "\n";
 	return 0;
}