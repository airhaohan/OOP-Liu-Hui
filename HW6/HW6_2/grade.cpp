#include <string>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using std::string;			using std::domain_error;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and Vec of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const Vec<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw.begin(), hw.end(), hw[0]));
}

//数值成绩转换为对应的字母等级成绩
string letter_grade(const double grade) {
	static const double numbers[] = { 90, 85, 82, 78, 75, 71, 66, 62, 60, 0 };
	static const char* const letters[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	for (size_t i = 0; i != ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
	}
	return "?/?/?";
}
