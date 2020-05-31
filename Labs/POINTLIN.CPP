#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>

class shape
{
 private:
  int color;

 public:
   shape();
   shape(int);
   ~shape();
   void setColor(int);
   int getcolor();
   virtual void draw()=0;
};

class poin
{
 private:
  int x,y;

 public:
  poin();
  poin(int a);
  poin(int a, int b);
  poin(poin &p);
  ~poin();
  void setx(int a);
  void sety(int b);
  void setxy(int a,int b);
  int getx();
  int gety();
  void print();

};


class lin:public shape
{
 private:
  poin start;
  poin end;

 public:
  lin();
  lin(int x1,int y1,int x2,int y2,int c);
  lin(lin &l);
  ~lin();
  void setstart(poin p);
  void setend(poin p);
  void print();
  void draw();

};

class circl:public shape
{
  private:
   int rad;
   poin center;

  public:
   circl();
   circl(int x1,int y1,int r, int c);
   circl(poin p,int r);
   circl(circl & c);
   ~circl();
   void setcenter(int x1,int y1);
   void setcenter(poin p);
   void setrad(int r);
   poin getcenter();
   int getrad();
   void print();
   void draw();
};

class rectan:public shape
{
  private:
   poin ul;
   poin lr;

  public:
   rectan();
   rectan(rectan &r);
   rectan(int x,int y,int z, int k, int c);
   ~rectan();
   void setul(poin p);
   void setlr(poin p);
   void setrect(poin p1,poin p2);
   poin getul();
   poin getlr();
   void print();
   void draw();

};

class pic
{
 private:
  int cnum;
  int rnum;
  int lnum;

  circl *cptr;
  rectan *rptr;
  lin *lptr;


