import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

public class D{

	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			long n=sc.nextLong();
			long sum=1;
			long count=1;
			long highbit=Long.highestOneBit(n);
			int days = Long.numberOfTrailingZeros(highbit);
			System.out.println(days);
			for(int i=0;i<days;i++){
				long have = Math.min(count, (n - sum) / (days - i) - count);
                count += have;
                sum += count;
                System.out.print(have+" ");
			}
			System.out.println("\n");
		}
	}
}