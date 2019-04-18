#include<bits/stdc++.h>
#define lli long long int 
using namespace std;
typedef long long int BigInt;

BigInt gcdExtended(BigInt a,BigInt b, BigInt *x,BigInt *y) 
{ 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    BigInt x1, y1;
    BigInt gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 


int main()
{
 int t;
 cin>>t;
 int l;
 for(l=1;l<=t;l++)
 {
 	lli n,len;
 	cin>>n>>len;
    vector<BigInt> vec(len);
    vector<BigInt> vec2;
    vector<BigInt> vec4;
    vector<BigInt>vec3;
    set<BigInt>set1;
    set<BigInt,greater<BigInt>>set2;
   for(int i=0;i<len;i++)
   cin>>vec[i];
  for(int i=0;i<len-1;i++){
           BigInt x,y; 
          if(vec[i]!=vec[i+1])
          {
         vec4.push_back(i);
         vec2.push_back(gcdExtended(vec[i],vec[i+1],&x,&y));
         vec3.push_back(gcdExtended(vec[i],vec[i+1],&x,&y));
     } }
     val=vec[vec4[0]]/vec2[0];
     vec3.push_back(val);
     val=vec[vec4[vec4.size()-1]]/vec2[vec2.size()-1];
     vec3.push_back(val);
    	sort(vec3.begin(), vec3.end());
	vec3.erase(unique(vec3.begin(), vec3.end()), vec3.end());
	string s="";
	val=vec[vec4[0]]/vec2[0]; 

	int pos=lower_bound(vec3.begin(),vec3.end(),val)-vec3.begin();

	s= s+(char)(pos+65);
	for(int i=0;i<vec2.size();i++){
		pos=lower_bound(vec3.begin(),vec3.end(),vec2[i])-vec3.begin();
		s=s+(char)(pos+65);
	}
	val = vec[vec.size()-1]/vec2[vec2.size()-1];
	pos = lower_bound(vec3.begin(),vec3.end(),val)-vec3.begin();
	s=s+(char)(pos+65);
	cout<<"Case #"<<l<<":"<<s<<endl;
  }}






