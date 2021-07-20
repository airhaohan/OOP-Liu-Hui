#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Bigint.h"

using std::cout;			using std::cin;
using std::endl;			using std::domain_error;			

int main () {
	try {
		cout << "测试构造函数、size()函数和输出函数" << endl; 
		int a = 0, b = 1234, c = INT_MIN, d = INT_MAX;  
		Bigint num1(a), num2(b), num3(c), num4(d), num5;
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
		
		cout << "测试构建每一位都为 v 的 n 位大整数" << endl;
		int n, v;
		cout << "请输入 n 和 v (0 <= v <= 9)" << endl;
		cin >> n >> v;
		Bigint b3(n, v);
		cout << b3 << endl;
		
		cout << endl <<"测试流输入操作" << endl; 
		Bigint b1, b2;
		cout << "请输入两个大整数：" << endl;
		cin >> b1 >> b2;
		
		cout << endl << "测试流输出操作" << endl; 
		cout << "b1为：" << b1 << endl;
		cout << "b2为：" << b2 << endl;
		
		cout << endl << "测试大整数间重载的关系运算符" << endl; 
		if (b1 > b2)
			cout << b1 << " > "  << b2 << endl; 
		if (b1 >= b2)
			cout << b1 << " >= " << b2 << endl; 
		if (b1 < b2)
			cout << b1 << " < "  << b2 << endl; 
		if (b1 <= b2)
			cout << b1 << " <= " << b2 << endl; 
		if (b1 == b2)
			cout << b1 << " == " << b2 << endl; 
		if (b1 != b2)
			cout << b1 << " != " << b2 << endl;
			
		cout << endl << "测试绝对值函数和取负操作符" << endl; 
		cout << "b1的绝对值为：" << absv(b1) << endl;
		cout << "b1的相反数为：" << -b1 << endl;
		
		cout << endl << "测试大整数间重载的运算符" << endl;
		cout <<  "b1 + b2 = " << b1 + b2 << endl;
		cout <<  "b1 - b2 = " << b1 - b2 << endl;
		cout <<  "b1 * b2 = " << b1 * b2 << endl;
		cout <<  "b1 / b2 = " << b1 / b2 << endl;
		cout <<  "b1 % b2 = " << b1 % b2 << endl;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}
