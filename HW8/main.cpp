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
	cout << "请输入三角形的三条边长：";
	try {
		cin >> t;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "三角形的周长为："; 
	try {
		cout << t.circumference();
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << ", 面积为：";
	try {
		cout << t.area() << endl;
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
	
	//Rectangle
	cout << "请输入矩形的长和宽：";
	try {
		cin >> r;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "矩形的周长为：" << r.circumference() << ", 面积为：" << r.area() << endl;
	
	//Circle 
	cout << "请输入圆的半径：";
	try {
		cin >> c;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	cout << "圆的周长为：" << c.circumference() << ", 面积为：" << c.area() << endl;

	return 0;	 
}
