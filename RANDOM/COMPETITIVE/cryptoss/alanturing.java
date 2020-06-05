import java.util.*;
public class Solution{
    public static Map<String,Integer> exists = new HashMap<String,Integer>();
    public static LinkedList<String> queue = new LinkedList<String>();
    static String swap(String str, int i, int j) 
    { 
        StringBuilder sb = new StringBuilder(str); 
        sb.setCharAt(i, str.charAt(j)); 
        sb.setCharAt(j, str.charAt(i)); 
        return sb.toString(); 
    } 
    public static String maker(String str,int a,int b,int c,int d,int e,int f){
            String strf = swap(str,a,b);
            strf = swap(strf,c,d);
            strf = swap(strf,e,f);
            /*char x = str.charAt(a);
            char y = str.charAt(b);
            str = str.substring(0,a)+y+str.substring(a+1);
            str = str.substring(0,b)+x+str.substring(b+1);
            x = str.charAt(c);
            y = str.charAt(d);
            str = str.substring(0,c)+y+str.substring(c+1);
            str = str.substring(0,d)+x+str.substring(d+1);
            x = str.charAt(e);
            y = str.charAt(f);
            str = str.substring(0,e)+y+str.substring(e+1);
            str = str.substring(0,f)+x+str.substring(f+1);
            return str;*/
            return strf;
    }
    public static void eval(){
        int curr = 0;
        while(queue.size()!=0){

            String temp = queue.poll();
            curr = exists.get(temp);
            String t1 = maker(temp,0,3,0,4,0,1);
            String t2 = maker(temp,0,1,3,4,0,4);
            String t3 = maker(temp,1,2,1,4,4,5);
            String t4 = maker(temp,1,4,1,5,1,2);
            String t5 = maker(temp,3,6,4,7,3,7);
            String t6 = maker(temp,3,4,6,7,3,7);
            String t7 = maker(temp,4,5,7,8,4,8);
            String t8 = maker(temp,4,7,4,8,4,5);
        if(exists.containsKey(t1)==false){
            exists.put(t1,curr+1);
            queue.add(t1);
            //eval(t1.str,t1.depth);
        }
        if(exists.containsKey(t2)==false){
            exists.put(t2,curr+1);
            queue.add(t2);
            //eval(t2.str,t2.depth);
        }
        if(exists.containsKey(t3)==false){
            exists.put(t3,curr+1);
            queue.add(t3);
            //eval(t3.str,t3.depth);
        }
        if(exists.containsKey(t4)==false){
            exists.put(t4,curr+1);
            queue.add(t4);
            //eval(t4.str,t4.depth);
        }
        if(exists.containsKey(t5)==false){
            exists.put(t5,curr+1);
            queue.add(t5);
            //eval(t5.str,t5.depth);
        }
        if(exists.containsKey(t6)==false){
            exists.put(t6,curr+1);
            queue.add(t6);
            //eval(t6.str,t6.depth);
        }
        if(exists.containsKey(t7)==false){
            exists.put(t7,curr+1);
            queue.add(t7);
            //eval(t7.str,t7.depth);
        }
        if(exists.containsKey(t8)==false){
            exists.put(t8,curr+1);
            queue.add(t8);
            //eval(t8.str,t8.depth);
        }
    }

    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        exists.put("123456789",0);
        queue.add("123456789");
        eval();
        for(int i=0;i<t;i++){
            long k = in.nextLong();
            int n = in.nextInt();
            String str = k+"";
            if(exists.get(str)<=n)
                System.out.println(exists.get(str));
            else
                System.out.println("-1");
        }
    }
}