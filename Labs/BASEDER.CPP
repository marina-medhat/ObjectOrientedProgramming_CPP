#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class base
{
  protected:
   int a;
   int b;

  public:
    base();
    base(base &b);
    base(int);
    ~base();
    void seta(int);
    void setb(int);
    int calcsum();
};


class derived:public base
{
  int c;

  public:
    derived();
    derived(derived &cp);
    derived(int);
    ~derived();
    void setc(int);
    int getcc();
    int calcsum();
};

    base::base()
    {
     a=b=0;
     cout<<"base default constructor"<<endl;
    }

    base::base(base &cp)
    {
     a=cp.a;
     b=cp.b;
     cout<<"base copy constructor"<<endl;
    }

    base::base(int x)
    {
     a=b=x;
     cout<<"base constructor with parameter"<<endl;
    }

    base::~base()
    {
     cout<<"base destructor"<<endl;
    }

    void base::seta(int x)
    {
      a=x;
    }

    void base::setb(int x)
    {
     b=x;
    }

    int base::calcsum()
    {
     return a+b;
    }


    derived::derived()
    {
     a=b=c=0;
     cout<<"derived deafult constructor"<<endl;
    }

    derived::derived(derived &cp)
    {
     a=cp.a;
     b=cp.b;
     c=cp.c;
     cout<<"derived copy constructor"<<endl;
    }

    derived::derived(int x):base(5)
    {
     c=x;
     cout<<"derived constructor with parameters"<<endl;
    }

    derived::~derived()
    {
     cout<<"derived destructor"<<endl;
    }

    void derived::setc(int x)
    {
      c=x;
    }

    int derived::getcc()
    {
     return c;
    }

    int derived::calcsum()
    {
     return base::calcsum()+c;
    }

void main(void)
{
 clrscr();
 base b1(5);
 cout<<"the sum of a,b is "<<b1.calcsum()<<endl;

 derived d(6);
 cout<<"the sum of a,b,c is "<<d.calcsum()<<endl;


 getch();
}