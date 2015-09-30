#ifndef GROUPSTUDENT_H
#define GROUPSTUDENT_H
#include "Student.h"
#include <list>
#include <algorithm>

using namespace std;

class Group
{
    static int count;
    list<Student *> GroupStudent;
    int id;
    list<Student *>::iterator FindStudById(int id);
    list<Student *>::iterator FindStudByRef(Student *stud);
    list<Student *>::iterator FindStudByName(string name, string sname);
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
    list<Student *> ListStd();
    bool ValidGroup();
    list<string> InfoGroup();
    float AvrGrade();
    void SortByGrade();
    void SortBySurname();
    void SortByName();
    bool RmStGr(int id);
};

int Group::count = 0;

Group::Group() {
    if (count >= 0) {
        this->id = count;
        this->count++;
    }
}
Group::~Group() {
    cout << "des group" << endl;
    for (auto &i: GroupStudent) {
        i->DelGrp(this);
    }
    this->GroupStudent.clear();
}
Group::Group(const Group &other) {
    *this = other;
}

bool Group::Add_student(Student *stud) {
    Group buff = *this;
    GroupStudent.push_front(stud);
    if (!ValidGroup() || FindStudById(stud->GetId()) == GroupStudent.end() || 
        !stud->add_group(this)) {
        *this = buff;
        return 0;
    } else {
        return 1;
    }
}

list<Student *>::iterator Group::FindStudById(int id) {
        return std::search_n(GroupStudent.begin(), GroupStudent.end(), 1, id, 
                         [](Student * i, int j) -> bool { 
                             return (i->GetId() == j); 
                         });
}
list<Student *>::iterator Group::FindStudByRef(Student *stud) {
    return search_n(GroupStudent.begin(), GroupStudent.end(), 1, stud);
}
list<Student *>::iterator Group::FindStudByName(string name, string sname) {
    string str[2] = {name, sname}; 
    return std::search_n(GroupStudent.begin(), GroupStudent.end(), 1, str, 
                         [](const Student * i, const string str[]) -> bool {
                             return (i->GetName() == str[0] && i->GetSurname() == str[1]);
                         });
}

bool Group::RmStud(list<Student *>::iterator it) {
    if (it != GroupStudent.end()) {
        (*it)->DelGrp(this);
        GroupStudent.erase(it);
        return 1;
    } else {
        return 0;
    }
}

bool Group::RmStGr(int id) {
    list<Student *>::iterator it = FindStudById(id);
    if (it != GroupStudent.end()) {
        GroupStudent.erase(it);
        return 1;
    } else {
        return 0;
    }
}

bool Group::Rem_student(int id) {
    return RmStud(FindStudById(id));
}
bool Group::Rem_student(Student *stud) {
    return RmStud(FindStudByRef(stud));
}
bool Group::Rem_student(string name, string sname) {
    return RmStud(FindStudByName(name, sname));
}

Student* Group::FindStudent(string name, string sname) {
    list<Student *>::iterator it = FindStudByName(name, sname);
    if (it == GroupStudent.end()) {
        return NULL;
    } else {
        return *it;
    }
}
Student* Group::FindStudent(int id) {
    list<Student *>::iterator it = FindStudById(id);
    if (it == GroupStudent.end()) {
        return NULL;
    } else {
        return *it;
    }
}

list<Student *> Group::ListStd() {
    return this->GroupStudent;
}

bool Group::ValidGroup() {
    for (auto& i: GroupStudent) {
        if (!i->valid_student()) return 0;
    }
    return 1;
}

list<string> Group::InfoGroup() {
    list<string> buff;
    for (auto& i: GroupStudent) {
        buff.push_back(i->Print_info());
    }
    return buff;
}

float Group::AvrGrade() {
    if (!GroupStudent.size()) {
        return 0;
    } else {
        int Grd = 0;
        for (auto& i: GroupStudent) {
            Grd += i->GetGrade();
        }
        return (float)Grd/GroupStudent.size();
    }  
}

void Group::SortByGrade() {
    GroupStudent.sort([](const Student *first, const Student *second) -> bool {
        return (first->GetGrade() < second->GetGrade());
    });
}

void Group::SortBySurname() {
    GroupStudent.sort([](const Student *first, const Student *second) -> bool {
        return (first->GetSurname() < second->GetSurname());
    });
}

void Group::SortByName() {
    GroupStudent.sort([](const Student *first, const Student *second) -> bool {
        return (first->GetName() < second->GetName());
    });
}

void DelSt(list<Group *> buf, int id) {
    for (auto &i: buf) {
        i->RmStGr(id); 
    }
}
#endif