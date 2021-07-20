#include <iostream>
#include <stdexcept>
#include "Date.h"
//#include "Date.cpp"

using std::cin;			using std::cout;
using std::endl;		using std::logic_error;

int main () {
	//������������ 
	cout << "��������������(�����գ��Կո�ָ�):" << endl;
	Date d1, d2; 
	try {
		d1.read_date(cin);
		d1.valid();
	}
	catch (logic_error e) {
		cout << e.what() << endl;
		return 0;
	}
	try {
		d2.read_date(cin);
		d2.valid();
	}
	catch (logic_error e) {
		cout << e.what() << endl;
		return 0;
	}
	//��� 
	cout << "����һ��" ;	d1.output();	cout << endl;
	cout << "���ڶ���" ;	d2.output();	cout << endl;
	cout << "���������������Ϊ��" << days_span(d1, d2) << endl;
	cout << "������һ����һ��Ϊ��"; d1.next_day().output(); cout << endl; 
	cout << "������һ����һ��Ϊ��"; d1.next_month().output(); cout << endl; 
	cout << "������һ����һ��Ϊ��"; d1.next_year().output(); cout << endl;
	return 0;
}
