#include<stdio.h>
#include<stdlib.h>
int main()
{

    int arr[100];
    int n,flag;
    int windowsize;
    scanf("%d",&n);
    scanf("%d",&windowsize);
    for(int i=0;i<n;i++)
    {
        scanf("%d\t",&arr[i]);
    }
    if(windowsize<n){
    for(int i=0;i<(n-windowsize+1);i++)
    {
        flag=0;
        for(int j=0;j<windowsize;j++)
        {
            if (arr[i+j] < 0)
            {
            printf("%d\t",arr[i+j]);
                flag =1;
                break;
            }
        }
    if(!flag)
        printf("NO neg ele...0");
    }
    }

}
