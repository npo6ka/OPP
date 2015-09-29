#include <iostream>
#include "Student.h"
#include "Groups.h"


#include <list>
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
	
    Student ab4("vlad", "sidorov", 3);
    Student ab5("vlad", "sidorov", 3);
	Group group;
    group.Rem_student(0);
    group.FindStudent(2);
    group.FindStudent("asd", "asdas");
	group.Add_student(&ab1);
	group.Add_student(&ab2);
    {
        Student ab3("vlad", "sidorov", 3);
	    group.Add_student(&ab3);
    }
    group.Add_student(&ab4);
    group.Add_student(&ab5);
    cout << group.AvrGrade() << endl;
    printGroup(group.InfoGroup());
    group.SortByGrade();
    printGroup(group.InfoGroup());
    group.SortBySurname();
    printGroup(group.InfoGroup());
    group.SortBySurname();
    printGroup(group.InfoGroup());
	group.FindStudent(2);
	/*group.Rem_student(0);
	group.Rem_student("vlad", "sidorov");
	group.Rem_student(&ab2);*/
    cout << group.AvrGrade() << endl;
    printGroup(group.InfoGroup());
	return 0;
}

