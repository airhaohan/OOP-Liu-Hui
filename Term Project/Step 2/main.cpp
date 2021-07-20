#include <ostream>
#include <istream>
#include <stdexcept>
#include <iostream>
#include "Bigint.h"

using std::cin;			using std::cout;
using std::endl;		using std::istream;
using std::ostream;		using std::domain_error;

int main () {
	
	cout << "�������������" << endl; 
	Bigint b1, b2;
	cout << "������������������";
	try {
		cin >> b1 >> b2;
	}
	catch (domain_error e) {
		cout << e.what();
		return 0;
	}
	
	cout << "�������������" << endl; 
	cout << "��һ��������Ϊ��" << b1 << endl;
	cout << "��һ��������Ϊ��" << b2 << endl;
	
	cout << "���Դ�������Ĺ�ϵ�����" << endl; 
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
		
	cout << "���Դ�������int��Ĺ�ϵ�����" << endl;
	cout << "������һ��int������(�������һ�������Ƚϴ�С)��";
	int temp;
	cin >> temp; 
	if (b1 == temp)
		cout << b1 << " == " << temp << endl;
	if (b1 != temp)
		cout << b1 << " != " << temp << endl;
	cout << "���Թ���ÿһλ��Ϊ v �� n λ������" << endl;
	int n, v;
	cout << "������ n �� v (0 <= v <= 9)" << endl;
	cin >> n >> v;
	Bigint b3(n, v);
	cout << b3 << endl;
	return 0;
}
