#ifndef EX4_H_INCLUDED
#define EX4_H_INCLUDED

using namespace std;

class Student {

    private:
        int note;
        string name;

    public:
        Student(int n = 0, string nam = "Joe Doe");
        void setNote(int n);
        int getNote();
        string getName();
        void setName(string nam);
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

#endif // EX4_H_INCLUDED
