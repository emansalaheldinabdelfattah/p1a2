#include <iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include"fcivector.h"
#include"students.h"
#include"courses.h"
using namespace std;
///////////////////
template<class T>

void functionlist(T ele)
    {
        try{
         char c;
        do{
        int choice2,choose;
fcivector<T>v;//create of vector
        cout<<" What kind of operation would you like to perform?"<<endl<<
            "1. Add element."<<endl<<
            "2. Remove last element."<<endl<<
            "3. Insert element at certain position."<<endl<<
            "4. Erase element from a certain position."<<endl<<
            "5. Clear."<<endl<<
            "6. Display first element."<<endl<<
            "7. Display last element."<<endl<<
            "8. Display element at certain position."<<endl<<
            "9. Display vector size."<<endl<<
            "10. Display vector capacity."<<endl<<
            "11. Is empty? "<<endl;
        cin>>choice2;//to choose the choice
        switch(choice2)
        {
            case 1://push_back
            {

              cout<<"How many elements you would like to add?"<<endl;
                cin>>choose;
                for(int i=0 ; i<choose ;i++)
                {
                    T val;
                    cout<<"enter the element"<<endl;  //throw 10;
                    cin>>val;
                    v.push_back(val);
                }




                break;
            }

            case 2://pop _back
            {
                v.pop_back();
                break;
            }

            case 3://insert
            {
                cout<<"enter the position :"<<endl;
                int postion;
                T val;
                cin>>postion;
                cout<<"enter the value :"<<endl;
                cin>>val;
              //  v.insert(postion, val);
                v.print();
                break;
            }

            case 4://erase
            {
                 if(v.size()==0)
                  {
                    cout<<"you can't erase "<<endl;
                     break;
                   }
                cout<<"enter the position\n";
                int position;
                cin>>position;
              //  v.erase(v.begin()+position);
                v.print();
                break;
            }

            case 5://clear
            {
                 v.clear();
                break;
            }

            case 6://first element
            {
                cout<<v.front();
                break;
            }

            case 7://last element
            {
                cout<<v.back();
                break;
            }

            case 8://operator[]
            {
                int index;
                cout<<"enter the position"<<endl;
                cin>>index;
                cout<<v.operator[](index);
                break;
            }

            case 9://number of elements
            {
                cout<<v.size();
                break;
            }

            case 10://actual size of vector
            {
                cout<<v.capact();
                break;
            }

            case 11://if is vector empty or not
            {
                if(v.empety()==1)cout<<"true"<<endl;
                else cout<<"false"<<endl;
                break;
            }
            default:
                throw 404;

        }
      cout<<endl;
      cout<<"if you enter again enter Y else enter N"<<endl;
      cin>>c;
    }
    while(c=='y'||c=='Y');
        }
        catch(int p)
        {
            cout<<p;
        }
    }





int main() {

try{
    int choice1;
       cout<<"Insert type of vector you would like to create:"<<endl<<
        "1. list of integer"<<endl<<
        "2. list of character"<<endl<<
        "3. list of string"<<endl<<
        "4. list of float"<<endl<<
        "5. list of students"<<endl<<
        "6. Exit"<<endl;
       cin>>choice1;
       switch(choice1)
       {
           case 1:
           {
               int ele=0;
               cout<<"A vector of integers was created successfully."<<endl;
               functionlist(ele);
               break;
           }
           case 2:
           {
               char ele='a';
               cout<<"A vector of character was created successfully."<<endl;
               functionlist(ele);
               break;
           }
           case 3:
           {
               char ele[100]="user";
               cout<<"A vector of string was created successfully."<<endl;
               functionlist(ele);
               break;
           }
           case 4:
           {
               float ele=0.0;
               cout<<"A vector of float was created successfully."<<endl;
               functionlist(ele);
               break;
           }
           case 5:
           {
          students ele;
               cout<<"A vector of students was created successfully."<<endl;
               functionlist(ele);
               break;
           }
           case 6:
           {
               exit(0);
           }
           default:
            throw 404;
       }
}
catch(int s)
{
cout<<s;
}

    return 0;
}

