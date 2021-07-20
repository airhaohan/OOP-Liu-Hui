#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Core.h"

using std::cin;				using std::cout;
using std::endl;			using std::max;
using std::vector;			using std::string;
using std::ifstream;		using std::ofstream;
using std::domain_error;

int main () {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	ifstream infile("grades2");
	ofstream outfile("final2");
	while (record.read(infile)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	sort (students.begin(), students.end(), Student_info::compare);
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		outfile << students[i].name() << string(maxlen - students[i].name().size() + 1, ' ');
		cout << students[i].name() << string(maxlen - students[i].name().size() + 1, ' ');
		try {
			double final_grade = students[i].grade();
			outfile << final_grade;
			cout << final_grade;
		}
		catch (domain_error e) {
			outfile << e.what();
			cout << e.what();
		}
		outfile << endl;
		cout << endl;
	}
	return 0;
}
