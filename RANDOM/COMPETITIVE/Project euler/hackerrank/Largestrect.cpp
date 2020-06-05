#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 

typedef struct StackItem
{
    int height;
    int index;
} StackItem;

int main() 
{
    int n,i,top = -1,left, currArea = 0, maxArea = 0;
    scanf("%d",&n);
    
    int *arr = (int *)malloc(sizeof(int)*(n+1));
    StackItem *s = (StackItem *)malloc(sizeof(StackItem)*n);
   
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    arr[i] = -1;
    
    for(i = 0;i<=n;i++)
    {
        while(top>=0 && arr[i] < s[top].height)
        {
            if(top == 0)
                left = -1;
            else
                left = s[top-1].index;
            
            currArea = s[top].height * (i - left -1);
            maxArea = (currArea > maxArea) ? currArea : maxArea;
            top--;
        }
        
        if(i<n)
        {
            top++;
            s[top].index = i;
            s[top].height = arr[i];
        }
    }
        
    free(arr);
    free(s);
                             
    printf("%d",maxArea);
    return 0;
}