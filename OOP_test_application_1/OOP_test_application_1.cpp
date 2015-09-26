#include <iostream>
#include <vector>
#include "Student.h"
#include "Groups.h"

using namespace std;

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