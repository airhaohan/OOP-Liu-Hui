#ifndef GUARD_Bigint_h
#define GUARD_Bigint_h

#include <vector>

class Bigint {
	public:
		typedef std::vector<int>::size_type size_type;
		
		//Constructor
		Bigint ();
		Bigint (int);
		
		size_type size () const { return bigint.size() - 1; }	//不包括符号位，所以减一 
		
		void output();	//输出bigint 
		
	private:
		std::vector<int> bigint;
};

#endif
#pragma once
