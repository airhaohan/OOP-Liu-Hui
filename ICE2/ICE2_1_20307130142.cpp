#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

//����vector��ʾ��ʮ�������ļӷ����� 
vector<int> add (vector<int> n, vector<int> m) {
	//��֤n��λ�����ڵ���m��λ�� 
	if (n.size() < m.size()) {
		vector<int> temp = n;
		n = m;
		m = temp;
		temp.clear();		
	}
	for (vector<int>::size_type i = 0; i != m.size(); i++) {
		n[i] += m[i];
	}
	
	//��λ 
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

//vector��ʾ��ʮ����������һλ�����߳���ʮ�ĳ˷����� 
vector<int> multiply_unit (vector<int> vec, int n) {
	for (vector<int>::size_type i = 0; i != vec.size(); ++i) {
		vec[i] *= n;
	}
	
	//��λ 
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

//vector��ʾʮ���������Բ�������λ������ 
vector<int> multiply_double (vector<int>& vec, int n) {
	if (n < 10)
	//���n��һλ����ֱ�ӷ��س���һλ���Ľ�� 
		return multiply_unit(vec, n);
	else
	//���n����λ�������ø�λ����vec����ʮλ����vec�ٳ���ʮ,ģ����ʽ����˷�
		return add (multiply_unit(vec, n % 10), multiply_unit(multiply_unit(vec, n / 10), 10));
}

vector<int> factorial (int n) {
	//temp����1��n�Ľ׳ˣ�ret����1��n�Ľ׳˵ĺ� 
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
	cout << "Enter n(1<=n<=50)��" ;
	int n;
	cin >> n;
	cout << "1!";
	for (int i = 1; i != n; ++i) {
		cout << "+" << i + 1 << "!";
	}
	cout << "=";
	//ʹ��vector�����������ʮ�������ݣ�vector��0λ�����λ 
	vector<int> fac = factorial(n);
	for (vector<int>::size_type i = fac.size() - 1; i != -1; --i) {
		cout << fac[i];
	}
}
