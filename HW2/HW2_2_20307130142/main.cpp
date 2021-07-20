#include <vector>
#include <string>
#include <istream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using std::cin;			using std::cout;
using std::max;			using std::endl;
using std::sort;		using std::streamsize;
using std::vector;		using std::setprecision;
using std::string;		using std::domain_error;
using std::istream;

int main () {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	while (read(cin, record)) {
		//记录最长名字的长度，便于之后输出报表对齐 
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		try {
			students[i].total = grade(students[i]);		
		}
		//如果没有做平时作业的话，总评分数记为 0 
		catch (domain_error) {
			students[i].total = 0;	
		}
	}
	//通过总评分数来排序 
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			streamsize prec = cout.precision();
			cout << setprecision(3) << grade(students[i]) << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
