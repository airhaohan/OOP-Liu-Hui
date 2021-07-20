#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <string>
#include <vector>
#include <iostream>

class Student_info {
	public:
		//constructor
		Student_info();
		Student_info(std::istream&);	//加上explicit防止不自然的隐式类型转换 
		
		std::string name() const { return n; };	//accessor function
		bool valid() const { return !homework.empty(); };
		std::istream& read(std::istream&);
		double grade() const;
		
	private:
		std::string n;
		double midterm, final;
		std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
#endif
