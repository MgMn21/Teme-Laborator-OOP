/*
    1.2 Modificati codul astfel incit in constructorii Student si StudentsGroup sa folositi cuvintul cheie this.
**/

#include <iostream>
#include "ex2.h"

using namespace std;

//Functions for the classes:

//Student:

Student::Student(int n){
    this -> note = n;
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
    this -> studentsNumber = n;
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
