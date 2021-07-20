#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

//������һ��ȡģ���������Ƿ����������Ҳ�֪����ô������������
//���磺-11ģ3������ 1; -11ģ-3������ 1 
int mod (int num, int base) {
	if (num % base >= 0)
		return num % base;
	else { //num < 0
		if (base > 0)
			return base + num % base;
		else //base < 0
			return -base + num % base;
	}
}

//����ת������ 
void convert (int num, int base) {
	//��vector<int>����ÿһλ���֣�vector�ĵ�0λ���Ǹ�λ 
	vector<int> n;
	vector<char> s = {'A', 'B', 'C', 'D', 'E', 'F'};
	while (num != 0) {
		//ģ��̳����Ĺ��� 
		n.push_back(mod(num, base));
		num = ( num - mod(num, base) ) / base;
	}
	for (vector<int>::size_type i = n.size() - 1; i != -1; --i) {
		if (n[i] < 10)
			cout << n[i];
		else
			cout << s[n[i] - 10];
	}
}

int main () {
	cout << "Enter a decimal integer([2^31, 2^31 - 1]) and a base number([-16, -2]):" << endl;
	int num, base;
	cin >> num >> base;
	cout << num << "=";
	convert(num, base);
	cout << "(base" << base << ")";
	return 0;
}
