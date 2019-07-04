#include <bits/stdc++.h>
using namespace std;

int main(){
     
    	int n;
    	cin >> n;
     
    	int perm[n];
    	vector<pair<int,int> > result;
     
     
    	for ( int i = 0 ; i < n ; i++ ) {
    		cin >> perm[i];
    		perm[i]--;
    	}
     
    	int i = 0, j = n-1;
    	while( i < n /2 ) {
    	
    		while(i < n/2 && perm[i] < n/2 )
    			i++;
     
    		while(j >= n/2 && perm[j] >= n/2 )
    			j--;
     
     
    		if ( i < n/2 && j >= n/2 ) {
    			if ( (j - i) >= n/2 ) {
    				result.emplace_back(i,j);
    			}
    			else
                { 
    				result.emplace_back(i,n-1);
    				result.emplace_back(0,n-1);
    				result.emplace_back(0,j);
    				result.emplace_back(0,n-1);
    				result.emplace_back(i,n-1);
    			}
     
    			swap(perm[i],perm[j]);
    		}
     
    	}
     
     
    	vector<int> valuetoindexmap(n);
     
     
    	for ( int i =0 ; i < n ; i++ )
    		valuetoindexmap[perm[i]] = i;
     
     
    	for( int i = 0 ; i < n/2 ; i++ ) {
    		if ( valuetoindexmap[i]!= i ) {
     
    			j = valuetoindexmap[i];
    			result.emplace_back(i,n-1);
    			result.emplace_back(j,n-1);
    			result.emplace_back(i,n-1);
    			swap(perm[i],perm[j]);
    			
    			valuetoindexmap[perm[i]] = i; 
    			valuetoindexmap[perm[j]] = j;
    		}
    	}
     
    	for( int i = n/2 ; i < n ; i++ ) {
    		if ( valuetoindexmap[i]!= i ) {
     
    			j = valuetoindexmap[i];
    			result.emplace_back(0,i);
    			result.emplace_back(0,j);
    			result.emplace_back(0,i);
    			swap(perm[i],perm[j]);
    			
    			valuetoindexmap[perm[i]] = i; 
    			valuetoindexmap[perm[j]] = j;
    		}
    	}
     
    	// cout << "current perm is " << endl;
    	// for(int k=0;k<n;k++)
    	// 	cout << perm[k] << " ";
    	// cout << endl;
     
     
     
    	cout << result.size() << '\n';
    	for (auto& p : result) {
    	    cout << p.first + 1 << " " << p.second + 1 << '\n';
    	}
     
    	return 0;
    }