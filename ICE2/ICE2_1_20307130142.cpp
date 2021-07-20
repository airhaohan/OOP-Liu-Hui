#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

//两个vector表示的十进制数的加法函数 
vector<int> add (vector<int> n, vector<int> m) {
	//保证n的位数大于等于m的位数 
	if (n.size() < m.size()) {
		vector<int> temp = n;
		n = m;
		m = temp;
		temp.clear();		
	}
	for (vector<int>::size_type i = 0; i != m.size(); i++) {
		n[i] += m[i];
	}
	
	//进位 
	for (vector<int>::size_type i = 0; i != n.size() - 1; ++i) {
		if (n[i] > 9) {
			n[i] %= 10;
			n[i + 1]++;
		}
	}
	if (n[n.size() - 1] > 9) {
		n[n.size() - 1] %= 10;
		n.push_back(1);
	}
	m.clear();
	return n;
}

//vector表示的十进制数乘以一位数或者乘以十的乘法函数 
vector<int> multiply_unit (vector<int> vec, int n) {
	for (vector<int>::size_type i = 0; i != vec.size(); ++i) {
		vec[i] *= n;
	}
	
	//进位 
	for (vector<int>::size_type i = 0; i != vec.size() - 1; ++i) {
		if (vec[i] > 9) {
			vec[i + 1] += vec[i] / 10;
			vec[i] %= 10;
		}
	}
	if (vec[vec.size() - 1] > 9) {
		vec.push_back(vec[vec.size() - 1] / 10);
		vec[vec.size() - 2] %= 10;
	}
	return vec;
}

//vector表示十进制数乘以不超过两位数的数 
vector<int> multiply_double (vector<int>& vec, int n) {
	if (n < 10)
	//如果n是一位数，直接返回乘以一位数的结果 
		return multiply_unit(vec, n);
	else
	//如果n是两位数，则用个位乘以vec加上十位乘以vec再乘以十,模拟竖式计算乘法
		return add (multiply_unit(vec, n % 10), multiply_unit(multiply_unit(vec, n / 10), 10));
}

vector<int> factorial (int n) {
	//temp储存1到n的阶乘，ret储存1到n的阶乘的和 
	vector<int> ret, temp;
	ret.push_back(1);
	temp.push_back(1);
	for (int i = 1; i != n; i++) {
		temp = multiply_double(temp, i + 1);
		ret = add(temp, ret);
	}
	temp.clear();
	return ret;
}

int main () {
	cout << "Enter n(1<=n<=50)：" ;
	int n;
	cin >> n;
	cout << "1!";
	for (int i = 1; i != n; ++i) {
		cout << "+" << i + 1 << "!";
	}
	cout << "=";
	//使用vector来储存过长的十进制数据，vector第0位代表个位 
	vector<int> fac = factorial(n);
	for (vector<int>::size_type i = fac.size() - 1; i != -1; --i) {
		cout << fac[i];
	}
}
