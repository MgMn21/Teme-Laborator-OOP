/*
    1 - Declarati un constructor private, care seteaza nota unui element de tip
        class Student la 8. Folositi-l pt a initializa grade in constructorul
        initial
    2 - Folositi un membru variabila declarat static cu care sa numarati citi
        studenti sunt creati in acest moment. Adresati membrul static in
        constructor si destructor pentru a incrementa, decrementa numarul de
        studenti.
    3 - Creati o lista simplu inlantuita de studenti ( class Student). Afisati
        lista. Proiectati structura astfel incit sa pot afisa lista plecind de la
        oricare element al ei. Gasiti un mod simplu de a numara cati studenti s-au
        creat.
    4 - Creati o clasa de tip masina cu 3 constructori, 2 publici si unul
        privat, unul din constructori fara parametriii. Folositi this in
        respectivii contructori
**/

#include <iostream>
#include <list>
#include <string.h>


using namespace std;

class Student {

    int grade;
    string name;

    Student(int grade = 8, string name = " ") { // 1
        this->grade = grade;
        this->name = name;
    }

    public:

        static Student *constructor(int grade, string name){
            return new Student(grade, name);   // 1
        }

        int get_grade() {
            return this->grade;
        }

        string get_name() {
            return this->name;
        }
};


class StudentGroup {

    int number;
    list<Student> lst;  // 3

    public:

        StudentGroup(int number) {
            this -> number = number;
            list<Student> lst;
        }

        void read_student() {

            int grade;
            string name;

            for(int i = 0; i < this -> number; i++) {
                cout << "Student " << i << " name: ";
                cin >> name;
                cout << "Student " << i << " grade: ";
                cin >> grade;
                cout << '\n';

                Student *new_student;
                new_student = Student::constructor(grade, name);
                lst.push_back(*new_student);
            }
        }

        void print_students() {
            for (list<Student>::iterator it = lst.begin(); it != lst.end(); it++) {

                cout << it -> get_name() << " -> " << it -> get_grade() << '\n';
            }
        }

        int get_number_of_students() {
            return this -> number;
        }
};

class Masina {

    double price;
    string name;

    Masina(double price, string name = " ") {
        this -> price = price;
        this -> name = name;
    }

    public:

        static Masina* constructorPrice(double price) {
            return new Masina(price);
        }

        static Masina* constructorPriceAndName(double price, string name) {
            return new Masina(price, name);
        }

        double get_price() {
            return this -> price;
        }
        string get_name() {
            return this -> name;
        }
};

int main()
{
    StudentGroup *new_group = new StudentGroup(5);
    new_group -> read_student();
    new_group -> print_students();
    int student_number = new_group -> get_number_of_students();
    cout << "We have " << student_number << " students\n\n\n";

    Masina* car;
    car = Masina::constructorPriceAndName(10500, "Volkswagen Jetta");

    double pret = car -> get_price();
    string nume = car -> get_name();

    cout << "Nume: " << nume << endl;
    cout << "Pret: $" << pret << endl;

}
