/*
    1.1 Adaptati codul de mai sus astfel incit sa folositi fisiere header
**/

#include <iostream>
#include "ex1.h"

using namespace std;

//Functions for the classes:

//Student:

Student::Student(int n){
    note = n;
}

int Student::getNote(){
    return note;
}

void Student::setNote(int n){
    note = n;
}
//end Student

//StudentsGroup:

StudentsGroup::StudentsGroup(int n){
    studentsNumber = n;
    studentsList = new Student[studentsNumber];
}

void StudentsGroup::showStudentsInGroup(){
    for(int i=0; i<studentsNumber; i++){
        cout<<i<<" - "<<studentsList[i].getNote()<<endl;
    }
}
//end StudentsGroup

//end functions

int main()
{
    StudentsGroup *group = new StudentsGroup(3);
    group -> showStudentsInGroup();
    return 0;
}
