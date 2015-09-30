#include <iostream>
#include "Student.h"
#include "Groups.h"

using namespace std;

void printGroup(list<string> buff) {
	for (auto& i: buff) {
		cout << i << endl;
	}
	cout << endl;
}
int main()
{
	Student ab1("anton", "ivanov", 7);
	Student ab2("svetlana", "petrova", 12);
	Student ab3("vlad", "sidorov", 3);
    Student ab4("dmitriy", "egorova", 18);
    Student ab5("maria", "fedorova", 10);
	Group group0;
    Group group1;
    Group group2;
    group0.Add_student(&ab1);
	group0.Add_student(&ab3);
    group0.Add_student(&ab2);
	group1.Add_student(&ab4);
    group1.Add_student(&ab1);
	group1.Add_student(&ab5);
    group2.Add_student(&ab2);
	group2.Add_student(&ab4);
	group0.Add_student(&ab3);
    group0.Add_student(&ab4);
    group0.Add_student(&ab5);
    cout << "Average grade: " << group0.AvrGrade() << endl;\
    cout << "list group:" << endl;
    printGroup(group0.InfoGroup());
    group0.SortByGrade();
    cout << "Sort by Grade:" << endl;
    printGroup(group0.InfoGroup());
    group0.SortBySurname();
    cout << "Sort by Surname:" << endl;
    printGroup(group0.InfoGroup());
    group0.SortBySurname();
    printGroup(group0.InfoGroup());
	group0.FindStudent(2);
	group0.Rem_student(0);
	group0.Rem_student("vlad", "sidorov");
	group0.Rem_student(&ab2);
    cout << group0.AvrGrade() << endl;
    printGroup(group0.InfoGroup());
	return 0;
}

