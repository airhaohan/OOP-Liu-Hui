#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cin;			using std::cout;
using std::max;			using std::endl;
using std::vector;		using std::string;
using std::istream;		using std::domain_error;

//从输入流中读取英文单词的函数，返回值为最长的单词的长度 
vector<string>::size_type read_word (istream& is, vector<string>& words) {
	string record;
	string::size_type maxlen = 0;
	while (is >> record) {
		maxlen = max (maxlen, record.size());
		words.push_back(record);
	}
	//当没有读入任何单词时抛出异常 
	if (!words.size())
		throw domain_error("未输入任何单词，请重试！"); 
	return maxlen;
}

//用来统计每个单词出现了多少次的函数
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
	cout << "请输入若干英文单词：" << endl;
	try {
		string::size_type maxlen = read_word (cin, words);
		//排序以后更方便统计每个单词出现的次数 
		sort(words.begin(), words.end());
		cout << "单词总数：" << words.size() << endl;
		cout << "每个单词的出现次数：" << endl;
		for (vector<string>::size_type i = 0; i != words.size(); ) {
				int count = counter(words, i);
				//在单词末尾添加相应数量的空格使输出对齐 
				cout << words[i] << string (maxlen + 1 - words[i].size(), ' ') << count << endl;
				i += count;
		}
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}
