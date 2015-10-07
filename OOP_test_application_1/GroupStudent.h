#ifndef GROUPSTUDENT_H
#define GROUPSTUDENT_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Group;
class Student
{
private:
    static int count;
    string name;
    string surname;
    int grade;
    int id;
    list <Group *> GrpSt;

    bool valid_string(const string str) const;
    bool valid_grade() const;
    bool add_group(Group *);
public:
    Student (string name, string surname, int grade);
    ~Student();
    Student(const Student &other);

    bool valid_student() const;

    string GetName() const;
    string GetSurname() const;
    int GetGrade() const;
    int GetId() const;
    list <Group* > GetGrp() const; 

    void SetId();
    bool SetName(const string name);
    bool SetSurname(const string surname);
    bool SetGrade(const int pnt);

    bool Student::DelGrp(const Group* grp);
    bool AddGrade(int pnt);
    string Print_info() const;
    friend Group;
};
class Group
{
    static int count;
    list<Student *> GroupStudent;
    int id;

    list<Student *>::iterator FindStudById(int id);
    list<Student *>::iterator FindStudByRef(Student *stud);
    list<Student *>::iterator FindStudByName( string name, string sname);
    bool RmStud(list<Student *>::iterator it);
public:
    Group();
    ~Group();
    Group(const Group &other);

    bool Add_student(Student *stud);
    bool Rem_student (int id);
    bool Rem_student (Student *stud);
    bool Rem_student (string name, string sname);

    Student* FindStudent(string name, string sname);
    Student* FindStudent(int id);

    list<Student *> ListStd() const;
    bool ValidGroup() const;
    int GetId() const;
    float AvrGrade() const;

    void SortByGrade();
    void SortBySurname();
    void SortByName();
};

#endif