#ifndef GUARD_Date_h
#define GUARD_Date_h

#include <istream>

int const mon_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//月份 -天数对应表  

class Date {
	public:
		//constructor
		Date ();
		Date (int, int, int);
		Date (std::istream&);
		Date (const Date&);		//用一个Date去初始化另一个Date的构造函数 
		
		//accessor function
		int year () const { return y; };
		int month () const { return m; };
		int day () const { return d; };
		
		void valid () const ;						//有效日期判断 
		std::istream& read_date (std::istream&);	//输入日期 
		void output () const;						//输出日期 
		bool Isleapyear () const;					//闰年判断 
		Date next_day() const; 						//增加一天 
		Date next_month() const; 					//增加一月 
		Date next_year() const; 					//增加一年 
	private:
		int y, m, d;
};

int days_span (const Date&, const Date&);			//求两个日期相隔的天数 
bool date_compare (const Date&, const Date&);		//比较两个日期的先后  

#endif
#pragma once
