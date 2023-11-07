#include<stdio.h>
#include<conio.h>
#define n 10
int seta[n]={1,2,3,4,5};
int setb[n]={6,7,8,9,10};
void find()
{
int i,search,t=0;
printf("ENTER ELEMNET TO SEARCH\n");
scanf("%d",&search);
for(i=0;i<n;i++)
{
   if(seta[i]==search)
   {
   printf("\nparent of %d is %d\n",search,seta[0]);
   t=1;
   break;
   }
   else if(setb[i]==search)
   {
   printf("\n parent of %d is %d",search,setb[0]);
   t=1;
   break;
   }

}
if (t==0)
{
printf("\nelemnet %d not found",search);
}

}

void main()
{
int usetc[n],i=0,j=0;
clrscr();
printf("SET A:");
for(i=0;i<n;i++)
{
printf(" %d ",seta[i]);
i++ ;
}
printf("SET B:");
for(i=0;i<n;i++)
{
printf(" %d ",setb[i]);
i++ ;
}
//union operation
while(i<n)
{
 usetc[i]=seta[j];
 i++;
 usetc[i]=setb[j];
 i++;
 j++;
 }
printf("UNION OF DISJOINT SET\n");

for(i=0;i<n;i++)
{
printf("%d\t",usetc[i]);
}
find();

getch();
}
