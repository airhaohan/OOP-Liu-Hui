#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cin;				using std::cout;
using std::endl;			using std::domain_error;

int main () {
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟：" << endl;
	Queue QueueOfDine;
	for (int timer = 0, count = 0; !QueueOfDine.full(); ++timer) {
		if (timer % 8 == 0) {
			++count;
			QueueOfDine.push_back(count, timer);
			cout << timer << "s: 第" << count << "人进队." << endl;
		}
		if (timer % 25 == 0 && timer) {
			try {
				cout << "\t\t" << timer << "s: 第" << QueueOfDine.front()->val << "人出队." << endl;
				QueueOfDine.front_pop();
			}
			catch (domain_error e) {
				cout << e.what() << endl;
			}
		}
	}
	cout << "\t\t该窗口排队人数已达到50人！请分流！" << endl; 
	cout << "\t队首人员于" << QueueOfDine.front()->timer << "s入队" << endl; 
	cout << "\t队尾人员于" << QueueOfDine.back()->timer << "s入队" << endl; 
	cout << endl << "下面测试 output 函数" << endl;
	QueueOfDine.output(); 
	return 0;
}
