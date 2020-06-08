#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;


const int N=60;
char a[N][N];
bool vis[N][N];
int n,m;
int good,bad;

void dfs(int row,int col){


	vis[row][col]=true;

	if(row>n||col>m || row<1|| col<1)
		return;
	if(a[row][col]=='#')//wall
		return;
	if(a[row][col]=='G')
		good+=1;
	else if(a[row][col]=='B')
		bad+=1;
	if(!vis[row+1][col]) dfs(row+1,col);
	if(!vis[row-1][col]) dfs(row-1,col);
	if(!vis[row][col+1]) dfs(row,col+1);
	if(!vis[row][col-1]) dfs(row,col-1);

}


int main()
{
	//#ifdef ONLINE_JUDGE
      // freopen("input.txt","r", stdin);
       //freopen("out.txt", "w", stdout);
    //#endif
	int t;
	cin >> t;
	while(t--){
		good=0,bad=0;
		memset(vis,0,sizeof vis);
		memset(a,0,sizeof a);

		cin>>n>>m;
		int beforeG=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='G') beforeG+=1;
			}
		}
		//we block all neighbours of B
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='B'){
					if(a[i+1][j]=='.') 
						a[i+1][j]='#';
					if(a[i-1][j]=='.') 
						a[i-1][j]='#';
					if(a[i][j+1]=='.') 
						a[i][j+1]='#';
					if(a[i][j-1]=='.') 
						a[i][j-1]='#';
				}
			}
		}
		//dfs(n,m)
		//check for all good people. and blocks in their way.
		if(a[n][m]=='B'){
			cout<<"NO\n";
		}
		dfs(n,m);
		if(beforeG==good && bad==0)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
}

//https://codeforces.com/submissions/AwakeAnay