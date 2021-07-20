#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Bigint.h"

using std::cout;			using std::cin;
using std::endl;			using std::domain_error;			

int main () {
	try {
		cout << "���Թ��캯����size()�������������" << endl; 
		int a = 0, b = 1234, c = INT_MIN, d = INT_MAX;  
		Bigint num1(a), num2(b), num3(c), num4(d), num5;
		cout << "num1 is ";
		num1.output();
		cout << endl << "the size of num1 is " << num1.size() << endl;
		cout << "num2 is ";
		num2.output();
		cout << endl << "the size of num2 is " << num2.size() << endl;
		cout << "num3 is ";
		num3.output();
		cout << endl << "the size of num3 is " << num3.size() << endl;
		cout << "num4 is ";
		num4.output();
		cout << endl << "the size of num4 is " << num4.size() << endl;
		cout << "num5 is ";
		num5.output();
		cout << endl << "the size of num5 is " << num5.size() << endl;
		
		cout << "���Թ���ÿһλ��Ϊ v �� n λ������" << endl;
		int n, v;
		cout << "������ n �� v (0 <= v <= 9)" << endl;
		cin >> n >> v;
		Bigint b3(n, v);
		cout << b3 << endl;
		
		cout << endl <<"�������������" << endl; 
		Bigint b1, b2;
		cout << "������������������" << endl;
		cin >> b1 >> b2;
		
		cout << endl << "�������������" << endl; 
		cout << "b1Ϊ��" << b1 << endl;
		cout << "b2Ϊ��" << b2 << endl;
		
		cout << endl << "���Դ����������صĹ�ϵ�����" << endl; 
		if (b1 > b2)
			cout << b1 << " > "  << b2 << endl; 
		if (b1 >= b2)
			cout << b1 << " >= " << b2 << endl; 
		if (b1 < b2)
			cout << b1 << " < "  << b2 << endl; 
		if (b1 <= b2)
			cout << b1 << " <= " << b2 << endl; 
		if (b1 == b2)
			cout << b1 << " == " << b2 << endl; 
		if (b1 != b2)
			cout << b1 << " != " << b2 << endl;
			
		cout << endl << "���Ծ���ֵ������ȡ��������" << endl; 
		cout << "b1�ľ���ֵΪ��" << absv(b1) << endl;
		cout << "b1���෴��Ϊ��" << -b1 << endl;
		
		cout << endl << "���Դ����������ص������" << endl;
		cout <<  "b1 + b2 = " << b1 + b2 << endl;
		cout <<  "b1 - b2 = " << b1 - b2 << endl;
		cout <<  "b1 * b2 = " << b1 * b2 << endl;
		cout <<  "b1 / b2 = " << b1 / b2 << endl;
		cout <<  "b1 % b2 = " << b1 % b2 << endl;
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}
