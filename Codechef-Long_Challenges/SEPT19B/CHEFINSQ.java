import java.util.*;
import java.lang.*;
import java.io.*;


class CHEFINSQ{

public static long ncr(long n,long r){
		long i;
		long ans=1;
		for(i=1;i<=r;i++){
			ans=(ans*n)/i;
			n--;
		}
	  return ans;
	}
public static void main(String args[]){
	Scanner sc=new Scanner(System.in);

	int t,n,k;
	t=sc.nextInt();
	while(t-->0){
	     n=sc.nextInt();
	     k=sc.nextInt();
	     
	     int arr[]=new int[n];
	     for(int i=0;i<n;i++)
	     {
	         int x=sc.nextInt();
	         arr[i]=x;
	         //System.out.println(arr[i]);
	     }

	     Arrays.sort(arr);
	     int kth_cnt=0, tot=0;
	     for(int i=k-1;i>=0;i--)
	     {
	      	if(arr[i]==arr[k-1])
	       		kth_cnt++;
	     }

	    // System.out.println(kth_cnt);
	     int rem=k-kth_cnt;
	     //int pivot=arr[k-1];
	     for(int i=rem;(i<n&& arr[i]==arr[k-1]);i++)
	       tot++;

	      System.out.println(ncr(tot,kth_cnt));
	}
}
}