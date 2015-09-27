#ifndef GROUPSTUDENT_H
#define GROUPSTUDENT_H

#include <list>
#include <algorithm>
using namespace std;

class Group
{
    list<Student *> GroupStudent;
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
    bool ValidGroup();
    list<string> InfoGroup();
    float AvrGrade();
    void SortByGrade();
};

Group::Group()    {}
Group::~Group() {}
Group::Group(const Group &other) {
    *this = other;
}

bool Group::Add_student(Student *stud) {
    Group buff = *this;
    GroupStudent.push_front(stud);
    if (!ValidGroup() || FindStudById(stud->GetId()) == GroupStudent.end()) {
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
    return std::search_n(GroupStudent.begin(), GroupStudent.end(), 1, stud);
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
    return *FindStudByName(name, sname);
}
Student* Group::FindStudent(int id) {
    return *FindStudById(id);
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


//void destroy() {
    //    if (!student.empty()) {
    //        student.clear();
    //    }
    //}
    //float avg_point() {
    //    int sum = 0;
    //    for (int i = 0; i < (int)student.size(); i++) {
    //        sum += student[i].GetPoint();
    //    }
    //    return (float)sum / student.size();
    //}
    //void sort_sname() {
    //    for (int i = 0; i < (int)student.size() - 1 ; i++) {
    //        for (int j = i; j < (int)student.size() - 1; j++) {
    //            int k = 0;
    //            do {
    //                if (student[j].GetSurname()[k] == student[j+1].GetSurname()[k]) {
    //                    k++;
    //                } else {
    //                    
    //                    if (student[j].GetSurname()[k] < student[j+1].GetSurname()[k]) {
    //                        k = 0;
    //                    } else {
    //                        k = -1;
    //                    }
    //                }
    //            } while (k > 0 && student[j].GetSurname()[k] != '\0' &&  student[j+1].GetSurname()[k] != '\0');
    //            if (k == 0) {
    //                Student stud = student[j];
    //                student[j] = student[j+1];
    //                student[j+1] = stud;
    //            }
    //        }
    //    }
    //}
    //void sort_point() {
    //    for (int i = 0; i < (int)student.size() - 1 ; i++) {
    //        for (int j = i; j < (int)student.size() - 1; j++) {
    //            if (student[j].GetPoint() < student[j+1].GetPoint()) {
    //                Student stud = student[j];
    //                student[j] = student[j+1];
    //                student[j+1] = stud;
    //            }
    //        }
    //    }
    //}
;
#endif