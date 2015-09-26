#ifndef STUDENT_H
#define STUDENT_H

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

#endif