#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main () {
	cout << "输入始发站上车人数，车站数，终点站下车人数和所求的站点编号：";
	int a, n, m, x, f1, f2, sum, count;
	cin >> a >> n >> m >> x; /*先不做判断了叭，默认n>3, 3< x < n*/
	/*f1代表上一站上车人数， f2代表上上一站上车人数*/
	f1 = count = 0;
	/*先暴力枚举求出第二站上/下车人数*/ 
	while (1) {
		sum = f2 = a; 
		for (int i = 2; i != n - 1; ++i) {	/*i表示驶出第几站后*/
			sum += f2;
			f1 += f2;
			f2 = f1 - f2;
		}
		if (sum == m)
			break;
		else
			f1 = ++count;
	}
	
	sum = f2 = a; f1 = count;
	for (int i = 2; i != x; ++i) {
		sum += f2;
		f1 += f2;
		f2 = f1 - f2;
	}
	cout << "第" << x << "站开出时车上的人数为" << sum << endl; 
}
