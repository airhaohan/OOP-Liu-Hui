#include <ostream>
#include <istream>
#include <stdexcept>
#include <iostream>
#include "Bigint.h"

using std::cin;			using std::cout;
using std::endl;		using std::istream;
using std::ostream;		using std::domain_error;

int main () {
	
	cout << "测试流输入操作" << endl; 
	Bigint b1, b2;
	cout << "请输入两个大整数：";
	try {
		cin >> b1 >> b2;
	}
	catch (domain_error e) {
		cout << e.what();
		return 0;
	}
	
	cout << "测试流输出操作" << endl; 
	cout << "第一个大整数为：" << b1 << endl;
	cout << "第一个大整数为：" << b2 << endl;
	
	cout << "测试大整数间的关系运算符" << endl; 
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
		
	cout << "测试大整数与int间的关系运算符" << endl;
	cout << "请输入一个int型整数(用于与第一个整数比较大小)：";
	int temp;
	cin >> temp; 
	if (b1 == temp)
		cout << b1 << " == " << temp << endl;
	if (b1 != temp)
		cout << b1 << " != " << temp << endl;
	cout << "测试构建每一位都为 v 的 n 位大整数" << endl;
	int n, v;
	cout << "请输入 n 和 v (0 <= v <= 9)" << endl;
	cin >> n >> v;
	Bigint b3(n, v);
	cout << b3 << endl;
	return 0;
}
