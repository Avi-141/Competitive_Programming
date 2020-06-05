#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
struct Stack
{
	int top;
	unsigned capacity;
	char* array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*) malloc(stack->capacity * sizeof(char));
	return stack;
}
int isFull(struct Stack* stack)
{ return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack)
{ return stack->top == -1; }


void push(struct Stack* stack, char item)
{
	if (isFull(stack))
    {
        printf("STACKOVERFLOW");
		return;}
	stack->array[++stack->top] = item;
}


char pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int main()
{
    struct Stack* s= createStack(20);
    struct Stack* s1= createStack(20);
    char sen[100],val;
    int i;

    scanf("%[^\n]s",sen);
    int n=strlen(sen);
    for(i=0;i<strlen(sen);i++)
    {
        push(s,sen[i]);
    }
    while(!isEmpty(s))
    {

        char *s[n]=pop(s);
    }
    /* {
        if(isalpha(s->array[s->top]))
        {
            val = pop(s);
            push(s1,val);
        }
        else{pop(s);
        while(!isEmpty(s1)){
            printf("%c",pop(s1));
            }
            printf(" ");
            }
    }
    while(!(isEmpty(s1)))
            {
                val= pop(s1);
                printf("%c",val);
            }
}*/
