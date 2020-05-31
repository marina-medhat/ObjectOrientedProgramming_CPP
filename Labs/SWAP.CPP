#include <stdio.h>
#include <conio.h>

void swap(int * x,int * y);

void main(void)
{
clrscr();
int a=4;
int b=5;

swap(& a,& b);

printf("a= %d ,,, b= %d",a,b);
printf("\n");
getch();

}

void swap(int *x,int * y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;

}