#include <ios>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::sort;
using std::max;				using std::cout;
using std::endl;			using std::vector;
using std::string;   		using std::streamsize;
using std::setprecision;	using std::domain_error;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	while (record.read(cin)) {		//changed
		// find length of longest name
		maxlen = max(maxlen, record.name().size());	//changed
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {

		// write the name, padded on the right to 'maxlen+1' characters
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');	 //changed

		// compute and write the grade
		try {
			double final_grade = students[i].grade();	//changed
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
