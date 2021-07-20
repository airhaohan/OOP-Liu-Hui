#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <string>
#include <fstream>
#include <iostream>
#include "Vec.h"

class Student_info {
public:
	//constructor
	Student_info();
	Student_info(std::istream&);

	std::string name() const { return n; };	//accessor function
	bool valid() const { return !homework.empty(); };
	std::istream& read(std::istream&);
	std::ifstream& read(std::ifstream&);	//changed 
	double grade() const;

private:
	std::string n;
	double midterm, final;
	Vec<double> homework;
};

bool compare(const Student_info&, const Student_info&);
#endif
#pragma once
