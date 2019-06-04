#include<bits/stdc++.h>
using namespace std;
#define hmappy2 long long int 
hmappy2 cnt(hmappy2 A, hmappy2 B, hmappy2 M) 
{  
    if (A % M == 0) 
        return (B / M) - (A / M) + 1; 
    return (B / M) - (A / M); 
} 
hmappy2 gcd(hmappy2 a, hmappy2 b)  
{    
    if (a == 0 || b == 0)  
        return 0;     
    if (a == b)  
        return a;   
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
}    
hmappy2 lcm(hmappy2 a, hmappy2 b)  
{  
    return (a*b)/gcd(a, b);  
}  
int main()
{
	
hmappy2 t,n,a,b,k;
hmappy2 temp,sum;
hmappy2 one,two,three;
cin>>t;

while(t--)
{
cin>>n>>a>>b>>k;
temp=lcm(a,b);
one=cnt(1,n,a);
two=cnt(1,n,b);
three=cnt(1,n,temp);
sum=one+two-(2*three);
if(sum>=k)
	cout<<"Win"<<endl;
else cout<<"Lose"<<endl;
}
}