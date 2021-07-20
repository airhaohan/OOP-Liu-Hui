#ifndef GUARD_my_func_h 
#define GUARD_my_func_h

#include <iostream>
#include <vector>

template <class It, class T>
T accumulate (It b, It e, T t) {
	while (b != e) {
		t += *b;		
		b++;
	}
	return t;
}

template <class It>
It max_element (It b, It e) {
	It m = b;
	while (b != e) {
		if (*m < *b)
			m = b;
		b++;
	}
	return m;
}

template <class It>
It min_element (It b, It e) {
	It m = b;
	while (b != e) {
		if (*m > *b)
			m = b;
		b++;
	}
	return m;
}
template <class It>
void output (It b, It e) {
	while (b != e) {
		std::cout << *b << "  ";
		b++;
	}
	std::cout << std::endl;
}

#endif
#pragma once
