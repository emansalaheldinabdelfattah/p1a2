#ifndef COURSES_H
#define COURSES_H
#include<string>
#include <cstring>
#include<iostream>


using namespace std;
class courses
        {
private:
 char courseName[100];
    char courseCode[100];
    char courseGrade;
    float  coursePoint;
    int courseYear;
    int  courseSemester;
public:


    courses();
    void printcourseinfo();
    friend std::istream &operator>>(std::istream &input,courses &s );
    friend std::ostream &operator<<(std::ostream &output,courses&s);

};
courses::courses(){}
/////////////////////////////////////////
void courses::printcourseinfo(){}


/////////cin in course/////////////////////////////////
////////////////////////////////////////////////////////
istream & operator>>(istream &input ,courses &s)
{

    cout<<"enter the course name"<<endl;
    input>>s.courseName;

     cout<<"enter the code of course"<<endl;
    input>>s.courseCode;

     cout<<"enter the course point"<<endl;
    input>>s.coursePoint;

    cout<<"enter the course grade"<<endl;
    input>>s.courseGrade;

   cout<<"enter the course smester"<<endl;
    input>>s.courseSemester;

      cout<<"enter the course year"<<endl;
    input>>s.courseYear;

    cout<<endl;

    return input;



}

/////////////////////cout in course/////////////////////////
////////////////////////////////////////////////////////////

ostream & operator<<(ostream & output ,courses &s)
{
    output<<s.courseName<<" \n"<<s.courseCode<<"\n"<<s.courseGrade<<"\n"<<s.coursePoint<<"\n"<<s.courseSemester<<"\n"<<s.courseYear;
    output<<endl;
    return output;

}




#endif // COURSES_H
