#include <stdio.h>
#include <conio.h>
#include <string.h>

struct employee
{
int id;
char name[10];

};

struct employee e[4]={{9,"marina"},{1,"marsel"},{5,"sandy"},{6,"K"}};

void main(void)
{


int i,j;
int k;
int flag;
int temp1;
char temp2[10];

clrscr();

for(j=1;j<4;j++)
{
flag=0;
for(i=0;i<=(4-j-1);i++)
{
if(e[i].id>e[i+1].id)
{
temp1=e[i].id;
e[i].id=e[i+1].id;
e[i+1].id=temp1;

strcpy(temp2,e[i].name);
strcpy(e[i].name,e[i+1].name);
strcpy(e[i+1].name,temp2);
flag=1;
}
}
if(flag==1)
break;
}


for(k=0;k<4;k++)
{
printf("%d",e[k].id);
printf("\n");
printf("%s",e[k].name);
printf("\n");
printf("\n");


}

getch();
}