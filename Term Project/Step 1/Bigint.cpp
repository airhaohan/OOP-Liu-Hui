#include <vector>
#include <iostream>
#include <algorithm>
#include "Bigint.h"

using std::vector;		using std::abs;
using std::cout;		using std::endl;

//默认构造函数为零 
Bigint::Bigint() {
	bigint.push_back(0);
	bigint.push_back(0);
}

Bigint::Bigint(int num) {
	//最小的int需要另外考虑，因为INT_MIN的相反数无法用int表示出来 
	bool flag = false;
	if (num == INT_MIN) {
		flag = true;
		num += 1;
	}
	
	bigint.push_back(num >= 0 ? 0 : 1);
	num = abs(num); //fabs会返回double,所以用abs 
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
