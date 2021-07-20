#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

double grade(const double& midterm, const double& final, const vector<double>& homework) {
	if (!homework.size()) {
		throw domain_error("student has done no homework");
	}
	return grade(midterm, final, median(homework));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}
