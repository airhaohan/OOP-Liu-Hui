#include <iostream>
#include "Bigint.h"

using std::cin;			using std::cout;
using std::endl;

int main()
{
	Bigint a, b; 
	
	//��֤������֮�������
	cout << "������a,b:" << endl;
	cin >> a >> b;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	// ��֤�������������Ļ�����㣬ע��step1�о�Ҫ��ʵ�ֲ���Ϊint�Ĺ��캯��
	int c;
	cout << "������a,c:" << endl;
	cin >> a >> c;
	cout << "c = " << Bigint(c) << endl;
	cout << "a + c = " << a + c << endl;
	cout << "a - c = " << a - c << endl;
}



