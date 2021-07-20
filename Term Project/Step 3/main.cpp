#include <ostream>
#include <istream>
#include <stdexcept>
#include <iostream>
#include "Bigint.h"

using std::cin;			using std::cout;
using std::endl;		using std::istream;
using std::ostream;		using std::domain_error;

int main () {
	Bigint b1;
	cout << "请输入一个大整数：";
	try {
		cin >> b1;
	}
	catch (domain_error e) {
		cout << e.what();
		return 0;
	}
	
	cout << "这个大整数为：" << b1 << endl;
	cout << "测试绝对值函数" << endl; 
	cout << "这个大整数的绝对值为：" << absv(b1) << endl;
	cout << "测试取负操作符" << endl; 
	cout << "这个大整数的相反数为：" << -b1 << endl;
	
	return 0;
}
