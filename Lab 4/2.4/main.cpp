/*
        2.4 Scrieti o metoda care sorteaza tabloul / lista de Student, studentsList, dupa name/note
**/

#include <iostream>
#include <string>
#include <list>
# include <algorithm>

using namespace std;

//The classes:

class Student {

    private:
        int note;
        string name;

    public:
        Student(int n = 0, string nam = "Kendrick Lamar");
        int getNote();
        void setNote(int n);
        void setName(string nam);
        string getName();

};

class StudentsGroup {

    private:
        int studentsNumber;
        list<Student> studentsList;

    public:
        StudentsGroup(int n);
        void showStudentsInGroup();
        void readStudents();
        void sortByName();
        void sortByGrade();
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
    list<Student> studentsList;
}

void StudentsGroup::showStudentsInGroup(){

    int i = 0;
    for (list<Student>::iterator it=studentsList.begin(); it!=studentsList.end(); it++) {
        i++;
        cout<<"#"<<i<<": "<<it->getName()<<", graded "<<it->getNote()<<endl;
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

        Student tempStudent (note, studentName);
        studentsList.push_back(tempStudent);
    }
}

void StudentsGroup::sortByGrade(){

    studentsList.sort([](Student &s1, Student &s2){ return s1.getNote() > s2.getNote(); });

}

void StudentsGroup::sortByName(){

        studentsList.sort([](Student &s1, Student &s2){ return s1.getName().compare(s2.getName()) < 0;});

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
    group -> sortByName();
    cout<<endl<<"Ordered by name:"<<endl;
    group -> showStudentsInGroup();
    group -> sortByGrade();
    cout<<endl<<"Ordered by grade:"<<endl;
    group -> showStudentsInGroup();

    return 0;
}
