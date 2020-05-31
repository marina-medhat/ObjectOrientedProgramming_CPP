#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class Stack
{
  int top,size;
  int *stk;
  static int counter;


  public:
   Stack();
   Stack(int s);
   ~Stack();
   Stack(Stack &s);
   Stack & operator=(Stack &s);
   Stack operator+(Stack &s);
   int isempty();
   int isfull();
   int push(int data);
   int pop(int &data);
   void peak();
   friend void viewcontent(Stack s);
   static int getcounter()
   {
     return counter;
   }


};

int Stack::counter=0;

Stack::Stack()
{
 cout<<"the constructor is create initialization"<<endl;
 top=0;
 size=10;
 stk=new int[size];
 counter++;
}

Stack::Stack(int s)
{
 cout<<"the constructor is create initialization"<<endl;
 top=0;
 size=s;
 stk=new int[size];
 counter++;

}


Stack::Stack(Stack &s)
{
  top=s.top;
  size=s.size;
  stk=new int[size];

  for(int i=0;i<top;i++)
  {
   stk[i]=s.stk[i];
  }

  cout<<"this is the copy constructor "<<endl;
}


Stack& Stack::operator=(Stack &s)
{
  this->top=s.top;
  this->size=s.size;

  delete []stk;

  stk=new int[size];

  for(int i=0;i<top;i++)
  {
  stk[i]=s.stk[i];
  }

  return *this;

}


Stack Stack::operator+(Stack &s)
{
  Stack temp(size+s.size);
  temp.top=top+s.top;

  for(int i=0;i<top;i++)
  {
   temp.stk[i]=stk[i];
  }

  for(int j=0;j<s.top;j++)
  {
   temp.stk[j+top]=s.stk[j];
  }

  return temp;
}

int Stack::isempty()
{
  return !top;
}

int Stack::isfull()
{
  return top==size ;
}

int Stack::push(int data)
{
  if(isfull())
    return 0;

    stk[top]=data;
    top++;
    return 1;
}

int Stack::pop(int &data)
{
  if(isempty())
    return 0;

    top--;
    data=stk[top];
    return 1;
}

void Stack::peak()
{
  cout<<stk[top-1]<<endl;
}


void viewcontent(Stack s)
{
 int i;

 for(i=0;i<s.top;i++)
 {
   cout<<s.stk[i]<<endl;
 }
}

Stack::~Stack()
{
 if(stk)
   delete [] stk;

 counter--;
 cout<<"the destractor is done ;) "<<endl;
}

void main(void)
{
 clrscr();
 int siz;
 int ch,c;
 int num;
 int check;
 int termination=0;

 cout<<"counter is :"<<Stack::getcounter()<<endl;

 cout<<"plz enter size of your stack1 :"<<endl;
 cin>>siz;

 Stack s1(siz);
 cout<<"counter is :"<<Stack::getcounter()<<endl;


 cout<<"plz enter size of your stack2 :"<<endl;
 cin>>siz;

 Stack s2(siz);
 cout<<"counter is :"<<Stack::getcounter()<<endl;

 /*Stack s3();
 cout<<"counter is :"<<Stack::getcounter()<<endl;*/

 while(!termination)
 {
 cout<<"press number of your choice :"<<endl;
 cout<<"1-push a number in stack1"<<endl;
 cout<<"2-pop a number in stack1"<<endl;
 cout<<"3-peak a number in stack1"<<endl;
 cout<<"4-view content of stack1"<<endl;
 cout<<"5-push a number in stack2"<<endl;
 cout<<"6-pop a number in stack2"<<endl;
 cout<<"7-peak a number in stack2"<<endl;
 cout<<"8-view content of stack2"<<endl;
 cout<<"9-to equal 2 stacks "<<endl;
 cout<<"10-to add 2 stacks "<<endl;
 cout<<"11-continue or not ?"<<endl;

 cin>>ch;

 switch(ch)
 {
   case 1:
       cout<<"plz enter a number you want to push it in stack1 :"<<endl;
       cin>>num;
       check=s1.push(num);
       if(check==0)
	cout<<"not pushed"<<endl;
       else
	cout<<"pushed"<<endl;
	getch();
       break;

   case 2:
       check=s1.pop(num);
       if(check==0)
	cout<<"not poped"<<endl;
       else
	cout<<"poped number"<<num<<endl;
	getch();
       break;

   case 3:
	cout<<"peaked number"<<endl;
	s1.peak();
	getch();
       break;

   case 4:
       cout<<"the data in stack1 now is :"<<endl;
       viewcontent(s1);
       getch();
       break;

   case 5:
       cout<<"plz enter a number you want to push it in stack2 :"<<endl;
       cin>>num;
       check=s2.push(num);
       if(check==0)
	cout<<"not pushed"<<endl;
       else
	cout<<"pushed"<<endl;
	getch();
       break;

   case 6:
       check=s2.pop(num);
       if(check==0)
	cout<<"not poped"<<endl;
       else
	cout<<"poped number"<<num<<endl;
	getch();
       break;

   case 7:
	cout<<"peaked number"<<endl;
	s2.peak();
	getch();
       break;

   case 8:
       cout<<"the data in stack2 now is :"<<endl;
       viewcontent(s2);
       getch();
       break;

   case 9:
       cout<<"1- s1=s2"<<endl;
       cout<<"2- s2=s1"<<endl;
       cin>>c;
       if(c==1)
	 s1=s2;
       else
	 s2=s1;

       break;


   case 10:
	cout<<"the data in the result s1+s2 now is :"<<endl;
	viewcontent(s1+s2);
	getch();
	break;

   case 11:
       cout<<"if you want to continue plz enter 0 .. "<<endl;
       cout<<"to end press any number .. "<<endl;
       cin>>termination;
       break;

  }



 }








}