 public:
  pic();
  pic(int,int,int,circl *c,rectan *r,lin *l);
  ~pic();
  void setcircles(int num,circl *ptr);
  void setrects(int num,rectan *ptr);
  void setlines(int num,lin *ptr);
  void paint();
};



  shape::shape()
  {
   color=0;
   cout<<"shape default constructor"<<endl;
  }

  shape::shape(int c)
  {
   color=c;
   cout<<"shape constructor with parameters"<<endl;
  }

  shape::~shape()
  {
   cout<<"shape destructor"<<endl;
  }

  void shape::setColor(int x)
  {
   color=x;
  }

  int shape::getcolor()
  {
   return color;
  }

  poin::poin()
  {
   x=y=0;
   cout<<"(point) the default constractor is done "<<endl;
  }

  poin::poin(int a)
  {
   x=y=a;
   cout<<"(point) constractor by 1 parameters is done"<<endl;
  }

  poin::poin(int a, int b)
  {
   x=a;
   y=b;
   cout<<"(point) constractor by 2 parameters is done "<<endl;
  }

  poin::poin(poin &p)
  {
   x=p.x;
   y=p.y;
   cout<<"(point) copy constractor is done "<<endl;
  }

  poin::~poin()
  {
    cout<<"(point) the destractor is done "<<endl;
  }

  void poin::setx(int a)
  {
   x=a;
  }

  void poin::sety(int b)
  {
   y=b;
  }

  void poin::setxy(int a,int b)
  {
    x=a;
    y=b;
  }

  int poin::getx()
  {
    return x;
  }

  int poin::gety()
  {
    return y;
  }

  void poin::print()
  {
    cout<<"x= "<<x<<endl;
    cout<<"y= "<<y<<endl;
  }


  lin::lin()
  {
    start.setxy(0,0);
    end.setxy(0,0);
    cout<<"(line) default constratcor is done "<<endl;
  }

  lin::lin(int x1,int y1,int x2,int y2,int c)
  {
    start.setxy(x1,y1);
    end.setxy(x2,y2);
    setcolor(c);
    cout<<"(line) constractor with parameters is done"<<endl;
  }

  lin::lin(lin &l)
  {
   start=l.start;
   end=l.end;
  }

  lin::~lin()
  {
    cout<<"(line) destractor is done "<<endl;
  }

  void lin::setstart(poin p)
  {
    start=p;
  }
  void lin::setend(poin p)
  {
    end=p;

  }

  void lin::print()
  {
     cout<<"start point :"<<endl;
     start.print();

     cout<<"end point :"<<endl;
     end.print();

  }

  void lin::draw()
  {
   setcolor(80);
   line(start.getx(),start.gety(),end.getx(),end.gety());
  }


   circl::circl()
   {
    rad=0;
    center.setxy(0,0);
    cout<<"(circle) default constractor is done "<<endl;
   }

   circl::circl(int x1,int y1,int r, int c)
   {
    rad=r;
    center.setxy(x1,y1);
    setcolor(c);
    cout<<"(circle) constractor with parameters is done"<<endl;
   }

   circl::circl(poin p,int r)
   {
    rad=r;
    center=p;
    cout<<"(circle) constractor with parameters is done"<<endl;
   }

   circl::circl(circl & c)
   {
    rad=c.rad;
    center=c.center;
    cout<<"(circle) copy constractor is done"<<endl;
   }

   circl::~circl()
   {
    cout<<"the destractor is done"<<endl;
   }

   void circl::setcenter(int x1,int y1)
   {
    center.setxy(x1,y1);
   }

   void circl::setcenter(poin p)
   {
    center=p;
   }

   void circl::setrad(int r)
   {
    rad=r;
   }

   poin circl::getcenter()
   {
    return center;
   }

   int circl::getrad()
   {
    return rad;
   }

   void circl::print()
   {
    cout<<"circle data :"<<endl;
    cout<<"radius :"<<rad<<endl;
    cout<<"center :";
    center.print();
   }

   void circl::draw()
   {
     setcolor(90);
     circle(center.getx(),center.gety(),getrad());
   }


   rectan::rectan()
   {
    ul.setxy(0,0);
    lr.setxy(0,0);
   }

   rectan::rectan(int x,int y,int z, int k, int c)
   {
   setcolor(c);
   ul.setxy(x,y);
   lr.setxy(z,k);

   }

   rectan::rectan(rectan &r)
   {
    ul=r.ul;
    lr=r.lr;
   }

   rectan::~rectan()
   {
    cout<<"(rectang) destractor is done "<<endl;
   }

   void rectan::setul(poin p)
   {
    ul=p;
   }

   void rectan::setlr(poin p)
   {
    lr=p;
   }

   void rectan::setrect(poin p1 ,poin p2)
   {
     ul=p1;
     lr=p2;
   }

   poin rectan::getul()
   {
    return ul;
   }

   poin rectan::getlr()
   {
    return lr;
   }

   void rectan::print()
   {
    cout<<"ul :";
    ul.print();
    cout<<"lr :";
    lr.print();
   }

   void rectan::draw()
   {
     setcolor(50);
     rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
   }


   pic::pic()
   {
      cnum=rnum=lnum=0;
      cptr=NULL;
      rptr=NULL;
      lptr=NULL;
      cout<<"pic default constructor"<<endl;
   }


   pic::pic(int cn,int rn,int ln,circl *c ,rectan *r,lin *l)
   {
     cnum=cn;
     rnum=rn;
     lnum=ln;

     cptr=c;
     rptr=r;
     lptr=l;

     cout<<"pic constructor with parameters "<<endl;

   }


   pic::~pic()
   {
     cout<<"pic destructor"<<endl;
   }


   void pic::setcircles(int num,circl *ptr)
   {
     cnum=num;
     cptr=ptr;
   }


   void pic::setrects(int num,rectan *ptr)
   {
     rnum=num;
     rptr=ptr;
   }


   void pic::setlines(int num,lin *ptr)
   {
     lnum=num;
     lptr=ptr;
   }


   void pic::paint()
   {
     int i;
     for(i=0;i<cnum;i++)
     {
      cptr[i].draw();
     }

     for(i=0;i<rnum;i++)
     {
      rptr[i].draw();
     }

     for(i=0;i<lnum;i++)
     {
      lptr[i].draw();
     }

   }


void main()
{
   clrscr();
   int gdriver=DETECT,gmode,errorCode;

   initgraph(&gdriver,&gmode,"..\\ bgi");
   errorCode=graphresult();

   if(errorCode!=grOk)
   {
    cout<<"can not initialize graphics"<<endl;

   }
   else
   {
    pic mypic;
    circl carr[3]={circl(50,50,50,2),circl(200,100,100,1),circl(420,50,30,12)};
    rectan rarr[2]={rectan(30,40,170,100,11),rectan(420,50,500,300,12)} ;
    lin larr[2]={lin(420,50,300,300,3),lin(40,500,500,400,5)};

    mypic.setcircles(3,carr);
    mypic.setrects(2,rarr);
    mypic.setlines(2,larr);

    mypic.paint();

    getch();
    closegraph();

   }

      getch();

}
