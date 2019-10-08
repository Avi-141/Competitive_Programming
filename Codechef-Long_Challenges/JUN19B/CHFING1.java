import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.lang.*;
class CHFING 
{
	private static final long SALA = 1000000007;
    	public static void main(String[] args) 
        {
          Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- != 0) 
        {
        	 BigInteger n=new BigInteger(sc.next());
        	 BigInteger k=new BigInteger(sc.next());
        	 BigInteger answer=BigInteger.ZERO;
        	 BigInteger last_term=k.subtract(BigInteger.ONE);
        	 BigInteger d=n.subtract(BigInteger.ONE);
        	 BigInteger terms=last_term.divide(d);
             BigInteger temp=terms;
             terms=terms.add(BigInteger.ONE);
             temp=((temp.multiply(terms)).divide(BigInteger.valueOf(2)));
             BigInteger part1=(terms.multiply(last_term));
             BigInteger part2=(temp.multiply(d));
             answer=(part1.subtract(part2));
             answer=answer.mod(BigInteger.valueOf(SALA));
             System.out.println(answer);
           }
         }
    }

