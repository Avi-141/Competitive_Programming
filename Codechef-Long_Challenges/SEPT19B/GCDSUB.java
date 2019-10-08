import java.util.*;
import java.io.*;
import java.math.*;

class GDSUB{

public static int sumprod(int n,int k,ArrayList<Integer> a,int dp[][],int mod ){
        if (k == -1) {
            return 1;
        }
        if (n == -1) {
            return 0;
        }

        if (dp[n][k] != -1) {
            return dp[n][k];
        }
        int s1,s2;
        s1 = ((a.get(n)%mod)* (sumprod(n - 1, k - 1, a, dp,mod)%mod))%mod;
        s2 = sumprod(n - 1, k, a, dp,mod);
        dp[n][k] = (s1%mod + s2%mod)%mod;
        return  s1 + s2;
    }
    public static void main(String args[]){
        FastReader sc = new FastReader();
        HashMap<Integer,Integer> hm=new HashMap<>();
        int n,k,i,j;
        int  mod=1000000007,temp;
        long ans=1;
        n=sc.nextInt();
        k=sc.nextInt();
        int a[]=new int[n];
        for(i=0;i<n;i++){
            a[i]=sc.nextInt();
            if(hm.containsKey(a[i]))
                hm.put(a[i],hm.get(a[i])+1);
            else
                hm.put(a[i],1);
        }
        ArrayList<Integer> key=new ArrayList<Integer>(hm.keySet());
        ArrayList<Integer> val=new ArrayList<Integer>(hm.values());
        if(hm.size()<=k){
            ans=1;
            for(i=0;i<key.size();i++){
                temp=key.get(i);
                ans= ((ans%mod)*((hm.get(temp)+1)%mod))%mod;
            }
        }
        else{
            //Collections.sort(val);
            long dp[][]=new long[k+1][val.size()];
            ans=1;
            int len=val.size();
            for(i=0;i<val.size();i++){
                dp[1][i]=val.get(i);
                ans=(ans+dp[1][i])%mod;
            }
            for(i=2;i<=k;i++){
                long sum=0;
                for(j=len-i;j>=0;j--){
                    sum=((sum%mod)+(dp[i-1][j+1]%mod))%mod;
                    dp[i][j]= ((val.get(j)%mod)*(sum%mod))%mod;
                    ans= ((ans%mod)+(dp[i][j]%mod))%mod;
                }
            }
        }
        out.println(ans);
        out.flush();
    }

    static PrintWriter out;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
            out=new PrintWriter(System.out);
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
}