#include <string>
#include <istream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Core.h"

using std::cin;				using std::cout;
using std::max;				using std::endl;
using std::vector;			using std::string;
using std::ifstream;		using std::ofstream;
using std::streamsize;		using std::domain_error;
using std::setprecision;

int main () {
	vector<Core*> students;
	Core* record;
	char ch;
	string::size_type maxlen = 0;
	ifstream infile("grades2");
	ofstream outfile("final2");
	while (infile >> ch) {
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(infile);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), compare_Core_ptrs);
	for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
		outfile << students[i]->name() << string (maxlen + 1 - students[i]->name().size(), ' ');
		cout << students[i]->name() << string (maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec1 = outfile.precision();
			streamsize prec2 = cout.precision();
			outfile << setprecision(3) << final_grade << setprecision(prec1) << endl;
			cout << setprecision(3) << final_grade << setprecision(prec2) << endl;
		}
		catch (domain_error e) {
			outfile << e.what() << endl;
			cout << e.what() << endl;
		}
		delete students[i];
	}
	return 0;
}
