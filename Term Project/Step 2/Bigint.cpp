#include <vector>
#include <cctype>
#include <ostream>
#include <istream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Bigint.h"

using std::cout;			using std::abs;
using std::endl;			using std::vector;
using std::istream;			using std::ostream;
using std::domain_error;

//Ĭ�Ϲ��캯��Ϊ�� 
Bigint::Bigint() {
	bigint.push_back(0);
	bigint.push_back(0);
}

Bigint::Bigint(int num) {
	//��С��int��Ҫ���⿼�ǣ���ΪINT_MIN���෴���޷���int��ʾ���� 
	bool flag = false;
	if (num == INT_MIN) {
		flag = true;
		num += 1;
	}

	bigint.push_back(num >= 0 ? 0 : 1);
	num = abs(num); //fabs�᷵��double,������abs 
	do {
		bigint.push_back(num % 10);
		num /= 10;
	} while (num != 0);

	if (flag)
		bigint[1] += 1;
}

void Bigint::output() {
	if (bigint[0])
		cout << "-";
	for (size_type i = bigint.size() - 1; i > 0; --i) {
		cout << bigint[i];
	}
}

bool operator== (const Bigint& b1, const Bigint& b2) {
	if (b1.size() != b2.size())
		return false;
	Bigint::size_type i = b1.size();
	while (i) {
		if (b1[i] != b2[i])
			return false;
		--i;
	}
	return true;
}

bool operator!= (const Bigint& b1, const Bigint& b2) {
	return !(b1 == b2);
}

bool operator>  (const Bigint& b1, const Bigint& b2) {
	if (b1[0] != b2[0] || b1.size() > b2.size())
		return b1[0] ? false : true;
	if (b1.size() < b2.size())
		return b1[0] ? true : false;
	if (b1 == b2)
		return false;
	//ʣ�µ������b1��b2λ����ͬ��������ͬ 
	bool flag = true;	//flagΪtrue��ʾb1����ֵ��b2�� 
	Bigint::size_type i = b1.size();
	while (i > 0) {
		if (b1[i] == b2[i])
			--i;
		else {
			if (b1[i] < b2[i]) 
				flag = false;
			break; 
		}
	}
	return b1[0] ? !flag : flag;
}

bool operator<  (const Bigint& b1, const Bigint& b2) {
	return !(b1 > b2 || b1 == b2); 
}

bool operator>= (const Bigint& b1, const Bigint& b2) {
	return !(b1 < b2);
}

bool operator<= (const Bigint& b1, const Bigint& b2) {
	return !(b1 > b2);
}

istream& operator>> (istream& is, Bigint& b) {
	b.bigint.clear();
	char c;
	vector<int> reverse;	//�ȵ�������reverse�� 
	while (is.get(c) && isspace(c));
	if (is) {
		if (c == '-') {
			b.bigint.push_back(1);
			while (is.get(c) && c == '0');	//����ǰ���� 
			do {
				reverse.push_back(c - '0');
			} while (is.get(c) && '0' <= c && '9' >= c);
		}
		else if ('0' <= c && '9' >= c) {
			b.bigint.push_back(0);
			while (c == '0' && is.get(c));	 //����is.get()Ҫ���ں��
			if ('0' <= c && '9' >= c) {
				do {
					reverse.push_back(c - '0');
				} while (is.get(c) && '0' <= c && '9' >= c);
			}
		}
		else throw domain_error("�������"); 
		if (is)
			is.unget();
	}
	if (reverse.empty()) {
		b.bigint.clear();
		b.bigint.push_back(0);
		b.bigint.push_back(0);
	}
	else
		copy (reverse.rbegin(), reverse.rend(), back_inserter(b.bigint));
	return is;
}

ostream& operator<< (ostream& os, const Bigint& b) {
	if (b[0])
		cout << "-";
	for (Bigint::size_type i = b.size(); i > 0; --i) {
		cout << b[i];
	}
	return os;
}
