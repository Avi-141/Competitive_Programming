
#include "stdio.h"
#include "stdlib.h"

struct Node{
	char info;
	struct Node *next;
};

typedef struct Node *nodeptr;

struct Node* getNode()
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	return newNode;
}

void freeNode(nodeptr *q)
{
	free(q);
}


void push(nodeptr *q, char x)
{
	nodeptr foo = *q;
	*q = getNode();
	(*q)->info = x;
	(*q)->next = foo;
}

char pop_q(nodeptr *q)
{
	nodeptr foo = *q;
	char val = 0;
	if(foo == NULL)
	{
		//Blah blah
		return val;
	}
	if(foo -> next == NULL)
	{
		val = foo->info;
		*q = NULL;
		return val;
	}
	else
	{
		//Traverse to last node
		while((foo->next)->next != NULL)
		{
			foo = foo-> next;
		}
		val = (foo->next) -> info;
		foo -> next = NULL;
		free(foo -> next);
		return val;
	}
}

char pop_stack(nodeptr *s)
{
	nodeptr foo = *s;
	char val = 0;
	if(foo == NULL)
	{
		//Blah blah
		return val;
	}
	else
	{
		val = foo -> info;
		*s = foo -> next;
		return val;
	}
}


int main()
{
	nodeptr Queue;
	nodeptr Stack;

	char str[32];
	char bar,foo;

	int i;

	Queue = 0;
	Stack = 0;

	printf("%s\n","Enter word");
	scanf("%s",str);

	//insert into queue and stack
	i = 0;
	while((bar = str[i]) != '\0')
	{
		push(&Queue, bar);
		push(&Stack, bar);
		i++;
	}

	//pop and check
	i = 1; //Assume palindrome
	bar = 1;
	foo = 1;
	while(bar != 0 && foo != 0 && i == 1)
	{
		bar = pop_stack(&Stack);
		foo = pop_q(&Queue);

		if(bar != foo)
			i = 0;

	}

	if(i == 1)
		printf("Is a palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}
