#include <istream>
#include <iostream> 
#include <stdexcept>
#include <algorithm>
#include "Shape.h"

using std::cout;				using std::max;
using std::istream;				using std::domain_error;


istream& Triangle::read(istream& is) {
	is >> a >> b >> c;
	return is;	
}

istream& Rectangle::read(istream& is) {
	is >> lenth >> width; 
	return is;
}

istream& Circle::read(istream& is) {
	is >> radius;
	return is;
}

double Triangle::circumference () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)) || a <= 0 || b <= 0 || c <= 0)
		throw domain_error ("invalid side lenth");
	return a + b + c;
}

double Triangle::area () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)) || a <= 0 || b <= 0 || c <= 0)
		throw domain_error ("invalid side lenth");
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Rectangle::circumference () const {
	if (lenth <= 0 || width <= 0)
		throw domain_error ("invalid side lenth");
	return (lenth + width) * 2;
}

double Rectangle::area () const {
	if (lenth <= 0 || width <= 0)
		throw domain_error ("invalid side lenth");
	return lenth * width;
}

double Circle::circumference () const {
	if (radius <= 0)
		throw domain_error ("invalid side lenth");
	return 2 * 3.14159265358 * radius;
}

double Circle::area () const {
	if (radius <= 0)
		throw domain_error ("invalid side lenth");
	return 3.14159265358 * radius * radius;
}

istream& Figure::read (istream& is) {
	delete s;
	char ch;
	is >> ch;
	if (ch == 'T')
		s = new Triangle(is);
	else if (ch == 'R')
		s = new Rectangle(is);
	else
		s = new Circle(is);
	return is;
}

Figure::Figure(const Figure& f) : s(0) {
	if (f.s)
		s = f.s->clone();
}

Figure& Figure::operator= (const Figure& f) {
	if (&f != this) {
		delete s;
		if (f.s)
			s = f.s->clone();
		else
			s = 0;
	}
	return *this;
}

