#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Group;
void DelSt(list<Group *> buf, int id);

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

    bool Student::DelGrp(Group * grp);
	bool AddGrade(int pnt);
	string Print_info() const;
    friend Group;
};

int Student::count = 0;

bool Student::valid_string(const string str) const {
	return (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") == string::npos);
}
bool Student::valid_grade() const {
	return !(GetGrade() < 0);
}
bool Student::add_group(Group * NuGrp) {
    if (GrpSt.size() < 3) {
        GrpSt.push_back(NuGrp);
        return 1;
    } else {
        return 0;
    }
    return 0;
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
    DelSt(GetGrp(), id);
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

bool Student::DelGrp(Group * grp) {
    list<Group *>::iterator it = search_n(GrpSt.begin(), GrpSt.end(), 1, grp, 
                         [](Group * i, Group * j) -> bool { 
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

#endif