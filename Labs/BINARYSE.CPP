#include <stdio.h>
#include <conio.h>

#define n 5

void scanarr(int *arr,int size);
int binarySearch(int *arr,int size,int key);

void main(void)
{
int arr[n];
int result,k;

clrscr();

scanarr(arr,n);
printf("\n");
printf("plz enter a key to search about it :");
scanf("%d",&k);
printf("\n");
result= binarySearch(arr,n,k);
printf("\n");
printf("the result : %d",result);
printf("\n");
if(result>-1)
{
printf("found");
printf("\n");
}
else
{
printf("not found");
printf("\n");
}
getch();
}

void scanarr(int *arr,int size)
{
int i;
printf("plz enter numbers of array (sorted array) : ");
printf("\n");

for(i=0;i<size;i++)
{
printf("plz enter a number :");
scanf("%d",&arr[i]);
printf("\n");
}

}

int binarySearch(int *arr,int size,int key)
{
int h,l,mid;
l=0;
h=size;

while(l<h)
{
mid=(h+l)/2;

if(key==arr[mid])
{
  return mid;
}
else if(key >arr[mid])
{
l=mid+1;
}
else if(key<arr[mid])
{
h=mid-1;
}
}
return -1;

}