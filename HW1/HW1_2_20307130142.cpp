#include <iostream>

using std::cin;			using std::cout;
using std::endl;		using std::string;

int main () {
	//���������
	cout << "�����������εı߳���";
	int a;
	cin >> a;
	cout << endl;
	for (int i = 0; i != a; ++i) {
		for (int j = 0; j != a; j++) {
			cout << " *";
		}
		cout << endl;
	}
	cout << endl;
	
	//��������� 
	cout << "�����볤���εĳ��Ϳ�";
	int l, w;
	cin >> l >> w;
	cout << endl;
	for (int i = 0; i != w; ++i) {
		for (int j = 0; j != l; ++j) {
			cout << " *";
		}
		cout << endl;
	}
	cout << endl;
	
	//���������
	cout << "�����������εĵױ߳�����������";
	int b;
	cin >> b;
	cout << endl;
	for (int i = 0; i != (b + 1) / 2; ++i) {
		for (int j = 0; j != b; j++) {
			if (i + j >= (b - 1) / 2 && j - i <= (b - 1) / 2)
				cout << " *";
			else
				cout << "  ";
		}
		cout << endl;
	}
	return 0;
}
