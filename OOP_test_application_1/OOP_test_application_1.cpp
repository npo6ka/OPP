#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Student
{
	char *name;
	char *surname;
	char *patronymic;
	int points;

	bool valid_string(char *str) {
		int i = 0;
		if (str) {
			while ((str[i] != '\0') && (i >= 0))
			{
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
					i++;
				} else {
					i = -1;
				}
			}
		}
		if (i <= 0) {
			return 0;
		} else {
			return 1;
		}
	}
	

public:
	Student (char *name, char *surname, char *patronymic, int points) {
		if (!SetName(name) || !SetSurname(surname) || !SetPatronymic(patronymic) || !SetPoints(points)) {
			cout << "Error create class student, data not valid" << endl;
		} 
	}
	/*Student (char *name, char *surname, char *patronymic) {
		Student(name, surname, patronymic, 0);
	}*/
	~Student() {
		//delete(name);
		//delete(surname);
		//delete(patronymic);
	}

	bool valid_student()
	{
		return valid_string(GetName()) && valid_string(GetSurname()) && valid_string(GetPatronymic()) && GetPoint();
	}

	char *GetName() {
		return name;
	}
	char *GetSurname() {
		return surname;
	}
	char *GetPatronymic() {
		return patronymic;
	}
	int GetPoint() {
		return points;
	}

	bool SetName(char *name) {
		char *temp = GetName();
		this->name = name;
		if (valid_string(this->name)) {
			return 1;
		} else {
			this->name = temp;
			return 0;
		}
	}
	bool SetSurname(char *surname) {
		char *temp = GetSurname();
		this->surname = surname;
		if (valid_string(this->surname)) {
			return 1;
		} else {
			this->surname = temp;
			return 0;
		}
	}
	bool SetPatronymic(char *patr) {
		char *temp = GetPatronymic();
		this->patronymic = patr;
		if (valid_string(this->patronymic)) {
			return 1;
		} else {
			this->patronymic = temp;
			return 0;
		}
	}
	bool SetPoints(int pnt) {
		int temp = this->points;
		this->points = pnt;
		if (valid_student()) {
			return 1;
		} else {
			this->points = temp;
			return 0;
		}
	}

	bool addpoint(int pnt) {
		return SetPoints(GetPoint() + pnt);
	}
	void print_info() {
		if (valid_student()) {
			cout << "Name: " << GetName() << " | Surname: " << GetSurname() << " | Patronymic: " << GetPatronymic() << " | Point: " << GetPoint() << endl;
		} else {
			cout << "Value in class Student is not valid" << endl;
		}
	}
};

class Group
{
	vector<Student> student;
public:
	Group()
	{

	}
	~Group()
	{

	}
	bool add_student(char *name, char *surname, char *patronymic, int points)
	{
		Student stud(name, surname, patronymic, points);
		if (stud.valid_student()) {
			student.insert(student.end(), stud);
			return 1;
		} else {
			return 0;
		}
	}
};

int main()
 {
	//Student student("sidor", "AZaz", "asdas", 3);
	//student.SetName("lox");
	//student.print_info();
	Group group;
	group.add_student("sidor", "werwer", "zxcv", 3);
	group.add_student("pidor", "ghkcvn", "ghhdf", 30);
	group.add_student("vigor", "rtyvbx", "atyu", 10000);
	group.add_student("midor", "cvlpbvbn", "ubndg", 200);
	return 0;
}

/*vector<int> m;
	for (int i=0; i<10; i++)
		m.insert(m.begin(), i);
	vector<int> m2 (m);
	//m2.reserve(10);
	m2.insert(m2.begin()+4, 100);
	copy(m.begin(), m.end(), ostream_iterator<int>(cout, "\n")); 
	copy(m2.begin(), m2.end(), ostream_iterator<int>(cout, "\n"));
	//m.~vector();
	//m2.~vector();*/