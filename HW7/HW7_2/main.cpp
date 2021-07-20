#include <iostream>
#include "Str.h" 

using std::cin;			using std::cout;
using std::endl;		

int main() {
	cout << "Please enter your first name: ";
	Str name;
	cin >> name;
	const Str greeting = "Hello, " + name + "!";
	cout << "Please enter the number of blanks surrounding the greeting: ";
	int pad;
	cin >> pad;
	const int rows = pad * 2 + 3;
	const Str::size_type cols = greeting.size() + pad * 2 + 2;
	cout << endl;
	for (int r = 0; r != rows; ++r) {
		Str::size_type c = 0;
		while (c != cols) {
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
	cout << "逐个字符输出greeting(字符之间以空格分隔):" << endl;
	for (Str::size_type i = 0; i != greeting.size(); ++i) {
		cout << greeting[i] << " ";
	}
	return 0;
}
