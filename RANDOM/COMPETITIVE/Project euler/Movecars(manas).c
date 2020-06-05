#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    char key;
}element;
element stack[1000000];
element hand[10];
int top=-1;
void push1(char val)
{
        stack[++top].key=val;
    }
char pop1()
{
    return(stack[top--].key);
}
void push2(char val)
{
        hand[++top].key=val;
    }
char pop2(){
    return(hand[top--].key);
}
int main(){
    char a[1000000];
    int p,q,s,t,i,k;
    scanf("%d%d%d%d%d",&p,&q,&s,&t,&k); //lanes , keys,cars...
    char b[q];
    scanf("%s",a);
    scanf("%s",b);
    for(i=0;i<q;i++){
        push1(b[i]);
    }
    for(i=0;i<s;i++)
        {
        push2(stack[i].key);
    }
    i=s;
    while(i<q)
    {
        for(int j=0;j<t;j++){
            printf("%d %c\n",j,pop2());
            push2(stack[i++].key);
        }
    }
}
