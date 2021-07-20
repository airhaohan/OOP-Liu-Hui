#ifndef GUARD_median_h
#define GUARD_median_h

#include <stdexcept>

// 'median.h'
template <class It, class T>
T median(It b, It e, T begin_element) {	//为了实例化，需要提供一个参数begin_element来知道T是什么类型 
	int size = e - b;
	if (size == 0)
		throw std::domain_error("median of an empty vector");
	//创建新的数组储存给定的范围内的数据 
	T* p = new T[size];
	for (int i = 0; i != size; ++i)
		p[i] = *b++;
	//冒泡排序 
	for (int i = 1; i != size; ++i) {
		bool flag = true;
		for (int j = 0; j != size - i; ++j) {
			if (p[j] > p[j + 1]) {
				flag = false;
				T temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
		if (flag)
			break;
	}
	int mid = size / 2;
	T mid_num = size % 2 == 0 ? (p[mid] + p[mid - 1]) / 2 : p[mid];
	delete[] p;
	return mid_num;
}

#endif
#pragma once
