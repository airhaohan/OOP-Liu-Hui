#include <cmath> 
#include <istream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Date.h"

using std::cin;		 		using std::cout;
using std::max;				using std::min;
using std::endl;			using std::istream;
using std::logic_error;

//constructor 
Date::Date (): y(0), m(0), d(0) {};

Date::Date (istream& is) {
	read_date(is);
}

Date::Date (int yyyy, int mm, int dd) {
	y = yyyy;
	m = mm;
	d = dd;
}

Date::Date (const Date& date) {
	y = date.year();
	m = date.month();
	d = date.day();
} 

//�ж��Ƿ�Ϊ����
bool Date::Isleapyear () const {
	if (y % 4 == 0 && y % 100 || y % 400 == 0)
		return true;
	else
		return false;
} 

//�ж��Ƿ�Ϊ��Ч���� 
void Date::valid () const {
	if (y <= 0)
		throw logic_error("invalid year");
	if (m <= 0 || m > 12)
		throw logic_error("invalid month");
	if (d <= 0 || Isleapyear() ? (m == 2 && d > 29) : (m == 2 && d > 28) || m != 2 && d > mon_day[m - 1])
		throw logic_error("invalid day");	
	return;
}

//�������� 
istream& Date::read_date (istream& is) {
		is >> y >> m >> d;
		is.clear();
	return is;
}

//������� 
void Date::output () const {
		cout << y << "��" << m << "��" << d << "��";
}
//����һ�� 
Date Date::next_day() const {
	int yyyy = y, mm = m, dd = d;
	//����Ķ��·ֿ�����  
	if ((y % 4 == 0 && y % 100 || y % 400 == 0) && mm == 2) {
		dd = dd % 29 + 1;
		if (dd == 1)
			mm++;		//������£��·ݼ�һ
	}
	else {
		dd = dd % mon_day[mm - 1] + 1;
		mm = dd == 1 ? mm % 12 + 1 : mm;				//������£��·ݼ�һ 
		yyyy = dd == 1 && mm == 1 ? yyyy + 1 : yyyy;	//������꣬��ݼ�һ 
	}
	Date ret(yyyy, mm, dd);
	return ret;
}

//����һ�� 
Date Date::next_month() const {
	int yyyy = m == 12 ? y + 1 : y, mm = m % 12 + 1, dd = min (d, mon_day[mm - 1]);
	if ((y % 4 == 0 && y % 100 || y % 400 == 0) && mm == 2 && d > 28)	//����Ķ��·ֿ�����  
		dd++;
	Date ret(yyyy, mm, dd);
	return ret;
}

//����һ��  
Date Date::next_year() const {
	int yyyy = y + 1, mm = m, dd = d;
	//�������һ��϶��������� 
	if (mm == 2 && dd == 29)
		dd--;
	Date ret(yyyy, mm, dd);
	return ret;
}


//�������ڱȴ�С��d1��d2֮ǰΪ�� 
bool date_compare (const Date& d1, const Date& d2) {
	if (d1.year() < d2.year())
		return true;
	if (d1.year() > d2.year())
		return false;
	//d1.year() == d2.year()
	if (d1.month() < d2.month())
		return true;
	if (d1.month() > d2.month())
		return false;
	//d1.month() == d2.month()
	if (d1.day() < d2.day())
		return true;
	return false;
} 

//������������������ 
int days_span (const Date& date1, const Date& date2) {
	//��֤���ǲ���ͬһ���·� 
	if (date1.year() == date2.year() && date1.month() == date2.month())
		return abs(date1.day() - date2.day());
	int ret = 0;
	//��֤d1��d2֮ǰ 
	Date d1(date_compare (date1, date2) ? date1 : date2);
	Date d2(date_compare (date1, date2) ? date2 : date1);
	//i����ݣ�j���·�
	for (int i = d1.year(); i <= d2.year(); i++) {
		for (int j = (i == d1.year() ? d1.month() : 1); i == d2.year() ? j != d2.month() : j != 13; j++) {
			ret += mon_day[j - 1];
			//��������꣬Ҫ��һ�� 
			if ((i % 4 == 0 && i % 100 || i % 400 == 0) && j == 2)
				ret++;
		}
	}
	ret += d2.day() - d1.day();
	return ret;
}

