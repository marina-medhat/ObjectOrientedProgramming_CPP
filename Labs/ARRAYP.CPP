#include <stdio.h>
#include <conio.h>
#define s 10

void scanarr(int *ptr,int size);
void displayarr(int *ptr , int size);

void main(void)
{
clrscr();
int arr[10];
int *ptr;
ptr=arr;

scanarr(ptr,s);
displayarr(ptr,s);

getch();
}

void scanarr(int *ptr,int size)
{
int i;
printf("write numbers of array");
printf("\n");
for(i=0;i<size;i++)
{
printf("plz enter a number :");
scanf("%d",(ptr+i));
printf("\n");
}

}

void displayarr(int *ptr , int size)
{
int j;
printf("the numbers in array are :");
printf("\n");
for(j=0;j<size;j++)
{
printf("%d",*(ptr+j));
//printf("%d",(ptr[j]));
printf("\n");

}

}