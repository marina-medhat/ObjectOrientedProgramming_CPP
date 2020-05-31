#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>

template <class T>

class Stack
{
 private:
  int top;
  int size;
  T *stk;

  static int counter;

 public:
  Stack()
  {
   top=0;
   size=10;
   stk=new T[size];
   counter++;
   cout<<"stack default constructor "<<endl;
  }

  Stack(int s)
  {
   top=0;
   size=s;
   stk=new T[size];
   counter++;
   cout<<"stack constructor with parameter"<<endl;
  }

  ~Stack()
  {
   if(stk)
     delete [] stk;
   counter--;

   cout<<"stack dest"<<endl;
  }

  Stack(Stack &s);
  int push(T data);
  int pop(T &data);
  Stack& operator=(Stack &s);
  int isempty();
  int isfull();
  friend void viewcontent(Stack &s);

  static int getcounter()
  {
    return counter;
  }

};

  template <class T>
  int Stack<T>::counter=0;

  template <class T>
  Stack<T>::Stack(Stack<T> &s)
  {
   top=s.top;
   size=s.size;
   stk=new T[size];

   for(int i=0;i<top;i++)
   {
    stk[i]=s.stk[i];
   }


  cout<<"this is the copy constructor "<<endl;

  }

  template <class T>
  Stack<T>& Stack<T>::operator=(Stack<T> &s)
  {
    this->top=s.top;
    this->size=s.size;

    delete []stk;

    stk=new T[size];

    for(int i=0;i<top;i++)
    {
     stk[i]=s.stk[i];
    }

  return *this;

  }

  template <class T>
  int Stack<T>::isempty()
  {
    return !top;
  }

  template <class T>
  int Stack<T>::isfull()
  {
     return top==size ;
  }


  template <class T>
  int Stack<T>::push(T data)
  {
    if(isfull())
    return 0;

    stk[top]=data;
    top++;
    return 1;
  }


  template <class T>
  int Stack<T>::pop(T &data)
  {
    if(isempty())
    return 0;

    top--;
    data=stk[top];
    return 1;
  }

  template <class T>
  void viewcontent(Stack<T> &s)
  {
   for(int i=0;i<s.top;i++)
   {
    cout<<s.stk[i]<<endl;
   }
  }

void main()
{

 clrscr();
 Stack<int> s1(5);
 cout<<s1.getcounter()<<endl;
 cout<<Stack<int>::getcounter()<<endl;

 Stack<float> s2(12);
 cout<<s2.getcounter();




getch();
}
