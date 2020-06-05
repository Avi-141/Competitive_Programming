#include<bits/stdc++.h>
using namespace std;
void sort0(vector< vector<int> > &a,int c,int b)
{
	for(int i=c;i<=b;i++)
        {
		for(int j=i+1;j<=b;j++){
			if(a[0][i]>a[0][j]){
				int t,r;
				t=a[1][i];
				a[1][i]=a[1][j];
				a[1][j]=t;
				r=a[0][i];
				a[0][i]=a[0][j];
				a[0][j]=r;
			}
		}
	}
}
int main()
{
	int p,s;
	cin>>p>>s;
	vector< pair<int,int> >pr(p);
//	int arr[2][s];
	vector< vector<int> > a(2,vector<int>(s) );
	for(int i=0;i<p;i++)
	{
		int flag=0;
       for(int j=0;j<2;j++)
       for(int k=0;k<s;k++)
       cin>>a[j][k];
       sort0(a,0,s-1);
       /*for(int k=0;k<2;k++){
       		for(int j=0;j<s;j++){
       			cout<<a[k][j];
			   }
			   cout<<endl;
	   }*/
       for(int j=s-1;j>0;j--)
       if(a[1][j]<a[1][j-1])
       flag++;
       pr[i]=make_pair(flag,i);
    }
    sort(pr.begin(),pr.end());
    for(int i=0;i<pr.size();i++)
    cout<<pr[i].second+1<<"\n";
}
