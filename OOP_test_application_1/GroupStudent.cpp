#include "GroupStudent.h"

int Student::count = 0;

bool Student::valid_string(const string str) const {
    return (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") == string::npos);
}
bool Student::valid_grade() const {
    return !(GetGrade() < 0);
}
bool Student::add_group(Group * NumberGrp) {
    if (GrpSt.size() < 3) {
        GrpSt.push_back(NumberGrp);
        return 1;
    } else {
        return 0;
    }
}

Student::Student (string name, string surname, int grade): name(name), surname(surname), grade(0) {
    if (!SetName(name) || !SetSurname(surname) || !SetGrade(grade)) {
        cout << "Error create object student, data not valid" << endl;
    } else {
        SetId();
        this->count++;
    }
}
Student::~Student() {
    for (auto &i: GrpSt) {
        if (DelGrp(i)) {
            i->Rem_student(id);
        }
    }
}
Student::Student(const Student &other) {
    *this = other;
    //cout << "copy constructor\n"; 
}

bool Student::valid_student() const {
    return valid_string(GetName()) && valid_string(GetSurname()) && valid_grade();
}
 
string Student::GetName() const {
    return name;
}
string Student::GetSurname() const {
    return surname;
}
int Student::GetGrade() const  {
    return grade;
}
int Student::GetId() const {
    return id;
}

list <Group* > Student::GetGrp() const {
    return this->GrpSt;
}

void Student::SetId() {
    if (count < 0) {
        cout << "Error set unique id" << endl;
    } else {
        this->id = count; 
    }
}
bool Student::SetName(const string name) {
    string temp = GetName();
    this->name = name;
    if (valid_string(this->name)) {
        return 1;
    } else {
        this->name = temp;
        return 0;
    }
}
bool Student::SetSurname(const string surname) {
    string temp = GetSurname();
    this->surname = surname;
    if (valid_string(this->surname)) {
        return 1;
    } else {
        this->surname = temp;
        return 0;
    }
}
bool Student::SetGrade(const int pnt) {
    int temp = this->grade;
    this->grade = pnt;
    if (valid_grade()) {
        return 1;
    } else {
        this->grade = temp;
        return 0;
    }
}

bool Student::DelGrp(const Group * grp) {
    list<Group *>::iterator it = search_n(GrpSt.begin(), GrpSt.end(), 1, grp, 
                         [](const Group * i, const Group * j) -> bool { 
                             return (i == j); 
                         });
    if (it == GrpSt.end()) {
        return 0;
    } else {
        GrpSt.erase(it);
        return 1;
    }
}
bool Student::AddGrade(int pnt) {
    return SetGrade(GetGrade() + pnt);
}
string Student::Print_info() const {
    return "Name: " + GetName() + " | Surname: " + GetSurname() + " | Grade: " + to_string(GetGrade());
}

//------------------------------------------------------------------------------------------------

int Group::count = 0;

Group::Group() {
    if (count >= 0) {
        this->id = count;
        this->count++;
    }
}
Group::~Group() {
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
                         [](Student * i, const int j) -> bool { 
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

bool Group::Rem_student(int id) {
    return RmStud(FindStudById(id));
}
bool Group::Rem_student(Student *stud) {
    return RmStud(FindStudByRef(stud));
}
bool Group::Rem_student(string name, string sname) {
    return RmStud(FindStudByName(name, sname));
}

Student* Group::FindStudent(const string name, const string sname) {
    list<Student *>::iterator it = FindStudByName(name, sname);
    if (it == GroupStudent.end()) {
        return NULL;
    } else {
        return *it;
    }
}
Student* Group::FindStudent(const int id) {
    list<Student *>::iterator it = FindStudById(id);
    if (it == GroupStudent.end()) {
        return NULL;
    } else {
        return *it;
    }
}

bool Group::ValidGroup() const {
    for (auto& i: GroupStudent) {
        if (!i->valid_student()) return 0;
    }
    return 1;
}

list<Student *> Group::ListStd() const {
    return this->GroupStudent;
}

int Group::GetId() const {
    return this->id;
}

float Group::AvrGrade() const {
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

