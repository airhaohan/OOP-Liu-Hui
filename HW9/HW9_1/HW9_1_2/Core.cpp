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

istream& Student_info::read (istream& is) {
	delete cp;
	char ch;
	is >> ch;
	if (ch == 'U')
		cp = new Core(is);
	else
		cp = new Grad(is);
	return is;
}

Student_info::Student_info (const Student_info& s) : cp(0) {
	if (s.cp)
		cp = s.cp->clone();
}

Student_info& Student_info::operator= (const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}
