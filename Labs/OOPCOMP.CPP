#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>


class Complex
{
private:
   float real;
   float imagin;

public:
   Complex()
   {
     real=imagin=0;
     cout<<"it is the constructor creation done ;) (without parameters) "<<endl;
   }

   Complex(float r, float i)
   {
     real=r;
     imagin=i;
     cout<<"it is the constructor creation done ;) (with parameters) "<<endl;
   }

   Complex(Complex &c)
   {
     real=c.real;
     imagin=c.imagin;
     cout<<"it is the copy constructor creation done ;) "<<endl;
   }



   float getreal();

   float getimagin();

   void setreal(float re);

   void setimagin(float im);

   void print();

   friend istream& operator>>(istream&,Complex& c);
   friend ostream& operator<<(ostream&,Complex& c);


   //int operator==(Complex & c);

   //Complex& operator=(Complex & c);

   //Complex  operator+(Complex & c);

   ~Complex()
   {
     cout<<"it is the destructor ,, end of object ;) "<<endl;
   }


};


   istream& operator>>(istream& in,Complex& c)
   {
   cout<<"enter data of a complex:"<<endl;
   in>>c.real;
   in>>c.imagin;

   cout<<"thanks"<<endl;

   return in;
   }


   ostream& operator<<(ostream& out,Complex& c)
   {
   out<<"the value of complex :"<<endl;
   c.print();

   return out;
   }




   float Complex::getreal()
   {
     return real;
   }

   float Complex::getimagin()
   {
    return imagin;
   }

   void Complex::setreal(float re)
   {
      real=re;
   }

   void Complex::setimagin(float im)
   {
    imagin=im;
   }

   void Complex::print()
   {

     if(imagin==0)
       cout<<real<<"+"<<endl;
     else if(imagin < 0 )
       cout<<real<<imagin<<"i"<<endl;
     else if(imagin ==1)
       cout<<real<<"+i"<<endl;
     else
       cout<<real<<"+"<<imagin<<"i"<<endl;
   }

  /* Complex& Complex::operator=(Complex & c)
   {
     this->real=c.real;
     this->imagin=c.imagin;

     return *this;

   } */

  /* Complex Complex::operator+(Complex & c)
   {
     Complex  temp(real+c.real , imagin+c.imagin);
     return temp;

   } */

   /*int Complex::operator==(Complex & c)
   {
    return (real==c.real && imagin==c.imagin);

   } */






/*Complex subcomplex(Complex c1 ,Complex c2)
{
  float re1,re2,im1,im2;
  float subr,subi;
  Complex nc;

  im1=c1.getimagin();
  re1=c1.getreal();

  im2=c2.getimagin();
  re2=c2.getreal();

  subr=re1-re2;
  subi=im1-im2;

  nc.setreal(subr);
  nc.setimagin(subi);

  return nc;
} */


/*Complex addcomplex(Complex c1 ,Complex c2)
{
  float re1,re2,im1,im2;
  float sumr,sumi;
  Complex sc;

  im1=c1.getimagin();
  re1=c1.getreal();

  im2=c2.getimagin();
  re2=c2.getreal();

  sumr=re1+re2;
  sumi=im1+im2;

  sc.setreal(sumr);
  sc.setimagin(sumi);

  return sc;
} */




void main(void)
{

 clrscr();
 float fr,fi;
 Complex c1,c2,result;
 cout<<"plz enter a real number 1 :"<<endl;
 cin>>fr;
 c1.setreal(fr);

 cout<<"plz enter a imagin number 1 :"<<endl;
 cin>>fi;
 c1.setimagin(fi);
 c1.print();
 cout<<"--------------------------------------"<<endl;

/*cout<<"plz enter a real number 2 :"<<endl;
 cin>>fr;
 c2.setreal(fr);

 cout<<"plz enter a imagin number 2 :"<<endl;
 cin>>fi;
 c2.setimagin(fi);
 c2.print();
 cout<<"--------------------------------------"<<endl;

 result=c1+c2;

 result.print();
 cout<<"--------------------------------------"<<endl;

 printf("to make c1=c2 :\n");
 c1=c2;
 printf("the value of c1 now :\n");
 c1.print();
 cout<<"--------------------------------------"<<endl;

 printf("to compare if c1=c2 !");
 if(c1==c2)
  cout<<"equal"<<endl;
 else
  cout<<"not equal"<<endl;

 cout<<"--------------------------------------"<<endl;
 Complex c4;
 c4 = 1.3+c1; */


/* result.print();
 cout<<"--------------------------------------"<<endl;
*/


cout<<"now we will use cin>>c1 "<<endl;
cin>>c1;


cout<<"now we will use cout<<c1 "<<endl;
cout<<c1;


getch();
}