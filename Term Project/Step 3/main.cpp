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
	cout << "������һ����������";
	try {
		cin >> b1;
	}
	catch (domain_error e) {
		cout << e.what();
		return 0;
	}
	
	cout << "���������Ϊ��" << b1 << endl;
	cout << "���Ծ���ֵ����" << endl; 
	cout << "����������ľ���ֵΪ��" << absv(b1) << endl;
	cout << "����ȡ��������" << endl; 
	cout << "������������෴��Ϊ��" << -b1 << endl;
	
	return 0;
}
