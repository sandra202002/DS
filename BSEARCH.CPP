#include<stdio.h>
#include<conio.h>
void main()
{
int n,mid,i,a[20],item,first=0,last;

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
last=n-1;
mid=(first+last)/2;
while(first<=last)
{
if(a[mid]==item)
{
printf("\n Element is found is at position :%d",mid+1);
flag=1;
break;
}
else if(a[mid]<item)
{
first=mid+1;
}
else
{
last=mid-1;
}
mid=(first+last)/2;
}
if(flag==0)
{
printf("Element not found");
}
getch();
}