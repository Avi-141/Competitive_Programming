import java.util.*;
/*Author : sourav2999 */

class Cherries{
	public static int mini(int key[],boolean mst[]){
		int min=Integer.MAX_VALUE,min_i=-1;
		int n=key.length-1;
		for(int i=1;i<=n;i++){
			if(!mst[i] && key[i]<min){
				min=key[i];
				min_i=i;
			}
		}
		return min_i;
	}
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int t,n,i,j,count,x,y,m,u;
		t=sc.nextInt();
		count=0;
		while(t-->0){
			count++;
			n=sc.nextInt();
			m=sc.nextInt();
			int a[][]=new int[n+1][n+1];
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(i!=j)
						a[i][j]=2;
					else 
						a[i][j]=0;
				}
			}
			for(i=1;i<=m;i++){
				x=sc.nextInt();
				y=sc.nextInt();
				a[x][y]=1;
				a[y][x]=1;
			}
			int key[]=new int[n+1];
			boolean mst[]=new boolean[n+1];
			Arrays.fill(key,Integer.MAX_VALUE);
			Arrays.fill(mst,false);
			key[1]=0;
			for(i=1;i<=n-1;i++){
				u=mini(key,mst);	
				mst[u]=true;
				for(j=1;j<=n;j++){
					if(a[u][j]!=0 && !mst[j] && a[u][j]<key[j])
						key[j]=a[u][j];
				}
			}
			int sum=0;
			for(i=1;i<=n;i++)
				sum+=key[i];
			System.out.println("Case#"+count+": "+sum);
		}
	}
}