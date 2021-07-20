#include <vector>
#include <istream>
#include <algorithm>
#include <stdexcept>
#include "Core.h"
#include "grade.h"
#include "median.h"

using std::min;				using std::vector;
using std::istream;			using std::domain_error;


double Core::grade () const {
	return ::grade(midterm, final, homework);
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

istream& Core::read_common (istream& is) {
	is >> n >> midterm >> final;
	return is;
}

istream& Core::read (istream& is) {
	read_common(is);
	read_hw(is, homework);
	return is;
}

istream& Grad::read (istream& is) {
	Core::read_common(is);
	is >> thesis;
	read_hw(is, homework);
	return is;
}

double Grad::grade () const {
	return min(Core::grade(), thesis);
}

bool compare (const Core& cp1, const Core& cp2) {
	return cp1.name() < cp2.name();
}

bool compare_Core_ptrs (const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

