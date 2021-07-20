#ifndef GUARD_grade_h
#define GUARD_grade_h

// 'grade.h'
#include <string>
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::string letter_grade (const double);

#endif
