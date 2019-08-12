import java.lang.*;
import java.io.*;
import java.util.*;
import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 

class ZOMCAV{
       static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
  
	public static void main(String args[])
	{
        FastReader sc=new FastReader();
        int t=sc.nextInt();
	  while(t--!=0)
	  {
	   int n=sc.nextInt();
             int arr[]=new int[n];
            int rad[]=new int[n];
            int left,right;
            int one=1;
       for(int i=0;i<n;i++)
       {
       	int k=sc.nextInt();
       	left=i-k;
       	if(left<0)
       		left=0;
       	right=i+k;
       	if(right>n-one)
       		right=n-one;
       	arr[left]=arr[left]+one;
       	if(right!=n-1)
       		arr[right+one]=arr[right+one]-one;
       	
       }
       for(int i=one;i<n;i++)
       	arr[i]=arr[i]+arr[i-one];


      for(int i=0;i<n;i++)
      {
       int inp=sc.nextInt();
       rad[i]=inp;
      }

      Arrays.sort(arr);
      int laude=one;
      Arrays.sort(rad);
      for(int i=0;i<n;i++)
      {
      	if(rad[i]!=arr[i])
      	{
      		laude=0;
      		break;
      	}
      }
      if(laude==0)
      	System.out.println("NO");
      else System.out.println("YES");


	  }
	}
}