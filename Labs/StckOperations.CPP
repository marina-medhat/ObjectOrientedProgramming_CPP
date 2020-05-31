#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class Stack
{
  int top;
  int size;
  int *stk;

  public:
  Stack();
  Stack(Stack &s);
  ~Stack();
  Stack& operator=(Stack &s);

};

Stack::Stack()
{
  top=0;
  size=10;
  stk=new int[size];

  cout<<"this is the default constructor "<<endl;
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


Stack::~Stack()
{
  cout<<"this is the destructor is done ;)"<<endl;
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


void main(void)
{

 clrscr();
 Stack s1(,s2;




}