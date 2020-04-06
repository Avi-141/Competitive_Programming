import java.util.*;
import java.io.*;
import java.lang.*;

class intervals{

public static void main(String args[]){
       
        int t,k,i,j;
        int n;
        t=sc.nextInt();
        for(k=1;k<=t;k++){
            StringBuilder sb=new String
            n=sc.nextInt();
            pair a[]=new pair[n];
            int ans[]=new int[n];
            ArrayList<tup> p=new ArrayList<tup>();
            for(i=0;i<n;i++){
                l=sc.nextInt();
                r=sc.nextInt();
                a[i]=new pair(l,r);
                p.add(new tup(l,i,true));
                p.add(new tup(r,i,false));
            }
            Collections.sort(p,new Comparator<tup>(){
                @Override
                public int compare(tup a, tup b){
                    if(a.s==b.s){
                        if(a.b==b.b)
                            return a.ind-b.ind;
                        return ((a.b?1:0)-(b.b?1:0));
                    }
                    return a.s-b.s; ???????
                }
            });
            int count=0;
            boolean c=true,j=true;
            int ec=0,ej=0;
            int flag=0;
            for(i=0;i<p.size();i++){
                tup v=p.get(i);
                if(v.s>=ec)
                    c=true;
                if(v.s>=ej)
                    j=true;
                if(v.b)
                    count++;
                else 
                    count--;
                if(count<=2 && v.b){
                    if(c){
                        ans[v.ind]=1;
                        ec=a[v.ind].e;
                        c=false;
                    }
                    else if(j){
                        ans[v.ind]=2;
                        ej=a[v.ind].e;
                        j=false;
                    }
                }       
                else if(count>2){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                sb.append("Case #"+k+": IMPOSSIBLE\n");
                continue;
            }
            StringBuilder str=new StringBuilder();
            for(i=0;i<n;i++)
                str.append(ans[i]==1?'C':'J');
            sb.append("Case #"+k+": "+str+"\n");
        }
        sb.deleteCharAt(sb.length()-1);
        out.println(sb);
        out.flush();
    }
    static class pair{
        int s,e;
        public pair(int x,int y){
            s=x;
            e=y;
        }
    }
    static class tup{
        int s,ind;
        boolean b;
        public tup(int x,int y,boolean z){
            s=x;
            ind=y;
            b=z;
        }
    }
}
