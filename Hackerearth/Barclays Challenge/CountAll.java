import java.util.*;
import java.io.*;
import java.math.*;
class division{
	
	static class FastReader{
		BufferedReader br;
		StringTokenizer st;
		public FastReader(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		String next(){
			while(st==null || !st.hasMoreElements()){
				try{
					st= new StringTokenizer(br.readLine());
				}
				catch (IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		String nextLine(){
			String str = "";
			try{
				str=br.readLine();
			}
			catch(IOException e){
				e.printStackTrace();
			}
			return str;
		}
	}

	static class pair{
		int first,second;
		pair(int f,int s){
			first=f;
			second=s;
		}
	}

	public static long fastexpo(long x, long y, long p){
		long res=1;
		while(y > 0){
			if((y & 1)==1)
				res= ((res%p)*(x%p))%p;
			y= y >> 1;			
			x = ((x%p)*(x%p))%p;
		}
		return res;
	}

	public static long[] sieve (int n) {
		long div[]=new long[1000001];
		Arrays.fill(div,1);
		for(int i=2;i<=n;i++){
				for(int j=i;j<=1000000;j+=i){
						div[j]=(div[j]+1)%1000000007;
				}
		}
		return div;
	}

	public static long gcd(long a,long b){
        return (BigInteger.valueOf(a).gcd(BigInteger.valueOf(b))).longValue();
    }

    
	
	public static void main(String args[]){
		FastReader sc = new FastReader();
		long ans=0;
		int n,i;
		n=sc.nextInt();
		long div[]=sieve(n);
		int a[]=new int[n];
		for(i=0;i<n;i++){
			a[i]=sc.nextInt();
			ans=(ans+div[a[i]])%1000000007;
		}
		System.out.println(ans);

	}
}