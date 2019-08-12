#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
    	int n;
    	cin >> n;
    	int len = 2;
    	while(len * (len + 1) / 2 <= n)
    		++len;
    
    	n =n- len * (len - 1) / 2;
    	assert(n >= 0);
    	assert(n <= 45000);
    	
    	string s = "133";
    	while(n > 0){
    		--n;
    		s += "7";
    	}
    
    	len -= 2;
    	while(len > 0){
    		--len;
    		s += "3";
    	}
    	s += "7";
    	cout << s << endl;
    }
	return 0;
} 