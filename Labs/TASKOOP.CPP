#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

class String
{
 private:
  int size;
  char *str;

 public:
  String();
  String(int siz);
  String(char *s);
  String(String & s);
  ~String();
  void printinfo();
  String& operator=(String &s);
  char charat(int index);
  int indexof(char ch);
  int indexof(int start,char ch);
  String substring(int start);
  String substring(int start,int end);
  String concat(String s);
  String operator+(String s);
  String operator+=(String s);



     static String upercase(String &s)
    {
      String temp(s.size);

      for(int i=0;i<s.size;i++)
      {
	if(int(s.str[i])>90)
	  temp.str[i]=s.str[i]-32;
      }

      return temp;
    }

   static String lowercase(String &s)
   {
     String temp(s.size);

     for(int i=0;i<s.size;i++)
     {
       if(int(s.str[i])<97)
	 temp.str[i]=s.str[i]+32;
     }

    return temp;

   }


};

  String::String()
  {
   size=10;
   str=new char[size];
  // cout<<"string default constructor"<<endl;
  }


  String::String(int siz)
  {
   size=siz;
   str=new char[size];
  // cout<<"string constructor with parameter siz"<<endl;
  }



  String::String(char *s)
  {
    int i=0;
    while (s[i]!='\0')
    {
     i++;
    }

    str=new char[i];
    int j;
    for(j=0;j<i;j++)
    {
     str[j]=s[j];
    }
    size=j;

   // cout<<"string constractor with parameter"<<endl;
  }


  String::String(String &s)
  {
    size=s.size;

    if(size==0)
     str=NULL;

    else
    {
    str=new char[size];
    for(int i=0;i<size;i++)
    {
     str[i]=s.str[i];
    }

    }
   // cout<<"string copy constructor"<<endl;
  }


  String::~String()
  {

   if(size>0)
    delete [] str;
  // cout<<"string destructor"<<endl;
  }

  void String::printinfo()
  {
    cout<<"the string: ";
    for(int i=0;i<size;i++)
      cout<<str[i];
    cout<<"\n";
    cout<<"the size: ";
    cout<<size<<endl;
  }


  String& String::operator=(String &s)
  {

   if(str!=0)
     delete [] str;

   this->size=s.size;
   str=new char[size];

   for(int i=0;i<size;i++)
   {
    str[i]=s.str[i];
   }

   return *this;
  }


  char String::charat(int index)
  {
   return str[index];
  }


  int String::indexof(char ch)
  {
    for(int i=0;i<size;i++)
    {
     if(ch==str[i])
      return i;
    }
    return -1;
  }


  int String::indexof(int start,char ch)
  {
    for(int i=start;i<size;i++)
    {
     if(ch==str[i])
      return i;
    }

    return -1;
  }


  String String::substring(int start)
  {
    String s;
    int siz=size-start;
    s.size=siz;
    for(int i=start;i<size;i++)
    {
       s.str[i-start]=str[i];
    }


    return s;
  }


  String String::substring(int start,int end)
  {
    int len=end-start+1;
    String ns(len);
    for(int i=start;i<end+1;i++)
    {
     ns.str[i-start]=str[i];

    }

    return ns;

  }


  String String::concat(String s)
  {
    int len=size+s.size;
    String ns(len);
    for(int i=0;i<size;i++)
    {
     ns.str[i]=str[i];
    }

    for(int j=size;j<len;j++)
    {
     ns.str[j]=s.str[j-size];
    }

    return ns;
  }


  String String::operator+(String s)
  {
    int len=size+s.size;
    String ns(len);
    for(int i=0;i<size;i++)
    {
     ns.str[i]=str[i];
    }

    for(int j=size;j<len;j++)
    {
     ns.str[j]=s.str[j-size];
    }

    return ns;

  }


  String String::operator+=(String s)
  {
    int ts=size;
    String temp(size);
    for(int i=0;i<size;i++)
       temp.str[i]=str[i];

    delete [] str;
    int len=size+s.size;

    str= new char[len];
    size=len;

    for(i=0;i<ts;i++)
    {
     str[i]=temp.str[i];
    }

    for(int j=ts;j<len;j++)
    {
     str[j]=s.str[j-ts];
    }


    return *this;


  }







void main(void)
{
clrscr();
String s1("marina");
s1.printinfo();
char ch=s1.charat(2);
cout<<"the char at index 2 : "<<ch<<endl;
int ind=s1.indexof('a');
cout<<"the index of 'a' : "<<ind<<endl;
ind=s1.indexof(3,'a');
cout<<"the index of 'a' form index 3 : "<<ind<<endl;

String s2;
s2=s1.substring(4);
s2.printinfo();

String s3("marcelle");
String s4;
s4=s1.concat(s3);
s4.printinfo();

String s5;
s5=s1+s3;
s5.printinfo();

s1+=s3;
s1.printinfo();

s5=String::upercase(s3);
s5.printinfo();

String s6("MERNA");
s5=String::lowercase(s6);
s5.printinfo();


/*char c;
cout<<"plz enter a character :";
cin>>c;
cout<<"\n the value ascii of "<<c<<" is "<<int(c)<<endl;*/






getch();

}