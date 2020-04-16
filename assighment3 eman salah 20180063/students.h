#ifndef STUDENTS_H
#define STUDENTS_H



#include"fcivector.h"
#include"courses.h"
#include<cstring>
#include<string>

using namespace std;
class students {
private:

  char sname[100];
    int sid;
   char sdepartment[100];
public:

  fcivector<courses>fc;

    students();


    void printinfo();
    friend istream &operator>>(istream &input,students &s );
    friend ostream &operator<<(ostream &output,students&s);

};
students::students(){}
//////////////////////////////////////////
void students::printinfo(){}
////////////////////////////////////////
////////////////////////////////////////


////////////cin in the main////////////////////
//////////////////////////////////////////////
  int ncourses;
istream &operator >>(istream &input ,students &s)
{
    cout<<"enter your name"<<endl;
    input>>s.sname;
    cout<<"enter your id"<<endl;
    input>>s.sid;
    cout<<"enter your department"<<endl;
    input>>s.sdepartment;
    cout<<"enter the number of courses"<<endl;
    input>>ncourses;
   for(int i=0 ;i<ncourses;i++)
    {
        courses obj;
     input>>obj;

       s.fc.push_back(obj);

    }
    return input;
}


////////////cout in the main//////////////////////
/////////////////////////////////////////////////
ostream &operator<<(ostream &output , students &s)
{
   output<<s.sname<<"\n"<<s.sid<<"\n"<<s.sdepartment<<"\n";
    for(int i=0 ;i<s.fc.size() ; i++)
    {
       output<<s.fc[i];
    }
    return output;
}

#endif // STUDENTS_H
