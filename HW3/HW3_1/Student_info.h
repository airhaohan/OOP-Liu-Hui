#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <list>
#include <vector>
#include <string>
#include <istream>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	double total;		//�����ɼ� 
};

bool compare(const Student_info& x, const Student_info& y);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);
bool fgrade (Student_info&);
std::list<Student_info> extract_fails (std::list<Student_info>&);

#endif
#pragma once
