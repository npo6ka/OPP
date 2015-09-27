#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
	static int count;
	string name;
	string surname;
	int grade;
	int id;

	bool valid_string(const string str) const;
	bool valid_grade() const;

public:
	Student (string name, string surname, int grade);
	~Student();
	Student(const Student &other);

	bool valid_student() const;

	string GetName() const;
	string GetSurname() const;
	int GetGrade() const;
	int GetId() const;

	void SetId();
	bool SetName(const string name);
	bool SetSurname(const string surname);
	bool SetGrade(const int pnt);

	bool AddGrade(int pnt);
	string Print_info() const;
};

int Student::count = 0;

bool Student::valid_string(const string str) const {
	return (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") == string::npos);
}
bool Student::valid_grade() const {
	return !(GetGrade() < 0);
}

Student::Student (string name, string surname, int grade): name(name), surname(surname), grade(0) {
	if (!SetName(name) || !SetSurname(surname) || !SetGrade(grade)) {
		cout << "Error create object student, data not valid" << endl;
	} else {
		SetId();
		this->count++;
	}
}
Student::~Student() {}
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

bool Student::AddGrade(int pnt) {
	return SetGrade(GetGrade() + pnt);
}
string Student::Print_info() const {
	return "Name: " + GetName() + " | Surname: " + GetSurname() + " | Grade: " + to_string(GetGrade());
}

#endif