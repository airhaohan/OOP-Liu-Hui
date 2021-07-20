#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Bigint.h"

using std::cin;				using std::cout;
using std::endl;			using std::max;
using std::string;			using std::vector;



int main () {
	int a = 0, b = 1234, c = INT_MIN, d = INT_MAX;  
	Bigint num1(a), num2(b), num3(c), num4(d), num5;
	//分别输出五个数字和它们的大小 
	cout << "num1 is ";
	num1.output();
	cout << endl << "the size of num1 is " << num1.size() << endl;
	cout << "num2 is ";
	num2.output();
	cout << endl << "the size of num2 is " << num2.size() << endl;
	cout << "num3 is ";
	num3.output();
	cout << endl << "the size of num3 is " << num3.size() << endl;
	cout << "num4 is ";
	num4.output();
	cout << endl << "the size of num4 is " << num4.size() << endl;
	cout << "num5 is ";
	num5.output();
	cout << endl << "the size of num5 is " << num5.size() << endl;
	return 0;
}
