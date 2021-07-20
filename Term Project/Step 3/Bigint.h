#ifndef GUARD_Bigint_h
#define GUARD_Bigint_h

#include <vector>
#include <ostream>
#include <istream>

class Bigint {
	friend std::istream& operator>> (std::istream&, Bigint&);
	public:
		typedef std::vector<int>::size_type size_type;
		
		int& operator[] (size_type i) { return bigint[i]; }
		const int& operator[] (size_type i) const { return bigint[i]; }
		
		//Constructor
		Bigint();
		Bigint(int);
		Bigint(size_t n, unsigned int v) {
			bigint.push_back(0);
			if (!v)		//�ų����������� 
				bigint.push_back(0);
			else {
				for (size_type i = 0; i < n; ++i)
					bigint.push_back(v);
			}
		}
		
		Bigint& operator-();
		
		size_type size() const { return bigint.size() - 1; }	//����������λ�����Լ�һ 
		
		void output();	//���bigint 
	
	private:
		std::vector<int> bigint;
};

std::ostream& operator<< (std::ostream&, const Bigint&);
bool operator== (const Bigint& b1, const Bigint& b2);
bool operator!= (const Bigint& b1, const Bigint& b2);
bool operator>= (const Bigint& b1, const Bigint& b2);
bool operator<= (const Bigint& b1, const Bigint& b2);
bool operator>  (const Bigint& b1, const Bigint& b2);
bool operator<  (const Bigint& b1, const Bigint& b2);	
Bigint absv(const Bigint&);


#endif
#pragma once
