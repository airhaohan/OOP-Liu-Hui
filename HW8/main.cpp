#include <iostream>
#include <stdexcept>
#include "Shape.h"

using std::cin;			using std::cout;
using std::endl;		using std::domain_error;

int main () {
	Triangle t;
	Rectangle r;
	Circle c;
	
	//Triangle
	cout << "�����������ε������߳���";
	try {
		cin >> t;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "�����ε��ܳ�Ϊ��"; 
	try {
		cout << t.circumference();
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << ", ���Ϊ��";
	try {
		cout << t.area() << endl;
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
	
	//Rectangle
	cout << "��������εĳ��Ϳ�";
	try {
		cin >> r;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "���ε��ܳ�Ϊ��" << r.circumference() << ", ���Ϊ��" << r.area() << endl;
	
	//Circle 
	cout << "������Բ�İ뾶��";
	try {
		cin >> c;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "Բ���ܳ�Ϊ��" << c.circumference() << ", ���Ϊ��" << c.area() << endl;

	return 0;	 
}
