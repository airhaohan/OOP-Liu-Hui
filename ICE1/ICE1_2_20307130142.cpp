#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main () {
	cout << "����ʼ��վ�ϳ���������վ�����յ�վ�³������������վ���ţ�";
	int a, n, m, x, f1, f2, sum, count;
	cin >> a >> n >> m >> x; /*�Ȳ����ж��˰ȣ�Ĭ��n>3, 3< x < n*/
	/*f1������һվ�ϳ������� f2��������һվ�ϳ�����*/
	f1 = count = 0;
	/*�ȱ���ö������ڶ�վ��/�³�����*/ 
	while (1) {
		sum = f2 = a; 
		for (int i = 2; i != n - 1; ++i) {	/*i��ʾʻ���ڼ�վ��*/
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
	cout << "��" << x << "վ����ʱ���ϵ�����Ϊ" << sum << endl; 
}
