#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

using namespace std;

class Student {

    private:
        int note;
        string name;

    public:
        Student(int n = 0);
        void setNote(int n);
        int getNote();

};

class StudentsGroup {

    private:
        int studentsNumber;
        Student *studentsList;

    public:
        StudentsGroup(int n);
        void showStudentsInGroup();

};

#endif // EX1_H_INCLUDED
