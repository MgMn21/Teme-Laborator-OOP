/*
    1.4 Implementati o metoda readStudents in clasa StudentsGroup pentru citirea studentilor
**/

#include <iostream>
#include <string>
#include "ex4.h"

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

void StudentsGroup::readStudents(){

    int note;
    string studentName;

    for(int i=0; i < this->studentsNumber; i++){

        cout<<"Student #"<<i<<endl<<"Name: ";
        cin>>studentName;
        cout<<endl<<"Grade: ";
        cin>>note;
        cout<<endl;

        studentsList[i] = Student(note, studentName);  //Modificarea ceruta
    }
}

//end StudentsGroup

//end functions

int main()
{
    int nrOfstudents;

    cout<<"Please input the number of students in the group:"<<endl<<">> ";
    cin>>nrOfstudents;

    StudentsGroup *group = new StudentsGroup(nrOfstudents);
    group -> readStudents();
    group -> showStudentsInGroup();
    return 0;
}
