#ifndef GUARD_selectsort_h
#define GUARD_selectsort_h

template <class T>
void my_swap (T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <class Bi>
void selectSort (Bi b, Bi e) {
	while (b != e) {
		Bi flag = b;
		for (Bi it = b; it != e; it++)
			if (*flag > *it)
				flag = it;
		//½»»»
		my_swap (*b, *flag);
		++b;
	}
}

#endif
#pragma once
