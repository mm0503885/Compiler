#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream in,in2;
    in.open("XSL-1.txt",ios::in); //讀檔
    in2.open("XSL-2.txt",ios::in);

    fstream out;
    out.open("Result-1.txt",ios::out); //寫檔

     fstream out2;
    out2.open("Result-2.txt",ios::out);
    char a;
    string tag1,tag2,tag3,parameter;


    while(in.get(a))
    {
       if(a!='x') continue;
       else
       {
         in.get(a);
         if(a!='s') continue;
         else
         {
             in.get(a);
             if(a!='l') continue;
             else
                {
                  in.get(a);
                  if(a!=':') continue;
                  else          //到此為此確定為xsl:
                  {
                      in.get(a);
                      if(a=='t')  //template
                      {
                          in.get(a);
                          in.get(a);
                          if(a=='x') continue;  //代表為xsl:text 忽略此標籤
                          else
                          {
                              for(int i=0;i<6;i++) in.get(a);
                              if(a!=' ') continue;    //代表為</xsl:template>
                              else
                              {
                                  tag1="";
                                  for(int i=0;i<8;i++) in.get(a);
                                  while(a!='"')
                                  {
                                    tag1+=a;
                                    in.get(a);
                                  }
                                  out<<"tags:xsl:template"<<endl;
                                  out<<"select:"<<tag1<<endl;
                                  out<<"parameters:null"<<endl;
                              }
                          }
                      }
                      else if(a=='f') //即為for-each
                      {
                         for(int i=0;i<8;i++) in.get(a);
                              if(a!=' ') continue;    //代表為</xsl:for-each>
                              else
                              {
                                  tag2="";
                                  for(int i=0;i<9;i++) in.get(a);
                                  while(a!='"')
                                  {
                                    tag2+=a;
                                    in.get(a);
                                  }
                                  out<<"----------"<<endl;
                                  out<<"tags:xsl:for-each"<<endl;
                                  out<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out<<"parameters:null"<<endl;
                              }
                      }
                      else if(a=='s') //sort
                      {
                          in.get(a);
                          if(a=='t') continue;  //代表為xsl:stylesheet 忽略此標籤
                          else
                          {
                              for(int i=0;i<3;i++) in.get(a);
                              if(a!=' ') continue;
                              else
                              {
                                  parameter="";
                                  for(int i=0;i<9;i++) in.get(a);
                                  while(a!='"')
                                  {
                                    parameter+=a;
                                    in.get(a);
                                  }
                                  out<<"----------"<<endl;
                                  out<<"tags:xsl:sort"<<endl;
                                  out<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out<<"parameters:"<<parameter<<endl;
                              }
                          }
                      }
                      else if(a=='i') //即為if
                      {
                         for(int i=0;i<2;i++) in.get(a);
                              if(a!=' ') continue;    //代表為</xsl:if>
                              else
                              {
                                  parameter="";
                                  for(int i=0;i<7;i++) in.get(a);
                                  while(a!='"')
                                  {
                                    parameter+=a;
                                    in.get(a);
                                  }
                                  out<<"----------"<<endl;
                                  out<<"tags:xsl:if"<<endl;
                                  out<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out<<"parameters:"<<parameter<<endl;
                              }
                      }
                      else if(a=='v') //即為value-of
                      {
                         for(int i=0;i<8;i++) in.get(a);
                              if(a!=' ') continue;
                              else
                              {
                                  tag3="";
                                  for(int i=0;i<9;i++) in.get(a);
                                  while(a!='"')
                                  {
                                    tag3+=a;
                                    in.get(a);
                                  }
                                  out<<"----------"<<endl;
                                  out<<"tags:xsl:value-of"<<endl;
                                  out<<"select:"<<tag1<<"/"<<tag2<<"/"<<tag3<<endl;
                                  out<<"parameters:null"<<endl;
                              }
                      }


                  }


                }
         }


        }









    }

    while(in2.get(a))
    {
       if(a!='x') continue;
       else
       {
         in2.get(a);
         if(a!='s') continue;
         else
         {
             in2.get(a);
             if(a!='l') continue;
             else
                {
                  in2.get(a);
                  if(a!=':') continue;
                  else          //到此為此確定為xsl:
                  {
                      in2.get(a);
                      if(a=='t')  //template
                      {
                          in2.get(a);
                          in2.get(a);
                          if(a=='x') continue;  //代表為xsl:text 忽略此標籤
                          else
                          {
                              for(int i=0;i<6;i++) in2.get(a);
                              if(a!=' ') continue;    //代表為</xsl:template>
                              else
                              {
                                  tag1="";
                                  for(int i=0;i<8;i++) in2.get(a);
                                  while(a!='"')
                                  {
                                    tag1+=a;
                                    in2.get(a);
                                  }
                                  out2<<"tags:xsl:template"<<endl;
                                  out2<<"select:"<<tag1<<endl;
                                  out2<<"parameters:null"<<endl;
                              }
                          }
                      }
                      else if(a=='f') //即為for-each
                      {
                         for(int i=0;i<8;i++) in2.get(a);
                              if(a!=' ') continue;    //代表為</xsl:for-each>
                              else
                              {
                                  tag2="";
                                  for(int i=0;i<9;i++) in2.get(a);
                                  while(a!='[' && a!= '"')
                                  {
                                    tag2+=a;
                                    in2.get(a);
                                  }
                                  if(a=='[')
                                  {
                                      parameter="";
                                      in2.get(a);
                                      while(a!=']' )
                                      {
                                        parameter+=a;
                                        in2.get(a);
                                      }
                                    out2<<"----------"<<endl;
                                    out2<<"tags:xsl:for-each"<<endl;
                                    out2<<"select:"<<tag1<<"/"<<tag2<<endl;
                                    out2<<"parameters:"<<parameter<<endl;
                                  }
                                  else
                                  {
                                  out2<<"----------"<<endl;
                                  out2<<"tags:xsl:for-each"<<endl;
                                  out2<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out2<<"parameters:null"<<endl;
                                  }
                              }
                      }
                      else if(a=='s') //sort
                      {
                          in2.get(a);
                          if(a=='t') continue;  //代表為xsl:stylesheet 忽略此標籤
                          else
                          {
                              for(int i=0;i<3;i++) in2.get(a);
                              if(a!=' ') continue;
                              else
                              {
                                  parameter="";
                                  for(int i=0;i<9;i++) in2.get(a);
                                  while(a!='"')
                                  {
                                    parameter+=a;
                                    in2.get(a);
                                  }
                                  out2<<"----------"<<endl;
                                  out2<<"tags:xsl:sort"<<endl;
                                  out2<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out2<<"parameters:"<<parameter<<endl;
                              }
                          }
                      }
                      else if(a=='i') //即為if
                      {
                         for(int i=0;i<2;i++) in2.get(a);
                              if(a!=' ') continue;    //代表為</xsl:if>
                              else
                              {
                                  parameter="";
                                  for(int i=0;i<7;i++) in2.get(a);
                                  while(a!='"')
                                  {
                                    parameter+=a;
                                    in2.get(a);
                                  }
                                  out2<<"----------"<<endl;
                                  out2<<"tags:xsl:if"<<endl;
                                  out2<<"select:"<<tag1<<"/"<<tag2<<endl;
                                  out2<<"parameters:"<<parameter<<endl;
                              }
                      }
                      else if(a=='v') //即為value-of
                      {
                         for(int i=0;i<8;i++) in2.get(a);
                              if(a!=' ') continue;
                              else
                              {
                                  tag3="";
                                  for(int i=0;i<9;i++) in2.get(a);
                                  while(a!='"')
                                  {
                                    tag3+=a;
                                    in2.get(a);
                                  }
                                  out2<<"----------"<<endl;
                                  out2<<"tags:xsl:value-of"<<endl;
                                  out2<<"select:"<<tag1<<"/"<<tag2<<"/"<<tag3<<endl;
                                  out2<<"parameters:null"<<endl;
                              }
                      }


                  }


                }
         }


        }









    }





}
