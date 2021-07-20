#include <iostream>

using std::cin;			using std::cout;
using std::endl;		using std::string;

int main () {
	//输出正方形
	cout << "请输入正方形的边长：";
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
	
	//输出长方形 
	cout << "请输入长方形的长和宽：";
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
	
	//输出三角形
	cout << "请输入三角形的底边长（奇数）：";
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
