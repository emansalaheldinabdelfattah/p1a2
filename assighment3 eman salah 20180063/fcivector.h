#ifndef FCIVECTOR_H
#define FCIVECTOR_H



#include <iostream>
using namespace std;
        int numberofelement=0;  //to calculate the size of vector
   int capacity=10;//to calculate the actual size of vector

template <class T>

class fcivector {
private:
    T *elements;//to create dynamic array
public:
    fcivector();//to create dynamic array by default
    ~fcivector();
     void push_back(T val);//to pushes values in vector
    void pop_back(); //to delete the last element
    void insert (int position , T val);//to put variable in certain position
    int size();//the size that the user it
    int capact();//to calculate the actual size of vector
    bool empety();//to sure if the vector is empty or not
    T&operator[] (int index); //to certain position
    T* begin();//to return the address for the first element
    T& front();//to return the first element
    T& back();//to return the last element
    void erase(T * position );//to remove a certain element
    void clear();//to delete all the element
    void print();//to print vector

};



////////////default constructor////////////////////
//////////////////////////////////////////////////
template <class T>
 fcivector<T> ::fcivector()
 {
    T*elements=new T[capacity];

 }


 ///////////////size/////////////////////////
////////////////////////////////////////////
template<class T>
int fcivector<T>::size()
{
return numberofelement;
}


////////////////capacity///////////////////
////////////////////////////////////////////
template<class T>
int fcivector<T>::capact()
{
   return capacity;
}



///////////certain is empty///////////////////
/////////////////////////////////////////////
template<class T>
bool fcivector<T>::empety()
{
    if(size()>0) return false;
    else return true;
}



////////to certain position//////////////////
////////////////////////////////////////////
template<class T>
T& fcivector<T>::operator[](int index)
{

    return elements[index];

}

/////////////&first element////////////////
///////////////////////////////////////////
template <class T>
T* fcivector<T>::begin()
{
return &elements[0];
}


////////////first element//////////////////
//////////////////////////////////////////
template<class T>
T& fcivector<T>::front()
{

return  elements[0];
}

//////////////last element/////////////
//////////////////////////////////////
template<class T>
T&fcivector<T>::back()
{
return elements[size()-1];
}




//////////////push back/////////////////
////////////////////////////////////////
template<class T>
void fcivector<T>::push_back(T val)
{
     numberofelement++;
if(numberofelement>=capacity)
{
    capacity=capacity+capacity*0.5;
    T* temp=new T[capacity];
    for(int i=0 ; i<numberofelement; i++)
    {
        temp[i]=elements[i];
    }
    delete [] elements;
    elements=temp;
    *(elements+numberofelement)=val;

}
else
    {
    elements[numberofelement-1]=val;
}
}



///////////////pop back////////////////////
///////////////////////////////////////////
template<class T>
void fcivector<T>::pop_back()
{
if(numberofelement==0)
{
    cout<<"you can't pop back"<<endl;
}
else if(numberofelement>0)
{
    numberofelement--;
}
}



////////////////erase///////////////////////
////////////////////////////////////////////
template<class T>
void fcivector<T>::erase(T *position)
{
    int temp;
    for(int i=0 ;i<=numberofelement;i++)
    {

        if(begin()+i==((position)-1))
        {
            temp=i;
        numberofelement--;
        for(int j=temp ; j<=numberofelement;j++)
        {
            elements[j]=elements[j+1];
        }
        break;
        }
    }

}



//////////////insert//////////////////////////
//////////////////////////////////////////////
template<class T>
void fcivector<T>::insert(int position, T val)
{
    int temp1;


  for(int i=0 ;i<=numberofelement;i++)
    {

        if(i==(position))
        {
            temp1=i;
   numberofelement++;
T *temv=new T[numberofelement];
       for(int i=0 ; i<=temp1;i++)
        {
         temv[i]=elements[i];
        }
        temv[temp1]=val;
        int x=0;
        for(int i=temp1+1; i<numberofelement;i++)
        {

            temv[i]=elements[x];
            x++;
        }

        for(int i=0 ;i<numberofelement;i++)
        {
            elements[i]=temv[i];
        }

        delete[] temv;
       break;

       }
}
}


/////////////print vector///////////////////
////////////////////////////////////////////
template<class T>
void fcivector<T>::print()
{
cout<<"vector\n";
    for(int i=0 ; i<size() ;i++)
    {
        cout<<elements[i]<<endl;
    }
}



//////delete all elements all vector//////////
//////////////////////////////////////////////
template <class T>
void  fcivector<T>::clear()
{
    numberofelement=0;
    delete[]elements;
}


/////to delete from memory the vector////
////////////////////////////////////////
template<class T>
fcivector<T>::~fcivector()
{
delete elements;
}

#endif // FCIVECTOR_H
