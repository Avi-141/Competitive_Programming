#include<math.h>
#include<stdio.h>
double min(double arr[][1000],int p,int q)
{
    double min=arr[0][0];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(arr[i][j]<=min){
                min=arr[i][j];
            }
            
}}
return min;}
double max(double arr[][1000],int p,int q)
{
    double max=arr[0][0];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(arr[i][j]>=max){
                max=arr[i][j];
            }  
}}
return max;}

int main()
{
    double a[1000][1000],mn,mx,x;
    int b[1000][1000];
    int i,j;
    int p,q;
    scanf("%d%d",&p,&q);
    getchar();
    for(i=0;i<p;i++){
        for (j=0;j<q;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    mn=min(a,p,q);
    mx=max(a,p,q);
    for(i=0;i<p;i++){
     for(j=0;j<q;j++){
            b[i][j]=ceil((a[i][j]-mn)/(mx-mn));
           // if(x<0.5){
               // b[i][j]=floor(x);
           // }
            //else{                
           // b[i][j]=ceil(x);}
            
            
           
        
    }}

   
    for(i=0;i<p;i++){
        for (j = 0; j < q; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}