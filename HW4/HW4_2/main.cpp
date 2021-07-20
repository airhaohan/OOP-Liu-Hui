#include <iostream>
#include <stdexcept>
#include "Date.h"
//#include "Date.cpp"

using std::cin;			using std::cout;
using std::endl;		using std::logic_error;

int main () {
	//输入两个日期 
	cout << "请输入两个日期(年月日，以空格分隔):" << endl;
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
	//输出 
	cout << "日期一：" ;	d1.output();	cout << endl;
	cout << "日期二：" ;	d2.output();	cout << endl;
	cout << "两个日期相隔天数为：" << days_span(d1, d2) << endl;
	cout << "给日期一增加一天为："; d1.next_day().output(); cout << endl; 
	cout << "给日期一增加一月为："; d1.next_month().output(); cout << endl; 
	cout << "给日期一增加一年为："; d1.next_year().output(); cout << endl;
	return 0;
}
