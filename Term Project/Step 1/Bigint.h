#ifndef GUARD_Bigint_h
#define GUARD_Bigint_h

#include <vector>

class Bigint {
	public:
		typedef std::vector<int>::size_type size_type;
		
		//Constructor
		Bigint ();
		Bigint (int);
		
		size_type size () const { return bigint.size() - 1; }	//����������λ�����Լ�һ 
		
		void output();	//���bigint 
		
	private:
		std::vector<int> bigint;
};

#endif
#pragma once
