#include<bits/stdc++.h>
using namespace std;
int main()
{
	 int t,n,m;
	 cin>>t;
	 while(t--)
    {
	 cin>>n>>m;
	 int arr[n][m];
	 int count=0;
	 int pattern;
	 if(n==1&&m==2)
	 {
	     cout<<1<<"\n";
	     cout<<1<<" "<<1<<"\n";
	 }
	 else if(n==2&&m==1)
	 {
	     cout<<1<<"\n";
	     cout<<1<<"\n"<<1<<"\n";
	 }
	 else if(n==1&&m>=3)
	 {
	 	cout<<2<<endl;
	 	for(int i=0;i<m;i++)
	 	{
	 	    if(i%4==0||i%4==1)
	 	    pattern=1;
	 	    else pattern=2;
	 	    //arr[0][i]=pattern;
	 	    cout<<pattern<<" ";
	 	    //cout<<"\n";
	 	}
	 	cout<<"\n";
	 }
	 else if(n>=3&&m==1)
	 { 
	   cout<<2<<endl;
	  	for(int i=0;i<n;i++)
	 	{
	 	    if(i%4==0||i%4==1)
	 	    pattern=1;
	 	    else pattern=2;
	 	    cout<<pattern<<"\n";
	 	    //cout<<"\n";
	 	}
	 	cout<<"\n";
	 }
	 else if(n==2&&m==2)
	 {
	 	cout<<2<<"\n";
	 	cout<<1<<" "<<1<<"\n";
	 	cout<<2<<" "<<2<<"\n";
	 }
	 else if(n==1&&m==1)
	 {
	 	cout<<1<<"\n";
	 	cout<<1<<"\n";
	 }
	 else if(n==2&&m>2)
	 { 
	     cout<<3<<"\n";
	     for(int i=0;i<n;i++)
	     {
	         pattern=0;
	     for(int j=0;j<m;j++)
	     {
	         //arr[i][j]=pattern%3+1;
	         cout<<pattern%3+1<<" ";
	         pattern++;
	         
	     }
	     cout<<"\n";}
	 }
	 else if(m==2&&n>2)
	 {
	    cout<<3<<endl;
	     for(int i=0;i<n;i++)
	     {
	         //pattern=0;
	     for(int j=0;j<m;j++)
	     {
	         //arr[i][j]=i%3+1;
	         cout<<i%3+1<<"\n";
	         //pattern++;
	         }
	         cout<<"\n";}
	 }
	    /* else if(n==3&&m==3)
	   {
		cout<<3<<endl;
		cout<<1<<" "<<1<<" "<<3<<"\n";
        cout<<2<<" "<<2<<" "<<4<<"\n";
        cout<<3<<" "<<3<<" "<<1<<"\n";
	    }*/

  else if(n>=3&&m>=3)
  {
  	cout<<4<<endl;
   for(int i=0;i<n;i++)
	{
		if(i%4==0||i%4==1)
			pattern=0;
		else
			pattern=2;
		for(int j=0;j<m;j++)
		{
			cout<<pattern+1<<" ";
		    pattern ++;
		    pattern=(pattern%4);
		}
	cout<<"\n";
   }
  }
}//EOW
 }//EOM