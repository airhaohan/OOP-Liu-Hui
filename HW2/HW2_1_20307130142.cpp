#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cin;			using std::cout;
using std::max;			using std::endl;
using std::vector;		using std::string;
using std::istream;		using std::domain_error;

//���������ж�ȡӢ�ĵ��ʵĺ���������ֵΪ��ĵ��ʵĳ��� 
vector<string>::size_type read_word (istream& is, vector<string>& words) {
	string record;
	string::size_type maxlen = 0;
	while (is >> record) {
		maxlen = max (maxlen, record.size());
		words.push_back(record);
	}
	//��û�ж����κε���ʱ�׳��쳣 
	if (!words.size())
		throw domain_error("δ�����κε��ʣ������ԣ�"); 
	return maxlen;
}

//����ͳ��ÿ�����ʳ����˶��ٴεĺ���
int counter (const vector<string>& words, vector<string>::size_type i) {
	int ret = 0;
	while (i + ret < words.size() && words[i + ret] == words[i]) {
		++ret;
	}
	return ret;
}

int main () {
	vector<string> words;
	string record;
	cout << "����������Ӣ�ĵ��ʣ�" << endl;
	try {
		string::size_type maxlen = read_word (cin, words);
		//�����Ժ������ͳ��ÿ�����ʳ��ֵĴ��� 
		sort(words.begin(), words.end());
		cout << "����������" << words.size() << endl;
		cout << "ÿ�����ʵĳ��ִ�����" << endl;
		for (vector<string>::size_type i = 0; i != words.size(); ) {
				int count = counter(words, i);
				//�ڵ���ĩβ�����Ӧ�����Ŀո�ʹ������� 
				cout << words[i] << string (maxlen + 1 - words[i].size(), ' ') << count << endl;
				i += count;
		}
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}
