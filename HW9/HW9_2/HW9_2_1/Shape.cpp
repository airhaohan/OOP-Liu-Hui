#include <istream>
#include <iostream> 
#include <stdexcept>
#include <algorithm>
#include "Shape.h"

using std::cout;			using std::domain_error;
using std::max;				using std::istream;


istream& Triangle::read(istream& is) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		a = temp; 
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		b = temp; 
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		c = temp; 
	return is;	
}

istream& Rectangle::read(istream& is) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		lenth = temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		width = temp; 
	return is;
}

istream& Circle::read(istream& is) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("input error");
	else
		radius = temp;
	return is;
}

double Triangle::circumference () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)))
		throw domain_error ("invalid side lenth");
	return a + b + c;
}

double Triangle::area () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)))
		throw domain_error ("invalid side lenth");
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Rectangle::circumference () const {
	return (lenth + width) * 2;
}

double Rectangle::area () const {
	return lenth * width;
}

double Circle::circumference () const {
	return 2 * 3.14159265358 * radius;
}

double Circle::area () const {
	return 3.14159265358 * radius * radius;
}
