#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>


class geoshape
{
 protected:
  float dim1;
  float dim2;

 public:
  geoshape();
  geoshape(float);
  geoshape(float,float);
  ~geoshape();
  void setdim1(float);
  void setdim2(float);
  float getdim1();
  float getdim2();

  virtual float calcarea()=0;
};

class rect:public geoshape
{

  public:
    rect():geoshape(0,0){}
    rect(float w,float h):geoshape(w,h){}
    ~rect()
    {
     cout<<"geoshape dest"<<endl;
    }

    float calcarea()
    {
     return dim1*dim2;
    }

};

class square:public rect
{

  public:
  square():rect(0,0){}
  square(float l):rect(l,l){}
  ~square()
  {
   cout<<"square dest"<<endl;
  }

  float calcarea()
  {
   return dim1*dim2;
  }

  void setlength(float l)
  {
   dim1=dim2=l;
  }

};

class triang:public geoshape
{
 public:
  triang():geoshape(0,0){}
  triang(float b,float a):geoshape(a,b){}
  ~triang()
  {
   cout<<"triang dest"<<endl;
  }

  float calcarea()
  {
   return 0.5*dim1*dim2;
  }

};

class circle:public geoshape
{
  public:
   circle():geoshape(0,0){}
   circle(float r):geoshape(r,r){}
   ~circle()
   {
    cout<<"circle dest"<<endl;
   }

   float calcarea()
   {
    return dim1*dim2*3.14;
   }

   void setrad(float f)
   {
   dim1=dim2=f;
   }

};


  geoshape::geoshape()
  {
   dim1=0;
   dim2=0;

   cout<<"geoshape default constructor"<<endl;
  }

  geoshape::geoshape(float f)
  {
   dim1=f;
   dim2=f;
   cout<<"geoshape constructor with one parameter"<<endl;
  }

  geoshape::geoshape(float d1,float d2)
  {
   dim1=d1;
   dim2=d2;
   cout<<"geoshape constructor with 2 parameters"<<endl;
  }


  geoshape::~geoshape()
  {
   cout<<"geoshape destructor"<<endl;
  }


  void geoshape::setdim1(float d)
  {
    dim1=d;
  }


  void geoshape::setdim2(float d)
  {
   dim2=d;
  }

  float geoshape::getdim1()
  {
   return dim1;
  }

  float geoshape::getdim2()
  {
   return dim2;
  }

  float clacsumareas(geoshape *p1,geoshape *p2,geoshape *p3,geoshape *p4)
  {
   float sum;
   sum=(p1->calcarea())+(p2->calcarea())+(p3->calcarea())+(p4->calcarea());

   return sum;
  }

void main()
{

 clrscr();
 rect r(4,5);
 triang t(7,2);
 circle c(3);
 square s(6);
 cout<<"the area of rectangle :"<<r.calcarea()<<endl;
 cout<<"the area of triang :"<<t.calcarea()<<endl;
 cout<<"the area of circle :"<<c.calcarea()<<endl;
 cout<<"the area of square :"<<s.calcarea()<<endl;
 float f;
 f=clacsumareas(&r,&t,&c,&s);
 cout<<"sum of areas ="<<f<<endl;


 getch();


}