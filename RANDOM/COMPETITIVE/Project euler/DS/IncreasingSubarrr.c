#include<stdio.h>
#include<stdlib.h>
int main()

{

    int n,m;
    int arr[100]; int dp[100];
    int count=0;
     scanf("%d",&n);
     scanf("\n%d",&m);
     for(int i=0;i<n;i++)
     {

         scanf("%d",&arr[i]);
     }
     for(int i=0;i<n;i++)
     {
         dp[i]=arr[i];
         dp[i]=1;
     }
     for(int i=0;i<n;i++)
     {
         /*for(int i=0;i<m;i++){
         if(arr[i]<arr[i+1]){
         dp[i+1]+=dp[i];
         count++;}
     }
    // printf("%d",&dp[i]);
     }
  printf("%d",count);
} */
