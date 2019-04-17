#include<bits/stdc++.h>
using namespace std;
int main()
{
long int t,c;
long int n;
long int i;
 cin>>t;
 while(t--)
 {
   cin>>n;
   long int pattern1,pattern2;
   long int xorstore;
   long int unknown[n];
   long int next1,next2;
   long int loop;
   long int temp1,temp2;
   long int result;
   cout<<1<<" "<<1<<" "<<3<<" "<<4<<endl;
   cin>>pattern1;
   cout<<1<<" "<<2<<" "<<3<<" "<<4<<endl;
   cin>>pattern2;
   xorstore=pattern1^pattern2;
   cout<<1<<" "<<1<<" "<<2<<" "<<5<<endl;
   cin>>next1;
   unknown[4]=xorstore^next1;
   cout<<1<<" "<<1<<" "<<2<<" "<<6<<endl;
   cin>>next2;
   unknown[5]=xorstore^next2;
   for(i=5;i<n-1;i++)
   {
    cout<<1<<" "<<i<<" "<<(i+1)<<" "<<(i+2)<<endl;
    cin>>loop;
    unknown[i+1]=unknown[i]^unknown[i-1]^loop;
   }
   cout<<1<<" "<<3<<" "<<n<<" "<<n-1<<endl;
   cin>>temp1;
   unknown[2]=temp1^unknown[n-2]^unknown[n-1];
   cout<<1<<" "<<4<<" "<<5<<" "<<n<<endl;
   cin>>temp2;
   unknown[3]=unknown[4]^unknown[n-1]^temp2;
   unknown[0]=pattern1^unknown[3]^unknown[2];
   unknown[1]=unknown[2]^unknown[3]^pattern2;
   cout<<endl;
   cout<<2<<endl;
    for(int i=0;i<n;i++){
    	cout<<unknown[i]<<" ";}
    cout<<endl;
    cin>>result;
    if(result==-1)
    	exit(0);
}

}
