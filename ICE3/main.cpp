#include <list>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "selectsort.h"

using std::cin;				using std::cout;
using std::endl;			using std::max;
using std::string;			using std::vector;
using std::list;

int main() {
	srand(time(NULL));
	int num = rand() % 10 + 10;
	//生成随机的vector<int>
	vector<int> vec_i;
	for (int i = 0; i != num; i++) {
		vec_i.push_back(rand() % 100);
	}
	//生成随机的list<double>
	list<double> lt_d;
	for (int i = 0; i != num; i++) {
		lt_d.push_back((double)rand() / (RAND_MAX / 2000));	
	}
	//生成随机的list<char>
	list<char> lt_c;
	for (int i = 0; i != num; i++) {
		lt_c.push_back(rand() % 26 + 'A');
	}
	//排序前输出 
	cout << num << " random data:" << endl << "random int vector:";
	for (vector<int>::size_type i = 0; i != vec_i.size(); i++) {
		cout << " " << vec_i[i];
	}
	cout << endl << "random double list:";
	for (list<double>::iterator it = lt_d.begin(); it != lt_d.end(); it++) {
		cout << " " << *it;
	}
	cout << endl << "random char list:";
	for (list<char>::iterator it = lt_c.begin(); it != lt_c.end(); it++) {
		cout << " " << *it;
	}
	//排序 
	selectSort(vec_i.begin(), vec_i.end());
	selectSort(lt_d.begin(), lt_d.end());
	selectSort(lt_c.begin(), lt_c.end());
	//排序后输出 
	cout << endl << "The sorted data:" << endl << "sorted int vector:" << endl;
	for (vector<int>::size_type i = 0; i != vec_i.size(); i++) {
		cout << " " << vec_i[i];
	}
	cout << endl << "sorted double list:";
	for (list<double>::iterator it = lt_d.begin(); it != lt_d.end(); it++) {
		cout << " " << *it;
	}
	cout << endl << "sorted char list:";
	for (list<char>::iterator it = lt_c.begin(); it != lt_c.end(); it++) {
		cout << " " << *it;
	}
	return 0;
}
