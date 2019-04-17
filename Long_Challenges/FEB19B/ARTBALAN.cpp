#include<bits/stdc++.h>
using namespace std;
#define SIZE 26
#define mcbc continue
#define fuckoff break
#define lli long long int
int main(){
	lli t;
	cin>>t;
	while(t--)
	{
	    lli  BAHUTBTDIYATUNE;
	    lli i,j,k,h,fin;
		lli check=0;
		lli temp;
		string balance;
		cin>>balance;

		vector<int> freq(26,0);
		vector<int> output;
		vector<int>store;

		int len=balance.length();
		for(i=0;i<len;i++)
		freq[balance[i]-'A']++;

		sort(freq.begin(),freq.end(),greater<int>());
		for(k=0;k<freq.size();k++)
		{
			if(freq[k])
			store.push_back(freq[k]);
		    else  fuckoff;
		}
		for(h=0;h<SIZE;h++)
		{
			check=0; 
			if(len%(h+1)!=0) // when p/q>26
			mcbc;
			for(j=0;j<=h;j++)
			{
				if(j<store.size())
				{
				if(store[j]>(len/(h+1))){
				    temp=len/(h+1);
				check=check+store[j]-temp;}}
		    }
			
			for(fin=h+1;fin<store.size();fin++){
				check=check+store[fin];
			}
			output.push_back(check);
		}
		sort(output.begin(),output.end());
	        BAHUTBTDIYATUNE=output[0];
	        cout<<BAHUTBTDIYATUNE<<endl;
	}
}