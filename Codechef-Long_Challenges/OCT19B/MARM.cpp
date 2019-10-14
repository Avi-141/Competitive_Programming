#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include<string.h>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

#define ull unsigned long long 
int main(){
        
        int t;
        cin>>t;
        while (t--) {
            ull n,k;
            cin>>n>>k;
            vector<ull> arr(n);
            for (ull i = 0; i < n; i++)
                cin >>arr[i];
            int flag=0;
            ull rep = 3* n;
            if (k > rep){
                if(n&1)
                    arr[n/2]=0;
                k = k % (rep);
            }

            for (ull i = 0; i < k; i++)
                arr[i % n] ^= arr[n - (i % n) - 1];
            for (ull i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            cout<<"\n";
        }
    }
