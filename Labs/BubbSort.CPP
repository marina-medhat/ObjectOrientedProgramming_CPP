#include <stdio.h>
#include <conio.h>

#define n 5

void sort(int *arr,int s);
void swap(int *a,int *b);


void main(void)
{

int k;
int arr[n]={3,6,8,9,0};
int *ptr;
ptr=arr;
clrscr();
flushall();
sort(ptr,n);
flushall();


for(k=0;k<n;k++)
{
printf("%d",arr[k]);
printf("\n");
}
getch();
}

void sort(int *arr,int s)
{
int i,j;
int sorted=0;
for(i=0;((i<s-1)&&(!sorted));i++)
{
sorted=1;



    for(j=s-1;j<i;j--)
    {
      if(arr[j]<arr[j-1])
      {
      swap(&arr[j],&arr[j-1]);

      sorted=0;
      }

    }
    if(sorted==0)
    break;

}
}

void swap(int* a,int* b)
{
int temp;
temp = *a;
*a = *b;
*b =temp;

}