#include <stdio.h>
#include <conio.h>
#include <string.h>

#define s 3
#define m 5

void selcsort(char arr[s][m],int size);


void main(void)
{
char arr[s][m]={"b","z","c"};

int i;
clrscr();

selcsort(arr,s);
printf("\n");


for(i=0;i<s;i++)
{
printf("%s",arr[i]);
printf("\n");
}








getch();
}

void selcsort(char arr[s][m],int n)
{
int i,j,index=0;

for(i=0;i<n-1;i++)
{
index=i;
int x;
char temp[m];

   for(j=i+1;j<n;j++)
      {
      x=strcmp(arr[j],arr[index]);
      if(x<0)
	{
	index=j;
	}

      }

  // swap(&arr[i],&arr[index]);
  strcpy(temp,arr[i]);
  strcpy(arr[i],arr[index]);
  strcpy(arr[index],temp);



}

}

/*void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
} */