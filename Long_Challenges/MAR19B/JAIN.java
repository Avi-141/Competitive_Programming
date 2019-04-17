import java.util.HashMap;
import java.util.Scanner;

 class JAIN {

	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-->0) {
		    String[] combinations = new String[100];
			int n = in.nextInt();
				int count=0;
		HashMap<String, Integer> map = new HashMap<>();
			long solution = 0;
			for (int i = 0; i < n; i++) 
			{
				String data = in.next();
				String pres="";
				String notpres="";
				if(data.indexOf('a')!=-1){
	                pres+='a';
	            }
	            else{
	                notpres+='a';
	            }
	            if(data.indexOf('e')!=-1)
	            {
	                pres+='e';
	            }
	            else{
	                notpres+='e';
	            }
	            if(data.indexOf('i')!=-1){
	                pres+='i';
	            }
	            else{
	                notpres+='i';
	            }
	            if(data.indexOf('o')!=-1){
	                pres+='o';
	            }
	            else{
	                notpres+='o';
	            }
	            if(data.indexOf('u')!=-1){
	                pres+='u';
	            }
	            else{
	                notpres+='u';
	            }
	            for (int j = 0; j <count; j++) 
	            {
					String comb = combinations[j];
					boolean flag = true;
					for (int k = 0; k < notpres.length(); k++) 
					{
						if(comb.indexOf(notpres.charAt(k))==-1)
						 {
							flag = false;
							break;
						}
					}
					if(flag) 
					{
						solution+=map.get(comb);
					}	
				}
	            if(map.get(pres)!=null) 
	            {
	            	map.put(pres, map.get(pres)+1);
	            }
	            else {
	            	combinations[count++]=pres;
	            	map.put(new String(pres), 1);
	            }
				
			}
			System.out.println(solution);
		}
	}

}
