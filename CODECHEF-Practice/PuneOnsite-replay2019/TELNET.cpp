#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mp make_pair 
#define pb push_back 
const int MAX = 998244353;

int main() 
{
    int t;
    cin >> t;
    while(t--){

        int n, k;
        cin >> n >> k;
        
        vector<pair<pair<int,int>, int > > city[k];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int curr; 
                cin >> curr;
                city[curr-1].pb(mp(mp(i,j),MAX));
            }
        }
        
        
        /*for(int i=0; i<k; i++){
            for(int j=0; j<city[i].size(); j++){
                cout << city[i][j].first.first << " " << city[i][j].first.second << " " << city[i][j].second << " " << endl;
            }
        }*/
        
        for(int j=0; j<city[0].size(); j++){
            city[0][j].second = 0;
        }
        
        for(int i=1; i<k; i++){
            for(int j=0; j<city[i].size(); j++){
                for(int l=0; l<city[i-1].size(); l++){
                	//cout<<"Cell value" <<" "<<city[i][j]<<"\n";
                	//cout<<"Before"<<" "<<city[i][j].second<<"\n";
                    city[i][j].second = min(city[i][j].second, city[i-1][l].second +
                                abs(city[i][j].first.first-city[i-1][l].first.first) + 
                                abs(city[i][j].first.second-city[i-1][l].first.second));
                   //cout<<"Network between"<<" "<<city[i][j].first.first<<" "<<city[i-1][l].first.first<<"\n"<<city[i][j].first.second<<" "<<city[i-1][l].first.second<<"\n";
                    //cout<<"After"<<" "<<city[i][j].second<<"\n";
                }
            }
        }
        
        int  mincost= MAX;
        for(int j=0; j<city[k-1].size(); j++){
            mincost = min(mincost, city[k-1][j].second);
        }
        cout<<mincost<<"\n";
    }
}