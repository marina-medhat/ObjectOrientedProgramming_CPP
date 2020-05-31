#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>


void main(void)
{
clrscr();
int **pptr;
int n1 , n2;
int i,j;
pptr=(int **)malloc(2*sizeof(int*));

printf("plz enter size of first array  ");
scanf("%d",&n1);
pptr[0]=(int *)malloc(n1*sizeof(int));


printf("plz enter size of second array  ");
scanf("%d",&n2);
pptr[1]=(int *)malloc(n2*sizeof(int));

printf("plz enter data of first array:");
printf("\n");
for(i=0;i<2;i++)
{
   for(j=0;j<n1;j++)
   {
    scanf("%d",&pptr[i][j]);
    printf("\n");
   }
}
printf("\n");
printf("the data of first array");
for(i=0;i<2;i++)
{
   for(j=0;j<n1;j++)
   {
    printf("%d",*(pptr[i][j]));
    printf("\n");
   }
}



printf("plz enter data of second array:");
printf("\n");
for(i=0;i<2;i++)
{
   for(j=0;j<n2;j++)
   {
    scanf("%d",&pptr[i][j]);
    printf("\n");
   }
}
printf("\n");
printf("the data of first array");
for(i=0;i<2;i++)
{
   for(j=0;j<n2;j++)
   {
    printf("%d",*pptr[i][j]);
    printf("\n");
   }
}


}