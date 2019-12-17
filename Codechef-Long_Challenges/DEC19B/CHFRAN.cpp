#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

void calc_z (string &s, vector<int> & z)
{
    int len = s.size();
    z.resize (len);

    int l = 0, r = 0;
    for (int i=1; i<len; ++i)
        if (z[i-l]+i <= r)
            z[i] = z[i-l];
        else
        {
            l = i;
            if (i > r) r = i;
            for (z[i] = r-i; r<len; ++r, ++z[i])
                if (s[r] != s[z[i]])
                    break;
            --r;
        }
}
int main() { 
	int t;
	cin>>t;
	while(t--){

		ll n;
		cin>>n;
		vector<pair<ll,ll> > interval;
		pair<ll,ll> p;
		vector<pair<ll,ll>> left;
		vector<ll> right;
		vector<pair<ll,ll>> seq;
		ll l,r;
   		vector<int> z;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		p=make_pair(l,r);
		interval.push_back(p);
		left.push_back(make_pair(l,0));
		right.push_back(r);
	}
	
	sort(interval.begin(),interval.end());
    seq=left;
    
    for(int i=0;i<right.size();i++){
    	seq.push_back(make_pair(right[i],1));
    }
   sort(seq.begin(),seq.end());
   int flag=0,minn=INT_MAX;

   //bracket sequence 
   string str="";
   	for(int i=0;i<seq.size();i++){
   		if(seq[i].second==0)
   			str+="(";
   		else if(seq[i].second==1)
   			str+=")";
   }
   //cout<<str<<" ";
   string check="()()";
   string working_string=check+str;
  // vector<int> z;
   calc_z(working_string, z);//get position of ()()
  
    //int count=0;
      //for(int i = check.size(); i < working_string.size(); ++i)
        // if(z[i] >=check.size())
        //	count++;
            //cout <<"substr at "<<" "<<i - check.size() << endl;
   if(str.compare(check)==0){
   	cout<<0<<"\n";
   	continue;
   }

   if(n==1||str.compare("()")==0){
   	cout<<-1<<"\n";
   	continue;
   }
   int arr[str.size()];
   //memset(arr,0,sizeof(arr));
   int prefixSum[str.size()];
   //prefixSum[0] = arr[0]; 
   //arr +1 -1
   arr[0]=1;
   //prefixSum[0] = arr[0];
   for(int i=1;i<str.size();i++){
   	    arr[i]=arr[i-1];
   	if(str[i]=='(')
   		arr[i]+=1;
   	else if(str[i]==')') 
   	   arr[i]-=1;
   }

    for (int i = 0; i <str.size(); i++){
         if(arr[i]==0)
         	flag++;
     }
    if(flag>1){
        cout<<0<<"\n";
        continue;
     }
    for(int i=1;i<=seq.size()-2;i++){
     	if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])
     		minn=min(minn,arr[i]);
     }
     if(minn==INT_MAX){
     	cout<<-1<<"\n";
     	continue;
     }
     cout<<minn<<"\n";
   } 
}

/*
5
3
1 4
2 6
5 7
2
1 4
4 6
2
3 7
8 9
7 
1 3 
1 10 
2 4 
4 5 
6 7 
7 8 
9 10 
8
1 3
1 10
2 4
4 5
6 7
7 8
9 10
2 9 
*/

/*
4
3
1 4
2 6
5 7
(()())
2
1 4
4 6
(())
2
3 7
8 9
()()
0
7
1 3
1 10
2 4
4 5
6 7
7 8
9 10
((()())(())())*/