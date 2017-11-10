/*
        2.1 Optimizati codul de mai sus astfel incit in loc de studentsList[i].setNote(note)
        si studentsList[i].setName(studentName); sa folosim studentsList[i] = Student(note, studentName);
**/

#include <iostream>
#include <string>

using namespace std;

//The classes:

class Student {

    private:
        int note;
        string name;

    public:
        Student(int n = 0, string nam = "John Doe");
        int getNote();
        void setNote(int n);
        void setName(string nam);
        string getName();

};

class StudentsGroup {

    private:
        int studentsNumber;
        Student *studentsList;

    public:
        StudentsGroup(int n);
        void showStudentsInGroup();
        void readStudents();
};
//end class declarations

//Functions for the classes:

//Student:

Student::Student(int n, string nam){
    this->note = n;
    this->name = nam;
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
    return this->name;
}
//end Students

//StudentsGroup:

StudentsGroup::StudentsGroup(int n){
    this->studentsNumber = n;
    studentsList = new Student[n];
}

void StudentsGroup::showStudentsInGroup(){
    for(int i=0; i<studentsNumber; i++){
        cout<< "#" << i << " -> " << studentsList[i].getName( )<< ", graded: " << studentsList[i].getNote() << endl;
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

//end class functions

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
