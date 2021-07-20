#include <list>
#include <string>
#include <iomanip>
#include <istream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::max;
using std::cout;			using std::endl;
using std::list;			using std::string;
using std::streamsize;
using std::domain_error;	using std::setprecision;

int main () {
	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	//����ѧ���ɼ� 
	while (read(cin, record)) {
		//��¼����ֵĳ��ȣ�����֮������������ 
		maxlen = max (maxlen, record.name.size());
		students.push_back(record);
	}
	for (list<Student_info>::iterator it = students.begin(); it != students.end(); ++it) {
		try {
			it->total = grade(*it);		
		}
		//���û����ƽʱ��ҵ�Ļ�������������Ϊ 0 
		catch (domain_error) {
			it->total = 0;	
		}
	}
	
	//��ѧ�����ಢ���� 
	list<Student_info> fail = extract_fails (students);
	fail.sort(compare);
	students.sort(compare);
	
	//�������
	cout << "passing student records:" << endl;
	for (list<Student_info>::iterator it = students.begin(); it != students.end(); it++) {
		cout << it->name << string (maxlen + 1 - it->name.size(), ' ');
		try {
			streamsize prec = cout.precision();
			double final_grade = grade(*it);
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	cout << "failing student records:" << endl;
	for (list<Student_info>::iterator it = fail.begin(); it != fail.end(); it++) {
		cout << it->name << string (maxlen + 1 - it->name.size(), ' ');
		try {
			streamsize prec = cout.precision();
			double final_grade = grade(*it);
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
