#include <istream>
#include <iostream> 
#include <stdexcept>
#include <algorithm>
#include "Shape.h"

using std::cout;			using std::domain_error;
using std::max;				using std::istream;

istream& operator>> (istream& is, Triangle& t) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		t.a = temp; 
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		t.b = temp; 
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		t.c = temp; 
	return is;
}

istream& operator>> (istream& is, Rectangle& r) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		r.lenth = temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		r.width = temp; 
	return is;
}

istream& operator>> (istream& is, Circle& c) {
	double temp;
	is >> temp;
	if (temp <= 0)
		throw domain_error("输入错误！");
	else
		c.radius = temp;
	return is;
}

double Triangle::circumference () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)))
		throw domain_error ("不能构成三角形！");
	return a + b + c;
}

double Triangle::area () const {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)))
		throw domain_error ("不能构成三角形！");
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
