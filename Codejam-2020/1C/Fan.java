import java.util.*;
import java.io.*;
import java.math.*;
class Solution{
    public static int lower(ArrayList<Integer> a,int x){
        int low,high,mid;
        low=0;
        high=a.size();
        while(low<high){
            mid=(low+high)/2;
            if(x<=a.get(mid))
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int test,tt,i,ans=0,x,y;
        test=sc.nextInt();
        for(tt=1;tt<=test;tt++){
            x=sc.nextInt();
            y=sc.nextInt();
            char m[]=sc.next().toCharArray();
            HashMap<key,ArrayList<Integer>> map=new HashMap<>();
            ArrayList<Integer> temp=new ArrayList<>();
            temp.add(0);
            map.put(new key(x,y),temp);
            int time=0;
            for(i=0;i<m.length;i++){
                if(m[i]=='N'){
                    y++;
                }
                else if(m[i]=='E'){
                    x++;
                }
                else if(m[i]=='S'){
                    y--;

                }
                else if(m[i]=='W'){
                    x--;
                }
                time++;
                key ke=new key(x,y);
                if(map.containsKey(ke))
                    temp=map.get(ke);
                else 
                    temp=new ArrayList<>();
                temp.add(time);
                map.put(ke,temp);
            }
            int min=Integer.MAX_VALUE/2;
            int minr,pos;
            boolean  flag=false;
            int px=0,py=0;
            ArrayList<key> list=new ArrayList<>(map.keySet());
            for(i=0;i<list.size();i++){
                key ke=list.get(i);
                temp=map.get(ke);
                minr=Math.abs(ke.x)+Math.abs(ke.y);
                pos=lower(temp,minr);
                if(pos==temp.size())
                    continue;
                if(temp.get(pos)<min){
                    min=temp.get(pos);
                    flag=true;
                }
            }
            if(!flag)
                sb.append("Case #"+tt+": "+"IMPOSSIBLE"+"\n");
            else
                sb.append("Case #"+tt+": "+min+"\n");
        }
        sb.deleteCharAt(sb.length()-1);
        out.println(sb);
        out.flush();
    }
    static class key {
        int x,y;
        public key(int a, int b) {
            x = a;
            y=b;
        }

        @Override
        public boolean equals (Object O) {
          if (!(O instanceof key)) return false;
          if (((key) O).x != x) return false;
          if (((key) O).y != y) return false;
          return true;
        }

        @Override
        public int hashCode() {
          return (x << 16) + y;
        }
      
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

    public static boolean isPrime(int n) {
        if(n<2) return false;
        for(int i=2;i<=(int)Math.sqrt(n);i++) {
            if(n%i==0) return false;
        }
        return true;
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

    public static boolean[] sieve (int n) {
        boolean primes[]=new boolean[n+1];
        Arrays.fill(primes,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i)
                    primes[j]=false;
            }
        }
        return primes;
    }

    public static long gcd(long a,long b){
        return (BigInteger.valueOf(a).gcd(BigInteger.valueOf(b))).longValue();
    }

    public static void merge(int a[],int l,int m,int r){
        int n1,n2,i,j,tt;
        n1=m-l+1;
        n2=r-m;

        int L[]=new int[n1];
        int R[]=new int[n2];

        for(i=0;i<n1;i++)
            L[i]=a[l+i];
        for(j=0;j<n2;j++)
            R[j]=a[m+1+j];

        i=0;j=0;

        tt=l;
        while(i<n1&&j<n2){
            if(L[i]<=R[j]){
                a[tt]=L[i];
                i++;
            }
            else{
                a[tt]=R[j];
                j++;
            }
            tt++;
        }

        while(i<n1){
            a[tt]=L[i];
            i++;
            tt++;
        }
        while(j<n2){
            a[tt]=R[j];
            j++;
            tt++;
        }
    }
    public static void sort(int a[],int l,int r){
        int m;
        if(l<r){
            m=(l+r)/2;
            sort(a,l,m);
            sort(a,m+1,r);
            merge(a,l,m,r);
        }
    }
}