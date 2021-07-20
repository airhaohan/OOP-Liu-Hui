#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <istream>
#include <vector>
#include <string>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	double total;		//×ÜÆÀ³É¼¨ 
};

bool compare (const Student_info& x, const Student_info& y);
std::istream& read_hw (std::istream&, std::vector<double>&);
std::istream& read (std::istream&, Student_info&);

#endif
#pragma once
