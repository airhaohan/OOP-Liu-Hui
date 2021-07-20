#ifndef GUARD_commom_find_h
#define GUARD_commom_find_h

#include <iostream>
#include <algorithm>
#include <vector>


//寻找公共元素函数 
template <class T>
std::vector<T> find_common (const std::vector<T>& vec1, const std::vector<T>& vec2) {
	std::vector<T> ret;
	//按照vec1的顺序逐个寻找公共元素 
	for (typename std::vector<T>::size_type i = 0; i != vec1.size(); i++)
		if (find(vec2.begin(), vec2.end(), vec1[i]) != vec2.end())
			ret.push_back(vec1[i]);
	//返回存有公共元素的容器 
	return ret;
}

//输出函数 
template <class T>
void output (const std::vector<T>& vec) {
	for (typename std::vector<T>::size_type i = 0; i != vec.size(); i++)
		std::cout << vec[i] << "  ";
	std::cout << std::endl;
}

#endif
#pragma once
