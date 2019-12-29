import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.lang.*;


class DistPackets {
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
        long n = sc.nextInt(), m = sc.nextInt();
        long[] tree = new long[(int) m], assign = new long[(int) m];
        long overflow = 0;
        for (int i = 0; i < m; i++)
            tree[i] = sc.nextLong();
        assign[0]=n;

        //if(m>n)
          //  System.out.println(0);

        for (int i = 0; i < m; i++) 
        {
            n = assign[i]-tree[i];
            if (n > 0) 
            {
                if (n % 2 == 0) 
                {
                    if (2 * i + 1 < m && 2 * i + 2 < m)// left and right node both are present
                        assign[2 * i + 1] = assign[2 * i + 2] = n / 2;
                    else if (2 * i + 1 <=m && 2 * i + 2 >=m) 
                    {//only left node is present
                        assign[2 * i + 1] = n / 2;
                        overflow += n / 2;
                    }
                    else//no children present
                        overflow+=n;
                } 
                else 
                {
                    if (2 * i + 1 <m && 2 * i + 2 < m) 
                    {
                        assign[2 * i + 1] = n / 2 + 1;
                        assign[2 * i + 2] = n / 2;
                    } 
                    else if (2 * i + 1 <m && 2 * i + 2 >= m) 
                    {
                        assign[2 * i + 1] = n / 2 + 1;
                        overflow += n / 2;
                    }
                    else
                        overflow+=n;
                }

            }
        
        }
        System.out.println(overflow);
    }
}