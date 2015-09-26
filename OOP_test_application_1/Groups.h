/*#ifndef GROUPSTUDENT_H
#define GROUPSTUDENT_H

using namespace std;

class Group
{
	vector<Student> student;
public:
	Group()	{}
	~Group() {}
	bool add_student(char *name, char *surname, int grade) {
		Student stud(name, surname, grade);
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

#endif*/