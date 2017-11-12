/*
    1.3 Adaugati o variabila membru name, in clasa Student si modificati aplicatia astfel incit name sa fie initializat cu „Joe Doe”
**/

#include <iostream>
#include <string>
#include "ex3.h"

using namespace std;

//Functions for the classes:

//Student:

Student::Student(int n, string nam){
    this -> note = n;
    this -> name = nam;
}

int Student::getNote(){
    return note;
}

void Student::setNote(int n){
    note = n;
}

void Student::setName(string nam){
    this->name = nam;
}

string Student::getName(){
    return this -> name;
}
//end Student

//StudentsGroup:

StudentsGroup::StudentsGroup(int n){
    this -> studentsNumber = n;
    studentsList = new Student[studentsNumber];
}

void StudentsGroup::showStudentsInGroup(){
    for(int i=0; i<studentsNumber; i++){
        cout<<i<<" - "<<studentsList[i].getName()<<", "<<studentsList[i].getNote()<<endl;
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
