#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define uos unordered_set
#define mp0 make_pair
#define pb push_back
#define mp map<double,long long int>
#define d double


lli gcds(lli a, lli b) 
{ 
    if (b == 0) 
        return a; 
    return gcds(b, a % b);  
      
} 
void swap1(lli *xp, lli *yp) 
{ 
    lli temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


lli nums(uos<lli>set1)
   {
      lli num=0;
      while(set1.find(num)!=set1.end()){
        num++;}
      return num;
    }


vector< pair <lli,lli> > vect; 
mp gg;

lli stateofgame(lli m,lli n)
{
  lli x,y;
  lli hcf=gcds(m,n);

  m=m/hcf;
  n=n/hcf;
    if(m>n)swap1(&m,&n);
  if(!(n%m))return 1;
  if(m==0||n==0)return 0;
  if(gg.find(n/(d)m)!=gg.end()){
    return gg[n/(d)m];
  }
  uos<lli>set2;

  for(lli i=1;i*m<=n;i++)
  {
    set2.insert(stateofgame(m,n-i*m));
  }
gg[n/(d)m]=nums(set2);

return gg[n/(d)m];

}

int main()
{
lli t;
cin>>t;
while(t--)
{
 lli m,n;
 cin>>m>>n;
if(abs(m-n)==2&&(n%2==0||m%2==0)){
     if(m==2)
  cout<<"Ari"<<endl;
  else if(n==2)cout<<"Ari"<<endl;
  else cout<<"Rich"<<endl;
 }
else if(n==m){
cout<<"Ari"<<endl;}
//else if(abs(n-m)==1&&n!=1&&m!=1)
//cout<<"Rich"<<endl;
else if(n==1||m==1){
cout<<"Ari"<<endl;}

//else if(abs(n-m)==4)
//cout<<"Rich"<<endl;
 else if(stateofgame(m,n))
           cout<<"Ari"<<endl;
            
    else if(!(stateofgame(m,n)))
    cout<<"Rich"<<endl;
}
}