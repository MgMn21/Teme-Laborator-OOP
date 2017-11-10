/*
        2.2 Studiati daca este posibila extinderea tabelului de elemente Student cu
        cate un element cand se doreste introducerea unui nou student.

        R: Da, daca implementam tabelul de studenti folosind liste
**/

#include <iostream>
#include <string>
#include <list>

using namespace std;

//The classes:

class Student {

    private:
        int note;
        string name;

    public:
        Student(int n = 0, string nam = "Post Malone");
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
        void addNewStudent();
};
//end class declarations

//Functions for the classes:

//Student:

Student::Student(int n, string nam){
    this->note = n;
    this->name = nam;
}//end constructor

int Student::getNote(){
    return note;
}//end getNote

void Student::setNote(int n){
    note = n;
}//end setName

void Student::setName(string nam){
    this->name = nam;
}//end setName-

string Student::getName(){
    return this->name;
}//end getName
//end Students

//StudentsGroup:

StudentsGroup::StudentsGroup(int n){
    this->studentsNumber = n;
    list<Student> studentsList;
}//end constructor

void StudentsGroup::showStudentsInGroup(){

    int i = 0;
    for (list<Student>::iterator it=studentsList.begin(); it!=studentsList.end(); it++) {
        i++;
        cout<<"#"<<i<<": "<<it->getName()<<", graded "<<it->getNote()<<endl;
    }
}//end showStudentsInGroup

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
}//end readStudents

void StudentsGroup::addNewStudent(){

    int note;
    string studentName;

    this->studentsNumber++;
    cout<<"Student #"<<this->studentsNumber<<endl<<"Name: ";
    cin>>studentName;
    cout<<endl<<"Grade: ";
    cin>>note;
    cout<<endl;

    Student tempStudent (note, studentName);
    studentsList.push_back(tempStudent);
}
//end StudentsGroup

//end class functions

int main()
{
    char choice;
    int nrOfstudents;

    cout<<"Please input the number of students in the group:"<<endl<<">> ";
    cin>>nrOfstudents;

    StudentsGroup *group = new StudentsGroup(nrOfstudents);
    group -> readStudents();
    group -> showStudentsInGroup();

    while(1){

        cout<<endl<<"Do you want to add another student?(y/n);"<<endl<<">> "<<endl;
        cin>>choice;
        cout<<endl;
        if(choice == 'y'){
            group -> addNewStudent();
        }else{
            group -> showStudentsInGroup();
            return 0;
        }

    }

    return 0;
}
