#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Vec.h"
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::cin;				using std::cout;
using std::sort;			using std::max;
using std::endl;			using std::string;
using std::ifstream;		using std::ofstream;
using std::domain_error;

int main()
{
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name
	ifstream infile("grades");
	ofstream outfile("final");
	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	while (record.read(infile)) {		//changed
		// find length of longest name
		maxlen = max(maxlen, record.name().size());	//changed
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (Vec<Student_info>::size_type i = 0;
		i != students.size(); ++i) {

		// write the name, padded on the right to 'maxlen+1' characters
		outfile << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');	 //changed
		cout << students[i].name()
			<< string(maxlen + 1 - students[i].name().size(), ' ');	 //changed

		// compute and write the grade
		try {
			double final_grade = students[i].grade();	//changed
			outfile << letter_grade(final_grade);
			cout << letter_grade(final_grade);
		}
		catch (domain_error e) {
			outfile << e.what();
			cout << e.what();
		}
		outfile << endl;
		cout << endl;
	}
	cout << "the following is the result of testing median function on array" << endl;
	srand(time(NULL));
	int* p = new int[11];
	cout << "the random array is:" << endl;
	for (int i = 0; i != 11; ++i) {
		p[i] = rand() % 101;
		cout << p[i] << '\t';
	}
	cout << endl << "the median of the array is: " << median(p, p + 11, *p) << endl;
	cout << "after median function called, the array is unchanged:" << endl;
	for (int i = 0; i != 11; ++i)
		cout << p[i] << '\t';
	delete[] p;
	return 0;
}

