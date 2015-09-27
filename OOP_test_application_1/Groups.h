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
	Group(const Student &other);
	bool add_student(Student *stud);
	bool rem_student (int id);
	bool rem_student (Student *stud);
	bool rem_student (string name, string sname);
	
};

Group::Group()	{}
Group::~Group() {}
Group::Group(const Student &other) {
	*this = other;
}

bool Group::add_student(Student *stud) {
	if (stud->valid_student() && FindStudById(stud->GetId()) == GroupStudent.end()) {
		GroupStudent.push_front(stud);
		return 1;
	} else {
		return 0;
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
	if (it != GroupStudent.end() && it._Ptr->_Myval->valid_student()) {
		GroupStudent.erase(it);
		return 1;
	} else {
		return 0;
	}
}

bool Group::rem_student(int id) {
	return RmStud(FindStudById(id));
}
bool Group::rem_student(Student *stud) {
	return RmStud(FindStudByRef(stud));
}
bool Group::rem_student(string name, string sname) {
	return RmStud(FindStudByName(name, sname));
}

//cout << it._Ptr->_Myval->GetName() << endl;

/*if ((int)student.size() >= num && num >=0) {
		student.erase(student.begin()+num);
		return 1;
	} else {
		return 0;
	}*/

/*list<Student> Group::FindStudent(int id)
{

}*/

//void destroy() {
	//	if (!student.empty()) {
	//		student.clear();
	//	}
	//}
	//float avg_point() {
	//	int sum = 0;
	//	for (int i = 0; i < (int)student.size(); i++) {
	//		sum += student[i].GetPoint();
	//	}
	//	return (float)sum / student.size();
	//}
	//void sort_sname() {
	//	for (int i = 0; i < (int)student.size() - 1 ; i++) {
	//		for (int j = i; j < (int)student.size() - 1; j++) {
	//			int k = 0;
	//			do {
	//				if (student[j].GetSurname()[k] == student[j+1].GetSurname()[k]) {
	//					k++;
	//				} else {
	//					
	//					if (student[j].GetSurname()[k] < student[j+1].GetSurname()[k]) {
	//						k = 0;
	//					} else {
	//						k = -1;
	//					}
	//				}
	//			} while (k > 0 && student[j].GetSurname()[k] != '\0' &&  student[j+1].GetSurname()[k] != '\0');
	//			if (k == 0) {
	//				Student stud = student[j];
	//				student[j] = student[j+1];
	//				student[j+1] = stud;
	//			}
	//		}
	//	}
	//}
	//void sort_point() {
	//	for (int i = 0; i < (int)student.size() - 1 ; i++) {
	//		for (int j = i; j < (int)student.size() - 1; j++) {
	//			if (student[j].GetPoint() < student[j+1].GetPoint()) {
	//				Student stud = student[j];
	//				student[j] = student[j+1];
	//				student[j+1] = stud;
	//			}
	//		}
	//	}
	//}
	//void print_group() {
	//	for (int i = 0; i < (int)student.size(); i++) {
	//		student[i].print_info();
	//	}
	//	cout << endl;
	//}
;
#endif