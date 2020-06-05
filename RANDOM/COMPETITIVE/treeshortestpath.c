#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node*left ,right;
	int data
};

struct Node* newNode(int data) 
{ 
    struct node* ptr = (struct node*)malloc(sizeof(struct node)); 
    ptr->data = data; 
    ptr->left = ptr->right = NULL; 
    return ptr; 
} 

struct node* insert(struct node* root, int data) 
{ 
    if (!root) 
        root = newNode(data); 
    else if (root->data > data) 
        root->left = insert(root->left, data); 
    else if (root->data < data) 
        root->right = insert(root->right, data); 
    return root; 
} 
  

int distroot(struct Node* root, int x) 
{ 
    if (root->data == x) 
        return 0; 
    else if (root->data > x) 
        return 1 + distroot(root->left, x); 
    return 1 + distroot(root->right, x); 
} 
int dist2nodes(struct node* root,int x,int y)
{
	if(root==NULL)
	return;
   if(root->data>x && root->right>y)
   	  return dist2nodes(root->left,x,y);
   	if(root->data<x &&root->data<y)
   		return dist2nodes(root->right,x,y)
   	if(root->data>=x && root->data<=y)
   		return distroot(root,x);
   	     return distroot(root,y);

}
int main()
{
	struct node * r=NULL;
	r=insert(r,19);
	insert(r,21);
	insert(r,11);
	insert(r,2);
	insert(r,233);
	insert(r,12);
    insert(r,1);
    insert(r,111);
    insert(r,-1)
    insert(r,0);
    dist2nodes(r,19,1);
}
