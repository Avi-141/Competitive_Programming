void printNextGreater(int arr[], int n)
{
    int i = 0;
    struct stack s;
    s.top = -1;
    int element, next;
 
    for (i=0; i<n; i++)
    {
     /* push the first element to stack */
        if(i == 0)
        {
            push(&s, arr[0]);
            continue;
        }
         
        next = arr[i];
 
        if (!isEmpty(&s))
        {
            /* if stack is not empty, then pop
            an element from stack */
            element = pop(&s);
 
            while (element < next)
            {
                printf("\n %d -> %d", element, next);
                if(isEmpty(&s))
                   break;
                element = pop(&s);
            }
 
            /* If element is greater than next,
            then push the element back */
            if (element > next)
                push(&s, element);
        }
 
        /* push next to stack so that we can
        find next greater for it */
        push(&s, next);
    }
     
    while (!isEmpty(&s))
    {
        element = pop(&s);
        next = -1;
        printf("\n %d -> %d", element, next);
    }
}
