#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct queue
{
    int *items;
    int maxsize;
    int front;
    int rear;
    int size;
};
 struct queue* newqueue(int size)
 {
     struct queue *pt=NULL;
     pt=(struct queue*)malloc(size*sizeof(struct queue));
     pt->items=(struct queue*)malloc(size*sizeof(int));
     pt->front=-1;
     pt->maxsize=size;
     pt->rear=-1;
     return pt;
 }
 int size(struct queue *pt)
 {
     return pt->size;
 }
 int isempty(struct queue *pt)
 {
     if(pt->front==pt->rear==-1) return 1;
     else return 0;

 }
 int isfull(struct queue *pt )
 {
   if(pt->rear==pt->size-1) return 1;
   else return 0;
 }
void enqueue(struct queue *pt,int x)
 {
     if(isfull(pt)) return;
     else
     {
         pt->rear=(pt->rear+1)%pt->maxsize;
         pt->items[pt->rear]=x;

     }
 }
 void dequeue(struct queue*pt)
 {
     if(isempty(pt)) return;
     else
     {
         pt->front=(pt->front+1)%pt->maxsize;
         pt->size--;
     }
 }
 void display(struct queue *pt)
 {
     if(isempty(pt)) printf("queue empty!!");
     else printf("%d",pt->items[pt->front]);
 }
 int main()
 {
     int n,i,a[30],choice;
     printf("enter queue size: ");
     scanf("%d",&n);
     struct queue* pt=newqueue(n);
     printf("start entering elements: ");
     for(i=0;i<n;i++)
     {
        scanf("%d",&a[i]);
     }
      for(i=0;i<n;i++)
      {
          enqueue(pt,a[i]);
      }
     do
     {
     printf("enter choice : 1.dequeue\n2.checksize\n3.display\n4.exit");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:dequeue(pt);
         break;
         case 2:size(pt);
         break;
         case 3: display(pt);
         break;
     }
}while(choice!=4);
 }