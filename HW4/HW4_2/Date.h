#ifndef GUARD_Date_h
#define GUARD_Date_h

#include <istream>

int const mon_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//�·� -������Ӧ��  

class Date {
	public:
		//constructor
		Date ();
		Date (int, int, int);
		Date (std::istream&);
		Date (const Date&);		//��һ��Dateȥ��ʼ����һ��Date�Ĺ��캯�� 
		
		//accessor function
		int year () const { return y; };
		int month () const { return m; };
		int day () const { return d; };
		
		void valid () const ;						//��Ч�����ж� 
		std::istream& read_date (std::istream&);	//�������� 
		void output () const;						//������� 
		bool Isleapyear () const;					//�����ж� 
		Date next_day() const; 						//����һ�� 
		Date next_month() const; 					//����һ�� 
		Date next_year() const; 					//����һ�� 
	private:
		int y, m, d;
};

int days_span (const Date&, const Date&);			//������������������� 
bool date_compare (const Date&, const Date&);		//�Ƚ��������ڵ��Ⱥ�  

#endif
#pragma once
