import java.util.Scanner;
import java.io.*;
import java.lang.*;

public class RotationQueries {
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
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        long k = sc.nextLong(), arr[] = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextLong();
        for (int i = 0; i < n; i++) 
        {
            long x = 0;
            for (int j = i; j < n; j++)
            {
                if(x <=k) 
                {
                    x += arr[j];
                    }
                    if (x > k) 
                    {
                        x =x- arr[j];
                        break;
                    }
            }
            arr[(int) ((i + x) % n)] = k ^ x;
        }
      long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        System.out.println(sum);
    }
}