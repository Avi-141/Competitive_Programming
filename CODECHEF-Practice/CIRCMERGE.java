import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    static long a[];
	static long prefix[];
	static int n;
	static long dp[][]=new long[1000][1000];
	static long sum(int x,int y){
		return prefix[y+1]-prefix[x];
	}
	static long solve(int i,int j){
		if(i>=j) return 0;
		if(dp[i][j]!=-1) return dp[i][j];
		dp[i][j]=Long.MAX_VALUE;
		for(int k=i;k<=j;k++) dp[i][j]=Math.min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)+sum(k+1,j));
		return dp[i][j];
	}
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
		while(t-->0){
			n=sc.nextInt();
			a=new long[2*n-1];
			prefix=new long[2*n];
			for(int i=0;i<1000;i++) Arrays.fill(dp[i],-1);
			for(int i=0;i<n;i++)a[i]=sc.nextLong();
			for(int i=n;i<2*n-1;i++) a[i]=a[i-n];
			prefix[0]=0;
			for(int i=1;i<2*n;i++) prefix[i]=prefix[i-1]+a[i-1];
			long min=Long.MAX_VALUE;
			for(int i=0;i<n;i++){
				min=Math.min(min,solve(i,i+n-1));
			}
			System.out.println(min);
		}
    }
}