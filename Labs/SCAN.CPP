#include <stdio.h>
#include <conio.h>

#define left 75
#define right 77
#define end  79
#define home 71
#define enter 13
#define esc 27
#define null 0
#define s 10



void display(char *ptr,int size);



void main(void)
{
int col=1;
int row=4;
char arr[10];
char key;
int pos=0;
int count=0;
int termination=0;
char *ptr;
char ch;
ptr=arr;

clrscr();
gotoxy(col,row);

do
{
key=getch();

    switch(key)
    {
      default:
	  if(pos<s)
	  {
	    if(count!=0&&pos<count)
	    {
	      gotoxy((col+(pos*2)),row);
	      printf("%c",key);
	      arr[pos]=key;
	      pos++;
	      gotoxy((col+(pos*2)),row);


	    }
	    else
	    {
	      gotoxy((col+(count*2)),row);
	      printf("%c",key);
	      arr[count]=key;
	      count++;

	    }

	  }
	  else
	  {
	  termination=1;
	  }
	  break;

      case null:
	  key=getch();
	  switch(key)
	  {
	    case left:
		pos--;
		if(pos<0)
		  pos=0;

		gotoxy(col+(2*pos),row);
		break;

	    case right:
		pos++;
		if(pos>s)
		  pos=s-1;
		gotoxy(col+(2*pos),row);
		break;

	    case end:
		pos=count;
		gotoxy((col+(2*pos)),row);
		break;

	    case home:
		pos=0;
		gotoxy((col+(2*pos)),row);
		break;

	  }
	  break;

      case esc:
	   termination=1;
	   break;

      case enter:
	   display(ptr,count);
	   printf("\n");
	   printf("end of ur program ;) ,, plz press any ket ");
	   getch();
	   termination=1;
	   break;

    }


}while(!termination);



}

void display(char *ptr,int size)
{
int j;
int col=50,row=1;
for(j=0;j<size;j++)
{
 gotoxy((col+(j*2)),row);
 printf("%c",*(ptr+j));

}


}

/*void writechar(int pos,int )
{
   gotoxy((col+(count*2)),row);
	  if(i<s)
	  {
	  printf("%c",key);
	  arr[i]=key;
	  i++;
	  count++;
	  }

}*/