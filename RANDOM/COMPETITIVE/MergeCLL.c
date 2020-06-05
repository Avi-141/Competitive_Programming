# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
 
struct node *insert(struct node *p, int n)
{
    struct node *temp;
    /* if the existing list is empty then insert a new node as the
     starting node */
    if (p == NULL)
    {
        p = (struct node *) malloc(sizeof(struct node)); /* creates new node
         data value passes
         as parameter */
 
        if (p == NULL)
        {
            printf("Error\n");
            exit(0);
        }
        p->data = n;
        p->link = p; /* makes the pointer pointing to itself because it
         is a circular list*/
    }
    else
    {
        temp = p;
        /* traverses the existing list to get the pointer to the last node of
         it */
        while (temp->link != p)
            temp = temp->link;
        temp->link = (struct node *) malloc(sizeof(struct node));
         /*
         creates new node using
         data value passes as
         parameter and puts its
         address in the link field
         of last node of the
         existing list*/
        if (temp->link == NULL)
        {
            printf("Error\n");
            exit(0);
        }
        temp = temp->link;
        temp->data = n;
        temp->link = p;
    }
    return (p);
}
void printlist(struct node *p)
{
    struct node *temp;
    temp = p;
    printf("The data values in the list are\n");
    if (p != NULL)
    {
        do
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        } while (temp != p);
    }
    else
        printf("The list is empty\n");
}
struct node *merge(struct node *p, struct node *q)
{
    struct node *temp = NULL;
    struct node *r = NULL;
    r = p;
    temp = p;
    while (temp->link != p)
        temp = temp->link;
    temp->link = q;
    temp = q;
    while (temp->link != q)
        temp = temp->link;
    temp->link = r;
    return (r);
}
 
int main()
{
    int n;
    int x;
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
 
    /* this will create the first circular list nodes*/
    printf("Enter the number of nodes in the first list \n");
    scanf("%d", &n);
    while (n-- > 0)
    {
        printf("Enter the data value to be placed in a node\n");
        scanf("%d", &x);
        start1 = insert(start1, x);
    }
    printf("The first list is\n");
    printlist(start1);
 
    /* this will create the second circular list nodes*/
    printf("Enter the number of nodes in the second list \n");
    scanf("%d", &n);
    while (n-- > 0)
    {
        printf("Enter the data value to be placed in a node\n");
        scanf("%d", &x);
        start2 = insert(start2, x);
    }
    printf("The second list is:\n");
    printlist(start2);
 
    start3 = merge(start1, start2);
    printf("The resultant list is:\n");
    printlist(start3);
    getchar();
    return 0;
}