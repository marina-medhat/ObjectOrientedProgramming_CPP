#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class myarray
{
 private:
  int size;
  int *data;

 public:
   myarray(int s);
   ~myarray();
   void addelement(int indx,int d);
   void setarray();
   int& operator[](int indx);
   void resize(int ns);

};

   myarray::myarray(int s)
   {
     size=s;
     data= new int[s];
     cout<<"constractor"<<endl;
   }

   myarray::~myarray()
   {
     delete [] data;
     cout<<"destractor"<<endl;
   }

   void myarray::addelement(int indx,int d)
   {
     data[indx]=d;
   }

   void myarray::setarray()
   {
    int i;
    for(i=0;i<size;i++)
    {
      cout<<"plz enter a number :"<<endl;
      cin>>data[i];
    }
   }


   int& myarray::operator[](int indx)
   {
     return data[indx];
   }


   void myarray::resize(int ns)
   {
    int *temp;
    temp=new int[ns];

    if(ns<size)
     cout<<"some data has been lost"<<endl;



    for(int j=0;j<size;j++)
    {
      temp[j]=data[j];
    }

    size=ns;
    delete []data;
    data=temp;

   }


void main(void)
{

 clrscr();
 myarray m(4);
 m.addelement(0,5);
 m.addelement(1,4);
 m[2]=3;
 m[3]=2;
 int n;

 cout<<"the data you entered in array :"<<endl;
 cout<<m[0]<<"  "<<m[1]<<"  "<<m[2]<<endl;

 cout<<"plz enter an new size :"<<endl;
 cin>>n;



 m.resize(n);

 for(int x=0;x<n;x++)
 {
  cout<<m[x]<<endl;
 }

 m.setarray();

 for(int z=0;z<n;z++)
 {
  cout<<m[z]<<endl;
 }




getch();

}