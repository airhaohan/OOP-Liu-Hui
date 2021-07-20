#include <ctime>
#include <cstdlib>
#include <iostream>
#include "my_function.h"

using std::cin;				using std::cout;
using std::vector;			using std::endl;
using std::string;

int main () {
	srand(time(NULL));
	
	//生成随机的vector<int>
	vector<int> vec1;
	for (int i = 0; i != 10; ++i)
		vec1.push_back(rand() % 100 + 1);
	cout << "the integer list:" << endl;
	output(vec1.begin(), vec1.end());
	cout << "the sum of the integer list: " << accumulate(vec1.begin(), vec1.end(), 0) << endl;
	cout << "the max element in the integer list: " << *( max_element(vec1.begin(), vec1.end()) ) << endl;
	cout << "the min element in the integer list: " << *( min_element(vec1.begin(), vec1.end()) ) << endl;
	cout << endl;

	//生成随机的vector<double>
	vector<double> vec2;
	for (int i = 0; i != 10; ++i)
		vec2.push_back((double)rand() / RAND_MAX);
	cout << "the double list:" << endl;
	output(vec2.begin(), vec2.end());
	cout << "the sum of the double list: " << accumulate(vec2.begin(), vec2.end(), 0.0) << endl;
	cout << "the max element in the double list: " << *( max_element(vec2.begin(), vec2.end()) ) << endl;
	cout << "the min element in the double list: " << *( min_element(vec2.begin(), vec2.end()) ) << endl;
	cout << endl;
	
	//生成随机的vector<string>
	vector<string> vec3;
	for (int i = 0; i != 10; i++) {
		//limit表示字符串的随机长度
		int limit = rand() % 6 + 1;
		string record;
		for (int j = 0; j != limit; j++) {
			record.push_back(rand() % 26 + 'a');
		}
		vec3.push_back(record);
	}
	cout << "the string list:" << endl;
	output(vec3.begin(), vec3.end());
	string s = "";
	cout << "the concatenation of the string list: " << accumulate(vec3.begin(), vec3.end(), s) << endl;
	cout << "the max string in the string list: " << *( max_element(vec3.begin(), vec3.end()) ) << endl;
	cout << "the min string in the string list: " << *( min_element(vec3.begin(), vec3.end()) ) << endl;
}
