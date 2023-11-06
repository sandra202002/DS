#include<stdio.h>
#include<conio.h>
#define n 10
void main()
{
int i,j,k,t;
int u[n]={1,2,3,4,5,6,7,8,9,10};
int a[n]={1,2,3,4,5};
int b[n]={4,5,6,7,8,9};
int u_set[n],i_set[n],d_a[n],bitu[n],bita[n],bitb[n];
clrscr();
//to convert u to bit
for(i=0;i<n;i++)
{
if(u[i]!=-1)
{
bitu[i]=1;
}
}

printf("bit string representation of universal set is:\n");
for(i=0;i<n;i++)
{
printf("%d\t",bitu[i]);
}


for(i=0;i<n;i++)
{
t=0;
for(j=0;j<n;j++)
{
if(a[j]==u[i])
{
t=1;
break;
}
}
if(t==1)
{
bita[i]=1;
}
else
{
bita[i]=0;
}
}
printf("\nBit representation of set A:\n");
for(i=0;i<n;i++)
{
printf("%d\t",bita[i]);
}
printf("\n");

for(i=0;i<n;i++)
{
t=0;
for(j=0;j<n;j++)
{
if(b[j]==u[i])
{
t=1;
break;
}
}
if(t==1)
{
bitb[i]=1;
}
else
{
bitb[i]=0;
}
}

printf("bit representation of b:\n");
for(i=0;i<n;i++)
{
printf("%d\t",bitb[i]);
}
//set operations
for(i=0;i<n;i++)
{
if(bita[i]==1||bitb[i]==1)
{
u_set[i]=1;
}
else
{
u_set[i]=0;
}
}
printf("SET A UNION B\n");
for(i=0;i<n;i++)
{
printf("%d\t",u_set[i]);
}


for(i=0;i<n;i++)
{
if(bita[i]==1&&bitb[i]==1)
{
i_set[i]=1;
}
else
{
i_set[i]=0;
}
}
printf("SET A INTERSECTION B :\n");
for(i=0;i<n;i++)
{
printf("%d\t",i_set[i]);
}

for(i=0;i<n;i++)
{
if(bita[i]==1&&bitb[i]==0)
{
d_a[i]=1;
}
else
{
d_a[i]=0;
}
}
printf("SET A-B:\n");
for(i=0;i<n;i++)
{
printf("%d\t",d_a[i]);
}
getch();
}