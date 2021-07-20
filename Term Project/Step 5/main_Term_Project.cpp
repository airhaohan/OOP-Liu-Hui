#include <iostream>
#include "Bigint.h" //FIXME:如果头文件名不一样，将bigint.h替换为你的头文件名

using std::cin; using std::cout; using std::endl;
int main()
{
	Bigint a, b; //FIXME:如果类名不一样，将BigInt替换为你的类名
	int c;
	cout << "请输入大整数a,b和int类型c(a,b,c之间用空格隔开)" << endl;
	cin >> a >> b >> c;
	//step1
	cout << "大整数a的位数为" << a.size() << endl;
	Bigint c_BI(c); //FIXME:如果类名不一样，将BigInt替换为你的类名
	cout << "用c构造大整数，结果为" << c_BI << endl;
	//step2
	if (a < b)
		cout << "a < b" << endl;
	if (a <= b)
		cout << "a <= b" << endl;
	if (a > b)
		cout << "a > b" << endl;
	if (a >= b)
		cout << "a >= b" << endl;
	if (a == b)
		cout << "a == b" << endl;
	if (a != b)
		cout << "a != b" << endl;
	//step3
	cout << "-b=" << -b << endl; //注意这一步不应该改变b本身的值，而只是返回一个对b取负后的临时对象
	cout << "b的绝对值为" << absv(b) << endl;
	//step4
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	//step5
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a % b = " << a % b << endl;
}


