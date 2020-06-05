#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define mp  make_pair

vector<pair<ll,ll> > a;
ll parent[100010];
ll arr[100020];
void reset(int n)
{
    a.clear();
    for(int i=0;i<=n;i++)
        parent[i]=i;

}

ll find_set(ll parent[],ll p)
{
    if(p!=parent[p])
        parent[p]=find_set(parent,parent[p]);
    return parent[p];
}


int main()
{
    //int t;
    //cin>>t;
    //while(t--)
    //{
        ll i,j,ans=0,t1,t2,n,k,q,pa=0,pb=0;
        cin>>n>>k>>q;
        reset(n);
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            a.push_back(mp(arr[i],i));
        }
        sort(a.begin(),a.end());

        for(i=1;i<a.size();i++)
        {
            if((a[i].first-a[i-1].first)<=k)
                parent[a[i-1].second]=a[i].second;
        }

        while(q--)
        {
            cin>>t1>>t2;
            pa=find_set(parent,t1);
            pb=find_set(parent,t2);
            if(pa!=pb)  cout<<"No\n";
            else    cout<<"Yes\n";
        }


//    }
    return 0;
}
