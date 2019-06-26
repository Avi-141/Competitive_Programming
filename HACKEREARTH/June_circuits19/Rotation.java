 import java.util.*;
    import java.io.*;
    import java.lang.*;
     
     
    class Rotation
    {
    //long[][] table = new Long[1002][1002];
    public static int longestCommonSubstrings(String s, String t) {
        int[][] table = new int[s.length()][t.length()];
        int len=0;
        int longest = 0;
        Set<String> result = new HashSet<>();
     
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i) != t.charAt(j)) {
                    continue;
                }
     
                table[i][j] = (i == 0 || j == 0) ? 1
                                                 : 1 + table[i - 1][j - 1];
                if (table[i][j] > longest) {
                    longest = table[i][j];
                    result.clear();
                }
                if (table[i][j] == longest) {
                    result.add(s.substring(i - longest + 1, i + 1));
                    len=longest;
                    
                }
            }
        }
        return len;
    }
    public static void main(String args[]) 
     {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        String t=sc.next();
        
        //Set<String> str=new HashSet();
       int  str=longestCommonSubstrings(s,t);
        System.out.println(n-str);
        
        //System.out.println(lcs);
        
      }
    }

Language: Java
