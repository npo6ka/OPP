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
	Group()	{}
	~Group() {}
	bool add_student(char *name, char *surname, char *patronymic, int points) {
		Student stud(name, surname, patronymic, points);
		if (stud.valid_student()) {
			student.insert(student.end(), stud);
			return 1;
		} else {
			return 0;
		}
	}
	bool rem_student(int num) {
		if ((int)student.size() >= num && num >=0) {
			student.erase(student.begin()+num);
			return 1;
		} else {
			return 0;
		}
	}
	void destroy() {
		if (!student.empty()) {
			student.clear();
		}
	}
	float avg_point() {
		int sum = 0;
		for (int i = 0; i < (int)student.size(); i++) {
			sum += student[i].GetPoint();
		}
		return (float)sum / student.size();
	}
	void sort_sname() {
		for (int i = 0; i < (int)student.size() - 1 ; i++) {
			for (int j = i; j < (int)student.size() - 1; j++) {
				int k = 0;
				//i?iaa?ea no?ie
				do {
					if (student[j].GetSurname()[k] == student[j+1].GetSurname()[k]) {
						k++;
					} else {
						
						if (student[j].GetSurname()[k] < student[j+1].GetSurname()[k]) {
							k = 0;
						} else {
							k = -1;
						}
					}
				} while (k > 0 && student[j].GetSurname()[k] != '\0' &&  student[j+1].GetSurname()[k] != '\0');
				// e = 0 no?iee iaai iiiaiyou ianoaie
				if (k == 0) {
					Student stud = student[j];
					student[j] = student[j+1];
					student[j+1] = stud;
				}
			}
		}
	}
	void sort_point() {
		for (int i = 0; i < (int)student.size() - 1 ; i++) {
			for (int j = i; j < (int)student.size() - 1; j++) {
				if (student[j].GetPoint() < student[j+1].GetPoint()) {
					Student stud = student[j];
					student[j] = student[j+1];
					student[j+1] = stud;
				}
			}
		}
	}
	void print_group() {
		for (int i = 0; i < (int)student.size(); i++) {
			student[i].print_info();
		}
		cout << endl;
	}

};

int main()
 {
	//Student student("sidor", "AZaz", "asdas", 3);
	//student.SetName("lox");
	//student.print_info();
	Group group;
	group.add_student("sidor", "abcda", "zxcv", 10);
	group.add_student("pidor", "abcdf", "ghhdf", 9);
	group.add_student("sigor", "abcdb", "atyu", 8);
	group.add_student("midor", "abcd", "ubndg", 7);
	cout << group.avg_point() << endl;
	group.print_group();
	group.sort_point();
	group.print_group();
	group.sort_sname();
	group.print_group();
	group.rem_student(1);
	group.print_group();
	group.destroy();
	return 0;
}