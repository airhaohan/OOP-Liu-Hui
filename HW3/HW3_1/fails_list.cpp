#include <list>
#include "Student_info.h"

bool fgrade (Student_info& s) {
	return s.total < 60;
}

//��ѧ�����ɼ�����������ĺ���
std::list<Student_info> extract_fails (std::list<Student_info>& pass) {
	std::list<Student_info> fail;
	std::list<Student_info>::iterator it = pass.begin();
	while (it != pass.end()) {
		if (fgrade (*it)) {
			fail.push_back(*it);
			it = pass.erase(it);
		}
		else
			it++;
	}
	return fail;
}
