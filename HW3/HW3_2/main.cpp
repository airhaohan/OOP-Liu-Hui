#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "common_find.h"

using std::cin;			using std::cout;
using std::endl;		using std::vector;
using std::string;

int main () {
	vector<int> vec1, vec2;
	srand(time(NULL));
	//随机创建两个拥有14个整型数据、范围在[1，20]的vector并输出公共部分 
	cout << "Integer list 1:" << endl;
	for (int i = 0; i != 14; ++i)
		vec1.push_back(rand() % 20 + 1);
	output(vec1);
	cout << "Integer list 2:" << endl;
	for (int i = 0; i != 14; ++i)
		vec2.push_back(rand() % 20 + 1);
	output(vec2);
	vector<int> intersection = find_common(vec1, vec2);
	cout << "List in common:" << endl;
	output(intersection);
	
	//读入两个vector<string>并输出公共部分 
	vector<string> s1, s2;
	string record;
	cout << "Enter some words for string list 1:" << endl;
	while (cin >> record)
		s1.push_back(record);
	cin.clear();
	cout << "Enter some words for string list 2:" << endl;
	while (cin >> record)
		s2.push_back(record);
	vector<string> intersection2 = find_common(s1, s2);
	cout << "List in common:" << endl;
	output(intersection2);
	return 0;
}
