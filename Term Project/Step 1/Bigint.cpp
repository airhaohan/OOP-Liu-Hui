#include <vector>
#include <iostream>
#include <algorithm>
#include "Bigint.h"

using std::vector;		using std::abs;
using std::cout;		using std::endl;

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

void Bigint::output () {
	if (bigint[0]) 
		cout << "-";
	for (size_type i = bigint.size() - 1; i > 0; --i) {
		cout << bigint[i];
	}
}
