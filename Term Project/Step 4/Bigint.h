#ifndef GUARD_Bigint_h
#define GUARD_Bigint_h

#include <vector>
#include <ostream>
#include <istream>

class Bigint {
	friend std::ostream& operator<< (std::ostream&, const Bigint&);
	friend std::istream& operator>> (std::istream&, Bigint&);
	friend bool operator>  (const Bigint&, const Bigint&);
	friend bool operator== (const Bigint&, const Bigint&);
	friend Bigint operator+ (const Bigint&, const Bigint&);
	friend Bigint operator- (const Bigint&, const Bigint&);
	
	public:
		typedef std::vector<int>::size_type size_type;
		
		//Constructor
		Bigint();
		Bigint(int);
		Bigint(size_t n, unsigned int v) {
			bigint.push_back(0);
			if (!v)		//排除都是零的情况 
				bigint.push_back(0);
			else {
				for (size_type i = 0; i < n; ++i)
					bigint.push_back(v);
			}
		}
		
		Bigint operator-() const;
		
		size_type size() const { return bigint.size() - 1; }	//不包括符号位，所以减一 
		
		void output();	//输出bigint 
	
	private:
		std::vector<int> bigint;
		int& operator[] (size_type i) { return bigint[i]; }
		const int& operator[] (size_type i) const { return bigint[i]; }
};

bool operator!= (const Bigint&, const Bigint&);
bool operator>= (const Bigint&, const Bigint&);
bool operator<= (const Bigint&, const Bigint&);
bool operator<  (const Bigint&, const Bigint&);
Bigint absv(const Bigint&);

#endif
#pragma once
