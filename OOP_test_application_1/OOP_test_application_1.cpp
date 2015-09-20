#include "stdafx.h"
#include <iostream>

using namespace std;

class Student
{
	char *name;
	char *surname;
	char *patronymic;
	int points;


public:
	Student (char *name, char *surname, char *patronymic, int points) {
		if (!SetName(name) || !SetSurname(surname) || !SetPatronymic(patronymic) || !SetPoints(points)) {
			cout << "Error create class student, data not valid" << endl;
		} 
	}
	Student (char *name, char *surname, char *patronymic) {
		Student(name, surname, patronymic, 0);
	}
	~Student() {
		//delete(name);
		//delete(surname);
		//delete(patronymic);
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
	bool valid_student()
	{
		return valid_string(GetName()) && valid_string(GetSurname()) && valid_string(GetPatronymic()) && GetPoint();
	}

	bool SetName(char *name) {
		if (valid_string(name)) {
			this->name = name;
			return 1;
		} else {
			return 0;
		}
	}
	bool SetSurname(char *surname) {
		if (valid_string(surname)) {
			this->surname = surname;
			return 1;
		} else {
			return 0;
		}
	}
	bool SetPatronymic(char *patr) {
		if (valid_string(patr)) {
			this->patronymic = patr;
			return 1;
		} else {
			return 0;
		}
	}
	bool SetPoints(int pnt) {
		if (pnt >= 0) {
			this->points = pnt;
			return 1;
		} else {
			return 0;
		}
	}

	bool addpoint(int pnt) {
		if(SetPoints(GetPoint() + pnt)) {
			return 1;
		} else {
			return 0;
		}
	}
	void print_info() {
		if (valid_student()) {
			cout << "Name: " << GetName() << " | Surname: " << GetSurname() << " | Patronymic: " << GetPatronymic() << " | Point: " << GetPoint() << endl;
		} else {
			cout << "Value in class Student is not valid" << endl;
		}
	}
};

int main()
 {
	Student student("sidor", "AZaz", "asdas", 3);
	student.print_info();
	return 0;
}

