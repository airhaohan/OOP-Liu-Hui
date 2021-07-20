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

//判断是否为闰年
bool Date::Isleapyear () const {
	if (y % 4 == 0 && y % 100 || y % 400 == 0)
		return true;
	else
		return false;
} 

//判断是否为有效日期 
void Date::valid () const {
	if (y <= 0)
		throw logic_error("invalid year");
	if (m <= 0 || m > 12)
		throw logic_error("invalid month");
	if (d <= 0 || Isleapyear() ? (m == 2 && d > 29) : (m == 2 && d > 28) || m != 2 && d > mon_day[m - 1])
		throw logic_error("invalid day");	
	return;
}

//输入日期 
istream& Date::read_date (istream& is) {
		is >> y >> m >> d;
		is.clear();
	return is;
}

//输出日期 
void Date::output () const {
		cout << y << "年" << m << "月" << d << "日";
}
//增加一天 
Date Date::next_day() const {
	int yyyy = y, mm = m, dd = d;
	//闰年的二月分开讨论  
	if ((y % 4 == 0 && y % 100 || y % 400 == 0) && mm == 2) {
		dd = dd % 29 + 1;
		if (dd == 1)
			mm++;		//如果跨月，月份加一
	}
	else {
		dd = dd % mon_day[mm - 1] + 1;
		mm = dd == 1 ? mm % 12 + 1 : mm;				//如果跨月，月份加一 
		yyyy = dd == 1 && mm == 1 ? yyyy + 1 : yyyy;	//如果跨年，年份加一 
	}
	Date ret(yyyy, mm, dd);
	return ret;
}

//增加一月 
Date Date::next_month() const {
	int yyyy = m == 12 ? y + 1 : y, mm = m % 12 + 1, dd = min (d, mon_day[mm - 1]);
	if ((y % 4 == 0 && y % 100 || y % 400 == 0) && mm == 2 && d > 28)	//闰年的二月分开讨论  
		dd++;
	Date ret(yyyy, mm, dd);
	return ret;
}

//增加一年  
Date Date::next_year() const {
	int yyyy = y + 1, mm = m, dd = d;
	//闰年的下一年肯定不是闰年 
	if (mm == 2 && dd == 29)
		dd--;
	Date ret(yyyy, mm, dd);
	return ret;
}


//两个日期比大小，d1在d2之前为真 
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

//求两个日期相差的天数 
int days_span (const Date& date1, const Date& date2) {
	//保证他们不在同一个月份 
	if (date1.year() == date2.year() && date1.month() == date2.month())
		return abs(date1.day() - date2.day());
	int ret = 0;
	//保证d1在d2之前 
	Date d1(date_compare (date1, date2) ? date1 : date2);
	Date d2(date_compare (date1, date2) ? date2 : date1);
	//i是年份，j是月份
	for (int i = d1.year(); i <= d2.year(); i++) {
		for (int j = (i == d1.year() ? d1.month() : 1); i == d2.year() ? j != d2.month() : j != 13; j++) {
			ret += mon_day[j - 1];
			//如果是闰年，要加一天 
			if ((i % 4 == 0 && i % 100 || i % 400 == 0) && j == 2)
				ret++;
		}
	}
	ret += d2.day() - d1.day();
	return ret;
}

