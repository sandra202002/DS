#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,a[20],item;
printf("Enter the size of array");
scanf("%d",&n);
printf("Enter the element");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the element to search");
scanf("%d",&item);
int flag=0;
for(i=0;i<n;i++)
{
if(a[i]==item)
{
printf("\n Element is found is at position :%d",i+1);
flag=1;
}
}
if(flag==0)
{
printf("Element not found");
}
getch();
}