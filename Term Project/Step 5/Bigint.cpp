#include <cmath>
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
			bool flag = false;
			while (is.get(c) && c == '0') {	//����ǰ����
				if (c == '0')
					flag = true;
			}
			if ('0' <= c && '9' >= c) {
				do {
					reverse.push_back(c - '0');
				} while (is.get(c) && '0' <= c && '9' >= c);
			}
			else if ((isspace(c) || c == '-') && flag) {
				b.bigint[0] = 0;
				b.bigint.push_back(0);
			}
			else throw domain_error("�������"); 
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

Bigint Bigint::operator-() const {
	if (*this == 0)
		return 0;
	Bigint ret = *this;
	ret[0] = !(ret[0]);
	return ret;
}

Bigint absv(const Bigint& b) {
	Bigint ret = b;
	if (b < 0)
		return -ret;
	else
		return ret;
}

Bigint operator+ (const Bigint& b1, const Bigint& b2) {
	Bigint ret;
	if (!(b1[0] ^ b2[0])) {	//�����������ͬ��, ��b1λ�����ڵ���b2
		if (b1.size() < b2.size())
			return b2 + b1;
		else {
			Bigint ret(b1);
			for (Bigint::size_type i = 1; i <= b2.size(); ++i)
				ret[i] += b2[i];
			//��λ 
			int addbit = 0;
			for (Bigint::size_type i = 1; i <= ret.size(); ++i) {
				ret[i] += addbit;
				if (ret[i] >= 10) {
					ret[i] -= 10;
					addbit = 1;
				}
				else
					addbit = 0;
			}
			if (addbit)
				ret.bigint.push_back(addbit);
			return ret;
		}
	}
	else {	//��������������,��b1����ֵ����b2
		if (absv(b1) == absv(b2)) {
			Bigint ret(0);
			return ret;
		}
		else if (absv(b1) < absv(b2))
			return b2 + b1;
		else {
			Bigint ret(b1);
			int minbit = 0;
			for (Bigint::size_type i = 1; i <= b2.size(); ++i) {
				ret[i] -= (minbit + b2[i]);
				if (ret[i] < 0) {
					ret[i] += 10;
					minbit = 1;
				}
				else
					minbit = 0;
			}
			for (Bigint::size_type i = b2.size() + 1; i <= ret.size(); ++i) {
				if (minbit) {
					if (!ret[i])
						ret[i] = 9;
					else {
						--ret[i];
						break;
					}
				}
			}
			while (!ret[ret.size()])	//ɾ��ĩβԪ���� 
				ret.bigint.pop_back();
			return ret;
		}
	}
}

Bigint operator- (const Bigint& b1, const Bigint& b2) {
	return b1 + (-b2);
}

Bigint operator* (const Bigint& b1, const Bigint& b2) {
	if (b1.size() < b2.size())
		return b2 * b1;
	//���Ը�λ�����߳���ʮ 
	if (absv(b2) <= 10) {
		if (b2 == 0) {
			return 0;
		}
		Bigint ret(b1);
		ret[0] ^= b2[0];
		if (absv(b2) == 10) {
			ret.bigint.insert(ret.bigint.begin() + 1, 0);
			return ret;
		}
		int addbit = 0, n = b2[1];
		for (Bigint::size_type i = 1; i <= ret.size(); ++i) {
			ret[i] = ret[i] * n + addbit;
			addbit = ret[i] / 10;
			ret[i] %= 10;
		}
		if (addbit)
			ret.bigint.push_back(addbit);
		return ret;
	}
	//���Զ�λ��
	Bigint ret = 0;
	ret[0] ^= b2[0];
	for (Bigint::size_type i = b2.size(); i > 0; --i) {
		ret = ret * 10;
		ret = ret + b1 * b2[i];
	}
	return ret;
}

Bigint Bigint::e(int n) const {
	Bigint ret = *this;
	while (n < 0)
	{
		if (ret.size() == 1)
			return 0;
		else
			ret.bigint.erase(ret.bigint.begin() + 1);
		++n;
	}
	for(int i = 0; i != n; ++i)
		ret.bigint.insert(ret.bigint.begin() + 1, 0);
	return ret;
}

Bigint operator/ (const Bigint& b1, const Bigint& b2) {
	if (b2 == 0)
		throw domain_error("zero denominator");
	Bigint t1 = absv(b1), t2 = absv(b2), ret = 0;
	if (t1 < t2)
		return ret;
	int diff = b1.size() - b2.size();
 	//��Ա����e(int n)�������10��n���� 
	for (t2 = t2.e(diff); diff >= 0; --diff) {
		while (t1 >= t2) {
			t1 = t1 - t2;
			ret = ret + (Bigint(1)).e(diff);
		}
		t2 = t2.e(-1);
	}
	ret[0] = b1[0] ^ b2[0];
	return ret;
}

Bigint operator% (const Bigint& b1, const Bigint& b2) {
	if (b2 == 0)
		throw domain_error("zero denominator");
	return b1 - b2 * (b1 / b2);
}
