import java.io.*; 
import java.lang.*;
import java.util.*;


import java.util.Scanner;
 class RSIGNS{
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
static long power(long x, long y, long p) 
    {
        long res = 1;      
        
        x = x % p;  
      
        while (y > 0) 
        { 
     
            if((y & 1)==1) 
                res = (res * x) % p; 
      
            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res; 
    } 
  
public static void main(String args[])
{
  FastReader sc = new FastReader();
  long t=sc.nextLong();
  while(t--!=0)
  {
    long k=sc.nextLong();
    long pr=5*power(2,k,1000000007);
    pr=pr%1000000007;
    System.out.println(pr);

 }
}
}