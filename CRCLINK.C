#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int cqueue[MAX];
int front=-1,rear=-1,item,i;

void insert()
{
if((rear+1)%MAX==front)
{
printf("Queue overflow");
}
else
{
printf("enter the data to insert:");
scanf("%d",&item);
rear=(rear+1)%MAX;
cqueue[rear]=item;
printf("element inserted");
if(front==-1)
front=0;
}
}

void delte()
{
if(front==-1)
{
printf("Queue underflow");
}
else
{
printf("the deleted elemnt is %d",cqueue[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
front=(front+1)%MAX;
}
}

void display()
{
if(front==-1)
printf("queue underflow");
else
{
if(front<rear)
{
for(i=front;i<=rear;i++)
printf("%d\t",cqueue[i]);
}
else
{
for(i=front;i<=MAX+rear;i++)
printf("%d\t",cqueue[i%MAX]);
}
}
}

void main()
{
int ch;
do{
printf("\nSELECT\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
printf("ENTER YOUR CHOICE:");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
delte();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("enter a valid number");
}
}
while(1);
}

