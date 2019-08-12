import java.util.*;
import java.io.*;
import java.math.*;

class Solution {
	final static int MAX = 100005;
	final static long MOD = 1000000007;
	static long dp[][] = new long[MAX][10];
	static long pow[] = new long[MAX*2];
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int tm = 2 * MAX;
		pow[0] = 1;
		for(int i=1;i<tm;i++) {
			pow[i] = (pow[i-1] * 10) % MOD;
		}
		for(int i=0;i<10;i++)
			dp[1][i] = i;
		for(int i=2;i<MAX;i++) {
			for(int j=0;j<10;j++) {
				for(int k=0;k<10;k++) {
					if(j==k)
						dp[i][j] = (dp[i][j] + dp[i-1][k] + (pow[2*i-3] - pow[2*i-4]) * j + 10 * MOD) % MOD;
					else
						dp[i][j] = (dp[i][j] + dp[i-1][k] + pow[2*i-3] * j) % MOD;
				}
			}
		}
		// for(int i=1;i<MAX;i++) {
		// 	System.out.print(i+"=\t");
		// 	for(int j=0;j<10;j++)
		// 		System.out.print(dp[i][j]+"\t");
		// 	System.out.println();
		// }
		while(T-->0) {
			int nl = sc.nextInt();
			char[] l = sc.next().toCharArray();
			int nr = sc.nextInt();
			char[] r = sc.next().toCharArray();
			long ans = (sigmaf(r) - sigmaf(l) + f(l) + MOD) % MOD;
			System.out.println(ans);
		}

		// long sum = 0;
		// for(long n = 1;n<10000;n++) {
		// 	long f = f(n);
		// 	sum = (sum + f) % MOD;
		// 	long val = sigmaf(Long.toString(n).toCharArray());
		// 	System.out.println(n+"\t"+"\t"+f+"\t"+sum+"\t"+val+"\t"+(sum==val));
		// }
		// long check[][] = new long[MAX+1][10];
		// long limit = (long) Math.pow(10,MAX);
		// for(long i = 1;i<limit;i++) {
		// 	long val = f(i);
		// 	char ch[] = Long.toString(i).toCharArray();
		// 	int n = ch.length;
		// 	int d = ch[0] - 48;
		// 	check[n][d] += val;
		// 	for(int j=n+1; j<MAX; j++)
		// 		check[j][0] += val;
		// }
		// for(int i=1;i<MAX;i++) {
		// 	for(int j=0;j<10;j++) {
		// 		System.out.print((check[i][j] == dp[i][j]) + "\t");
		// 	}
		// 	System.out.println();
		// }
	}

	static long f(char ch[]) {
		int l = ch.length;
		long ans = 0;
		int pre = -1;
		for(int i=0;i<l;i++) {
			int dig = ch[i] - 48;
			if(pre != dig)
				ans = (ans + pow[l-i-1] * dig) % MOD;
			pre = dig;
		}
		return ans;
	}

	static long sigmaf(char[] no) {
		int n = no.length;
		long ans = 0;
		long val = 0;
		int pre = -1;
		for(int i=0;i<n;i++) {
			int dig = no[i] - 48;
			for(int j=0;j<dig;j++) {
				if(pre == j)
					ans = (ans + dp[n-i][j] - j * pow[2*(n-i-1)]) % MOD;
				else
					ans = (ans + dp[n-i][j]) % MOD;
			}
			ans = ( ans + ((val * dig) % MOD) * pow[n-i-1]) % MOD;
			if(pre != dig)
				val = (val + dig * pow[n-i-1]) % MOD;
			pre = dig;
		}
		ans = (ans + val) % MOD;
		return ans;
	}

	static int nextInt()throws IOException{
		InputStream in=System.in;
		int ans=0;
		boolean flag=true;
		byte b=0;
		boolean neg=false;
		while ((b>47 && b<58) || flag){
			if(b==45)
				neg=true;
			if(b>=48 && b<58){
				ans=ans*10+(b-48);
				flag=false;
			}
			b=(byte)in.read();
		}
		if(neg)
			return -ans;
		return ans;
	}

	static long nextLong()throws IOException{
		InputStream in=System.in;
		long ans=0;
		boolean flag=true;
		byte b=0;
		while ((b>47 && b<58) || flag){
			if(b>=48 && b<58){
				ans=ans*10+(b-48);
				flag=false;
			}
			b=(byte)in.read();
		}
		return ans;
	}
	static String next()throws Exception{
		StringBuilder sb=new StringBuilder(1<<16);
		InputStream in=System.in;
		byte b=0;
		do{
			if(!isWhiteSpace(b))
				sb.append((char)b);
			b=(byte)in.read();
		}while(!isWhiteSpace(b) || sb.length()==0);
		return sb.toString();
	}
	static boolean isWhiteSpace(byte b){
		char ch=(char)b;
		return ch=='\0' || ch==' ' || ch=='\n';
	}
}