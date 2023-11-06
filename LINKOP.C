#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void createlist(int);
void display();
void insert_first();
void insert_last();
void insert_pos();
void delete_first();
//void delete_last();
void delete_pos();
int n=0;
struct node{
int data;
struct node * next;
}*head;
void main()
{
int n,ch;
clrscr();

printf("\nenter the size of the list\n");
scanf("%d",&n);
createlist(n);
do{
printf("SELECT\n1.INSERT NODE AT 1ST\n2.INSER NODE AT LAST\n3.INSER NODE AT POSITION\n4.DELETE NODE AT 1ST\n5.DELETE NODE AT LAST\n6.DELETE NODE AT POSITION\n7.DISPLAY\n8.EXIT\n");

scanf("%d",&ch);
switch(ch){
case 1:insert_first();
	continue;

case 2:insert_last();
	continue;
case 3:insert_pos();
	continue;

case 4:delete_first();
	continue;
//case 5:delete_last();
  //	continue;

case 6:delete_pos();
	continue;

case 7:display();
	continue;
default:exit(0) ;


}

}while(ch!=0);


}


void createlist(int n){
int data,i;
struct node *curr,*newnode;
if(n==0){
return;
}
else{
head=malloc(sizeof(struct node));
if(head==NULL){
printf("unable to allocate memory");
return;

}
printf("enter the head value");
scanf("%d",&data);

head->data=data;
head->next=NULL;


curr=head;
for(i=1;i<n;++i)
{
printf("enter the node %d\n",i+1);
scanf("%d",&data);
newnode=malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;

curr->next=newnode;
curr=newnode;

}

}

}

void insert_first(){
struct node*newnode;
int data;
n++;
printf("enter node value\n");
scanf("%d",&data);

if(head->data==NULL){
head=malloc(sizeof(struct node));
head->data=data;
head->next=NULL;
printf("node inserted\n");

}
else{
newnode=malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
head=newnode;
printf("node inserted\n");

}
}

void insert_last(){
struct node *newnode,*lastnode;
int data;
if(head==NULL)
insert_first();
else{
n++;
printf("enter node value\n");
scanf("%d",&data);
newnode=malloc(sizeof(struct node));
newnode->data=data;

lastnode=head;
while(lastnode->next!=NULL)
{
lastnode=lastnode->next;

}
lastnode->next=newnode;
newnode->next=NULL;
printf("node inserted\n");

}
}

void insert_pos(){
struct node *newnode,*prev,*curr;
int pos,data,i;
printf("enter the position to be inserted\n");
scanf("%d",&pos);

if(pos<0 || pos>n+1){
printf("invalid position");
}
else if(pos==1){
insert_first();

}
else if(pos==n)
insert_last();
else
{
n++;
printf("enter the node value\n");
scanf("%d",&data);
newnode=malloc(sizeof(struct node));
newnode->data=data;

curr=head;
for(i=1;i<pos-1;i++){
curr=curr->next;

}
newnode->next=curr->next;
curr->next=newnode;
printf("node inserted\n");
}

}
void delete_first(){
if(head==NULL)
printf("no element to delete\n");
else if(head->next==NULL){
n--;
printf("the node deleted is%d\n",head->data);
head=NULL;


}
else{
n--;
printf("the node deleted is%d\n",head->data);
head=head->next;
}
}
void delete_pos()
{
struct node*curr,*prev;
int pos,i;
printf("enter the position to be deleted\n");
scanf("%d",&pos);
if(pos<0 || pos>n)
printf("invalid position");
else if (pos==1)
delete_first();
//else if(pos==n)
//delete_last();
else{
n--;
curr=head;
for(i=1;i<pos;i++)
{
prev=curr;
curr=curr->next;

}
prev->next=curr->next;
printf("the node deleted is%d\n",curr->data);


}
}
void display(){
struct node *curr;
if(head==NULL)
printf("list is empty\n");
else{
curr=head;
printf("the list is");
while(curr!=NULL){
printf("%d ",curr->data);
curr=curr->next;

}
}
printf("\n\n");
}