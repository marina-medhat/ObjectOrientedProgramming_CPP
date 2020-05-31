#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>

#define enter 13
#define up 72
#define down 80
#define esc 27
#define null 0
#define hl 0x70
#define normal 0x07

void print(int pos);

struct employee
{
char name[10];
char address[10];
int phone;
int id;
};

void main(void)
{
clrscr();
struct employee *sptr;
int n,indx;
int k;
int termination=0;
char key;
int pos=0;
int backk=0;
int counter=0;
int i,j;
int l,idd;






printf("plz enter number of employees : ");
scanf("%d",&n);
printf("\n");

sptr=(struct employee *) malloc(n*sizeof(struct employee));

for(i=1;i<n;i++)
{
(sptr+i)->id=0;
}


do
{
 clrscr();
  printf("plz enter the index of employee you want to add :");
  scanf("%d",&indx);
  printf("\n");
  counter++;

  clrscr();
  printf("and enter the id of this employee  :");
  scanf("%d",&idd);
  (sptr+indx)->id=idd;
  printf("\n");

do
{
backk=0;
 /* printf("plz enter the index of employee you want to add :");
  scanf("%d",&ind);
  printf("\n"); */

  clrscr();
  print(pos);
  key=getch();

  switch(key)
  {
    case null:
     key=getch();
     switch(key)
     {
	    case up:
	      pos--;
	      if(pos<0)
		pos=4;
	      break;

	    case down:
	      pos++;
	      if(pos>4)
		pos=0;
	      break;
     }
     break;

   case enter:
      switch(pos)
      {
	   case 0:
	      clrscr();
	      printf("plz enter name :");
	      flushall();
	      scanf("%s",&((sptr+(indx))->name));
	      break;

	   case 1:
	      clrscr();
	      printf("plz enter address :");
	      flushall();
	      scanf("%s",&((sptr+(indx))->address));
	      break;

	   case 2:
	      clrscr();
	      printf("plz enter phone :");
	      flushall();
	      scanf("%d",&((sptr+(indx))->phone));
	      break;

	   case 3:
	      backk=1;
	      break;

	   case 4:
	      clrscr();
	       flushall();
	       for(j=0;j<n;j++)
	      {
		  flushall();
		if((sptr+j)->id != 0)
		 {
		   printf("%s",(sptr+j)->name);
		   printf("\n");
		   printf("%s",(sptr+j)->address);
		   printf("\n");
		   printf("%d",(*(sptr+j)).phone);
		   printf("\n");



		 }
		   printf("\n");
		  continue;

	      }
	      getch();
	      break;
      }
      break;




  }






}while(!backk);
clrscr();
printf("plz enter esc to terminate prog or press any key to continue ;)");
key=getch();

if(key==esc)
termination=1;

}while(!termination);
}


/*
void print(void)
{

char menu[5][10]={"name","address","phone","back","display"};
int i;
int col=1;
int row=4;

   for(i=0;i<5;i++)
   {
    gotoxy(col,(row+i));
    printf("%s",menu[i]);
   }



} */

void print(int pos)
{
int col=4,row=1,i;

//char menu[5][10]={"new","display","enterID","exit","edit"};
char menu[5][10]={"name","address","phone","back","display"};

for(i=0;i<5;i++)
{
gotoxy(col,(row+i));
if(i==pos)
  textattr(hl);
cprintf("%s",menu[i]);
textattr(normal);

}

}