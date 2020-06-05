#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *r;
	struct Node* d;
	}Node;
	void push(Node**head_ref,int new_data)
	{
     Node* new=(Node*)malloc(sizeof(Node));
     new->r=NULL;
     new->data=new_data;
     new_node->d=(*head_ref);
     (*head_ref)=new_node;
     }
void print(Node*node)
{
	while(node!=NULL)
	{
	printf("%d",node->data);
	node=node->d;
}
}
Node *mergelist(Node*a,Node*b)
{
	if(a==NULL)
	return;
	if(b==NULL)
	return;
	 Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->d = merge( a->d, b ); 
    } 
    else
    { 
        result = b; 
        result->d = merge( a, b->d ); 
    } 
  
    return result; 
} 
Node* flatten (Node* root) 
{ 
    
    if (root == NULL || root->r == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->r) ); 
} 



int main() 
{ 
    Node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->r ), 20 ); 
    push( &( root->r ), 10 ); 
  
    push( &( root->r->r ), 50 ); 
    push( &( root->r->r ), 22 ); 
    push( &( root->r->r ), 19 ); 
  
    push( &( root->r->r->r ), 45 ); 
    push( &( root->r->r->r ), 40 ); 
    push( &( root->r->r->r ), 35 ); 
    push( &( root->r->r->r ), 20 ); 
  
    // Let us flatten the list 
    root = flatten(root); 
  
    // Let us print the flatened linked list 
    printList(root); 
  
    return 0; 
} 