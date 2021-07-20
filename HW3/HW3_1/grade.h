#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

inline double grade(double, double, double);
double grade(const double&, const double&, const std::vector<double>&);
double grade(const Student_info&);

//ÄÚÁªº¯Êý 
inline double grade(double midterm, double final, double homework) {
	return (0.2 * midterm + 0.4 * final + 0.4 * homework);
}

#endif
#pragma once