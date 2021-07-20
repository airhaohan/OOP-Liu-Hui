#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main () {
	cout << "Enter 3 English words: ";
	string s1, s2, s3, st;
	cin >> s1 >> s2 >> s3;
	if (s1 > s2) {
		st = s1;
		s1 = s2;
		s2 = st;
	}
	if (s1 > s3) {
		st = s1;
		s1 = s3;
		s3 = st;
	}
	if (s2 > s3) {
		st = s2;
		s2 = s3;
		s3 = st;
	}
	cout << s1 << " " << s2 << " " << s3 << endl;
	return 0;
}
