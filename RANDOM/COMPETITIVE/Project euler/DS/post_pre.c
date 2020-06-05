#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
char str[MAX],stack[MAX];
int top=-1;
void push(char c)
{
   stack[++top]=c;
}
char pop()
{
   return stack[top--];
}
void post_pre()
{
   int n,i,j=0; char c[20];
   char a,b,op;
   printf("Enter the postfix expression\n");
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0';
   printf("Prefix expression is:\t");
   for(i=n-1;i>=0;i--)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop(); c[j++]=pop();
        }
        push('@');
      }
   }
   c[j]='\0';
   strrev(c);
   printf("%s",c);
}
main()
{
    post_pre();
}
