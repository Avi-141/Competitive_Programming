#include <bits/stdc++.h>
using namespace std;
    #define x first
    #define y second
    #define all(x) x.begin(),x.end()
    #define ll long long
    #define pi pair<int,int>
    #define ld long double
    #define lg length()
    #define sz size()
    #define vi vector<int>
    #define vl vector<ll>
    #define vp vector<pi>
    #define vpl vector<pl>
    #define pb push_back
    int main()
    {

        int n,x,y;
        vector <pi> a,b; 
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> x >> y;
            if(x>y) a.pb({x,i});
            else b.pb({y,i});
        }
        if(a.sz>b.sz)
        {
            sort(all(a));
            cout << a.sz << '\n';
            for(pi i : a) cout << i.y << ' ';
        }
        else
        {
            sort(all(b));
            reverse(all(b));
            cout << b.sz << '\n';
            for(pi i : b) cout << i.y << ' ';
        }
    }

