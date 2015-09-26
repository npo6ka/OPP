#include <iostream>
#include <vector>
#include "Student.h"
#include "Groups.h"
#include <string>

using namespace std;

int main()
 {
	Student student("sidor", "AZaz", 3);
	student.SetName("lox");
	std::cout << student.Print_info() << endl;
	/*Group group;
	group.add_student("sidor", "abcda", 10);
	group.add_student("pidor", "abcdf", 9);
	group.add_student("sigor", "abcdb", 8);
	group.add_student("midor", "abcd", 7);
	cout << group.avg_point() << endl;
	group.print_group();
	group.sort_point();
	group.print_group();
	group.sort_sname();
	group.print_group();
	group.rem_student(1);
	group.print_group();
	group.destroy();*/
	return 0;
}