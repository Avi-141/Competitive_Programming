    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define pb push_back
     
    int main(int argc, char const *argv[])
    {
     
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end(),greater<int>());
     
        ll m;
        cin>>m;
        vector<ll> b(m);
        for(int i=0;i<m;i++)
            cin>>b[i];
        sort(b.begin(),b.end(),greater<int>());
     
        //cout<<n-1<<" "<<m-1;
       // cout<<b[m-1]<<" ";
     
        cout<<a[0]<<" "<<b[0];
        
        return 0;
    }