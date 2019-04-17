import java.util.*;
import java.lang.*;
class MAXEP
{
	public static void main(String args[])
	{
     long count=10000;
     long coins=1000;
     long n, c;
     Scanner sc=new Scanner(System.in);
     n=sc.nextLong();
     c=sc.nextLong();
     long y=0;
     long voltage;
     long i;
     long before=0;
     while(count>0)
     {
       for(i=count+before;i<n;i=i+count)
       {
        System.out.println(1+" "+i);
        System.out.print("\n");
        voltage =sc.nextInt();
        if(voltage==1)
        {
          System.out.println(2);
          System.out.println("\n");
          break;
        }
       }
     before=i-count;
     y=before;
     count/=10;
     }
     System.out.println(3+" "+(y+1)+" ");
     System.out.println("\n");
     }
}