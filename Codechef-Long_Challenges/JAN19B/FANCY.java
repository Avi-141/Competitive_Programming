import java.io.*;
import java.util.*;

class stupidshit
 {
    public static void main(String[] args) throws IOException 
    {
        BufferedReader read1 = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(read1.readLine());
        flagtocomeback:
        while (testcase-- != 0) 
        {
            String str = read1.readLine();
            String fancyshit[] = str.split(" ");
            for (String x : fancyshit)
                if (x.equals("not")) 
                {
                    System.out.println("Real Fancy");
                    continue flagtocomeback;
                }
            System.out.println("regularly fancy");
        }
    }
}