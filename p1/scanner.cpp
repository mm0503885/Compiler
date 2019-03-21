#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream in;
    in.open("input.xml",ios::in); //ÅªÀÉ

    fstream out;
    out.open("output.txt",ios::out); //¼gÀÉ
    char a;


    while(in.get(a))
    {


      if(isdigit(a) || isalpha(a)) {out<<a; if(!isdigit(in.peek()) && !isalpha(in.peek()) && in.peek()!='.' && in.peek()!='-' && in.peek()!=' ') out<<endl;}
      //

      else if(a=='.' || a=='-') out<<a;

      else if(a==' ') out<<endl;

      else if(a=='<') out<<a<<endl;

      else if(a=='>') {out<<a; if(in>>a) {out<<endl; in.putback(a);}}

       else if(a=='?') out<<a<<endl;

       else if(a=='=') out<<a<<endl;

       else if(a=='"')
        {
            out<<a<<endl;
            while(in.peek()!='"') {in.get(a); out<<a;}
            out<<endl;
            in.get(a) ;
            out<<a;
            if (in.peek()!=' ') out<<endl;
        }

        else if(a==':') out<<a<<endl;

         else if(a=='/') out<<a<<endl;


    }






}
