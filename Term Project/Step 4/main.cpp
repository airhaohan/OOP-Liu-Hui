#include <iostream>
#include "Bigint.h"

using std::cin;			using std::cout;
using std::endl;

int main()
{
	Bigint a, b; 
	
	//验证大整数之间的运算
	cout << "请输入a,b:" << endl;
	cin >> a >> b;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	// 验证大整数与整数的混合运算，注意step1中就要求实现参数为int的构造函数
	int c;
	cout << "请输入a,c:" << endl;
	cin >> a >> c;
	cout << "c = " << Bigint(c) << endl;
	cout << "a + c = " << a + c << endl;
	cout << "a - c = " << a - c << endl;
}



