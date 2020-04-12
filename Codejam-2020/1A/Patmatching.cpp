#include<bits/stdc++.h>
using namespace std;


const int N=101;
string a[N][2];
string s[N];
int n;

void solve (){

		cin>>n;
		string pref="",suff="";

		//store longest prefix and suffix from all sets of strings. 
		for(int i=0;i<n;i++){
			cin>>s[i];
			int len=(int)s[i].length();
			int ptr=0;

			while(s[i][ptr]!='*') ptr++;
			a[i][0]=s[i].substr(0,ptr);
			if( (int)a[i][0].length()>(int)pref.length() )
				pref=a[i][0];
			
			ptr=(int)s[i].length();
			while(s[i][ptr-1]!='*')ptr--;
			a[i][1]=s[i].substr(ptr,len-ptr);
			if((int)a[i][1].length()>(int)suff.length())
				suff=a[i][1];
		}
		//check for prefix substring and stored prefix for each string
		//same for suffix. 
		//they should match for a valid output.

		for(int i=0;i<n;i++){
			if(pref.substr(0,(int)a[i][0].length())!=a[i][0]){
				cout<<"*\n";
				return;
			}
			int sufflen=(int)suff.length();
			if(suff.substr(sufflen-(int)a[i][1].length(),(int)a[i][1].length())!=a[i][1] ){
				cout<<"*\n";
				return;
			}
		}
		/*prefix P and a suffix S*/
		/*
		parse the parts between the asterisks of a pattern so that X is the prefix up to the first asterisk, 
		Y is the suffix after the last asterisk, 
		and M1, M2, ..., Mk are the strings in between the asterisks, in order. 
		After checking that X is a prefix of P and Y is a suffix of S, as before, 
		all that remains to ensure is that the pattern M1*M2*...*Mk is present somewhere within the output word, 
		strictly between P and S. */

		/* ans =starting with P, then adding the middle word of every pattern in any order, then appending S.*/
		string ans = pref;
		for (int i = 0; i < n; i++)
			for (char c : s[i])
				if (c != '*')
					ans.push_back(c);
		for (char c : suff) ans.push_back(c);
		cout << ans << "\n";

}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}


	return 0;
}

