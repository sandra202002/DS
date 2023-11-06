#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
struct node *nxt;
int data;
};
struct node *head;
void b_insert();
void l_insert();
void s_insert();
void b_delete();
void l_delete();
void s_delete();
void search();
void display();

void main()
{
int choice=0;
clrscr();
while(choice!=9)
{
printf("\n************ MAIN MENU ************");
printf("\n===================================");
printf("\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT AT SPECIFIC LOCATION\n4.DELETE FROM BEGGINING\n5.DELETE FROM END\n6.DELETE FROM SPECIFIC LOCATION\n7.SEARCH\n8.DISPLAY\n9.EXIT");
printf("\n Enter your choice:");
scanf("%d",&choice);

switch(choice)
{
case 1:
b_insert();
break;
case 2:
l_insert();
break;
case 3:
s_insert();
break;
case 4:
b_delete();
break;
case 5:
l_delete();
break;
case 6:
s_delete();
break;
case 7:
search();
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf("enter a valid number!!!");
}
}
}

void b_insert()
{
struct node *ptr;
int item;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("OVERFLOW");
}
else
{
printf("ENTER THE ITEM TO INSERT:");
scanf("%d",&item);
if(head==NULL)
{
ptr->nxt=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->nxt=head;
head->prev=ptr;
head=ptr;
}
printf("NODE INSERTED");
}
}

void l_insert()
{
struct node *ptr,*temp;
int item;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("Overflow");
}
else
{
printf("ENETR THE ITEM:");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->nxt=NULL;
ptr->prev=NULL;
head=ptr;
}
else
{
temp=head;
while(temp->nxt!=NULL)
{
temp=temp->nxt;
}
temp->nxt=ptr;
ptr->prev=temp;
ptr->nxt=NULL;
}
}
printf("NODE INSERTED");
}

void s_insert()
{
struct node *ptr,*temp;
int item,loc,i;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("overflow");
}
else
{
temp=head;
printf("ENTER THE LOCATION:");
scanf("%d",&loc);
for(i=1;i<loc;i++)
{
temp=temp->nxt;
if(temp==NULL)
{
printf("THERE ARE LESS THAN %d ELEMENTS",loc);
return;
}
}
printf("ENTER THE VALUE:");
scanf("%d",&item);
ptr->data=item;
ptr->nxt=temp->nxt;
ptr->prev=temp;
temp->nxt=ptr;
temp->nxt->prev=ptr;
printf("NODE INSERTED");
}
}
void b_delete()
{
struct node *ptr;
if(head==NULL)
{
printf("UNDERFLOW");
}
else if(head->nxt==NULL)
{
head=NULL;
free(head);
printf("NODE DELETED");
}
else
{
ptr=head;
head=head->nxt;
head->prev=NULL;
free(ptr);
printf("NODE DELETED");
}
}

void l_delete()
{
struct node *ptr;
if(head==NULL)
{
printf("UNDERFLOW");
}
else if(head->nxt==NULL)
{
head=NULL;
free(head);
printf("NODE DELETED");
}
else
{
ptr=head;
if(ptr->nxt!=NULL)
{
ptr=ptr->nxt;
}
ptr->prev->nxt=NULL;
free(ptr);
printf("NODE DELETED");
}
}
void s_delete()
{
struct node *ptr,*temp;
int pos,i=1;
printf("ENTER POS TO DLT:");
scanf("%d",&pos);
ptr=head;
while(i<pos)
{
ptr=ptr->nxt;
i++;
}
temp=ptr->nxt;
ptr->nxt=temp->nxt;
temp->nxt->prev=ptr;
free(temp);
printf("\nNODE DELETED");
}

void display()
{
struct node *ptr;
printf("printing values........\n");
ptr=head;
while(ptr!=NULL)
{
printf(" %d ",ptr->data);
ptr=ptr->nxt;
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("list empty");
}
else
{
printf("ITEM TO SEARCH:");
scanf("%d",&item);
while(ptr!=NULL)
{

if(ptr->data==item)
{
printf("ITEM FOUND AT LOCATION %d",i+1);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr=ptr->nxt;
}
if(flag==1)
{
printf("ITEM NOT FOUND!!!!");
}
}
}




