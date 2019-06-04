#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pr pair<int,int>
#define self auto
#define lli long long 
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;

int main()
{
    lli x,y;
    cin >>x>>y;
    lli h,v;
    cin>>h>>v;

    vector<pr> horiz(h), vert(v);
    for(self &it : horiz)
        cin >> it.first >> it.second;
    for(self &it : vert)
        cin >> it.first >> it.second;
    sort(horiz.begin(), horiz.end());
    sort(vert.begin(), vert.end());

    lli cuts_area= h+v+(h*v);

    statisticsTree th, tv;

    for(self &it : horiz)
    {
       cuts_area += th.order_of_key(it.second);
       th.insert(it.second);
    }

    for(self &it : vert)
    {
        cuts_area += tv.order_of_key(it.second);
        tv.insert(it.second);
    }

    cout <<cuts_area+1<< endl;
}