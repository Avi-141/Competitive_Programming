import java.util.*;
import java.io.*;
import java.math.*;

class test {
	final static long MOD = 1000000007;
	public static void main(String args[]) throws Exception {
		int T = nextInt();
		while(T-->0) {
			int n = nextInt();
			Map<Integer, Pair> vals = new HashMap<>();
			vals.put(0, new Pair(-1,0));
			long trips = 0;
			int val = 0;
			for(int i=0;i<n;i++) {
				val = val ^ nextInt();
				if(vals.containsKey(val)) {
					Pair p = vals.get(val);
					long amt = p.s + (i - p.f - 1) * p.t;
					trips += amt;
					p.s = amt+p.t;
					p.t++;
					p.f = i;
				} else {
					vals.put(val, new Pair(i, 0));
				}
			}
			System.out.println(trips);
		}
	}

	static class Pair {
		long f,s,t;
		Pair(int a, int b) {
			f=a;
			s=b;
			t=1;
		}
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