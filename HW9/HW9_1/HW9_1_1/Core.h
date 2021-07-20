#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <vector>
#include <iostream>
#include <stdexcept>

class Core {
	friend class Student_info;
	public:
		Core() : midterm(0), final(0) { }
		Core(std::istream& is) { read(is); }
		virtual ~Core() { }
		
		std::string name() const { return n; }
		
		virtual std::istream& read(std::istream&);
		virtual double grade() const;
	
	protected:
		std::istream& read_common(std::istream&);
		double midterm, final;
		std::vector<double> homework;
	
	private:
		std::string n;		
};

class Grad : public Core {
	public:
		Grad() : thesis(0) { }
		Grad(std::istream& is) { read(is); }
		
		double grade() const;
		std::istream& read(std::istream&);
	
	private:
		double thesis;
};

bool compare (const Core&, const Core&);
bool compare_Core_ptrs (const Core*, const Core*);

#endif
#pragma once
