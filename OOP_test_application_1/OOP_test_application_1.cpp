#include <iostream>
#include "Student.h"
#include "Groups.h"

using namespace std;

int main()
 {
	Student ab1("anton", "ivanov", 12);
	Student ab2("svetlana", "petrova", 7);
	Student ab3("vlad", "sidorov", 3);
	std::cout << ab1.Print_info() << endl;
	std::cout << ab2.Print_info() << endl;
	std::cout << ab3.Print_info() << endl;
	Group group;
	group.add_student(&ab1);
	group.add_student(&ab2);
	group.add_student(&ab3);
	group.FindStudById(1);
	group.FindStudByName("vlad", "sidorov");
	group.FindStudByRef(&ab2);
	//group.rem_student(&ab3);

	/*group.add_student("sidor", "abcda", 10);
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
	// erasing from list
	return 0;
}


/*#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);
  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout,"\n"));
                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^
  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout,"\n"));
  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^
  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout,"\n"));
  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^
  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout,"\n"));
  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^
  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout,"\n"));
  //mylist.erase (it1, mylist.end());     // 10 30 60 80 90
                              //        ^
  for (auto& x: mylist)
    std::cout << " (" << x << ")";

  copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout," "));
  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}*/

