#include <iostream>
#include <list>
using namespace std;

/*
    T.8.2. Scrieți o clasa care creaza un array/lista de elemente de tip Persoana, Angajat sau Parinte.
    Alegerea tipului se face la creare, pe baza unui meniu simplu. Afisati componentele array-ului/listei.
*/

template<class T>
class lister{
    public:
        list<T> newList;
};

class Person{
    string name;
    int age;
    public:
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void printPerson(){
            cout<<"\nName: "<<this->name<<"\nAge: "<<this->age<<endl;
        }
};

class Employee{
    string name;
    int age;
    string Job;
    public:
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setJob(string job){
            this->Job = job;
        }
        void printEmployee(){
            cout<<"\nName: "<<this->name<<"\nAge: "<<this->age<<"\nJob: "<<this->Job<<endl;
        }
};

class Parent{
    string name;
    int age;
    int nrOfkids;
    public:
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setnrOfkids(int nr){
            this->nrOfkids = nr;
        }
        void printParent(){
            cout<<"\nName: "<<this->name<<"\nAge: "<<this->age<<"\n# of kids: "<<this->nrOfkids<<endl;
        }
};

int main()
{
    lister<Parent> par;
    lister<Employee> emp;
    lister<Person> person;
    int option = 0;
    char check = 'y';

    cout<<"What type of list do you want to create?\n\n1.Person\n2.Employee\n3.Parent\n\n>>>";
    cin>>option;
    switch(option){
    case 1:
        while(check != 'n' && check != 'N'){
            Person temp;
            string name;
            int age;
            cout<<"\n\nName: ";
            cin>>name;
            temp.setName(name);
            cout<<"\nAge: ";
            cin>>age;
            temp.setAge(age);
            person.newList.push_back(temp);
            cout<<"\nAdd another person?(y/n)\n>>>";
            cin>>check;
        }
        cout<<"Person list:";
        for(auto it = person.newList.begin(); it != person.newList.end(); it++){
            it->printPerson();
        }
        break;

    case 2:
        while(check != 'n' && check != 'N'){
            Employee temp;
            string name;
            int age;
            string job;
            cout<<"\n\nName: ";
            cin>>name;
            temp.setName(name);
            cout<<"\nAge: ";
            cin>>age;
            temp.setAge(age);
            cout<<"\nJob: ";
            cin>>job;
            temp.setJob(job);
            emp.newList.push_back(temp);
            cout<<"\nAdd another person?(y/n)\n>>>";
            cin>>check;
        }
        cout<<"Employee list:";
        for(auto it = emp.newList.begin(); it != emp.newList.end(); it++){
            it->printEmployee();
        }
        break;
    case 3:
        while(check != 'n' && check != 'N'){
            Parent temp;
            string name;
            int age;
            int nr;
            cout<<"\n\nName: ";
            cin>>name;
            temp.setName(name);
            cout<<"\nAge: ";
            cin>>age;
            temp.setAge(age);
            cout<<"\n# of children: ";
            cin>>nr;
            temp.setnrOfkids(nr);
            par.newList.push_back(temp);
            cout<<"\nAdd another person?(y/n)\n>>>";
            cin>>check;
        }
        cout<<"Parent list:";
        for(auto it = par.newList.begin(); it != par.newList.end(); it++){
            it->printParent();
        }
        break;
    }

    return 0;
}
