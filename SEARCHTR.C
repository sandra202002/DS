#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int k;
struct node
{
int key;
struct node *left,*right;
};
struct node* newnode(int item)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->key=item;
temp->left=temp->right=NULL;
return temp;
}
//insertion

struct node *insert(struct node* node,int key)
{
if(node==NULL)
return newnode(key);
if(key<node->key)
node->left=insert(node->left,key);
else if(key>node->key)
node->right=insert(node->right,key);
return node;
}
//searching

struct node *search(struct node* root,int key)
{
if(root==NULL||root->key==key)
return root;
if(root->key<key)
return search(root->right,key);
else
return search(root->left,key);
}

void main()
{
struct node* root=NULL;
root=insert(root,50);
insert(root,30);
insert(root,90);
insert(root,45);
insert(root,35);
insert(root,65);
clrscr();
printf("enter the elemt to be searched:");
scanf("%d",&k);
if(search(root,k)==NULL)
printf("%d not found",k);
else
printf("%d found",k);

getch();
}
