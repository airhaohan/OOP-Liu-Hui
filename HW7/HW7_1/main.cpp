#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cin;				using std::cout;
using std::endl;

int main () {
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟：" << endl;
	Queue<int> q;
	for (int timer = 0, count = 0; !q.isFull(); ++timer) {
		if (timer % 8 == 0) {
			++count;
			q.enQueue(timer);
			cout << timer << "s: 第" << count << "人进队." << endl;
		}
		if (timer % 25 == 0 && timer) {
			cout << "\t\t" << timer << "s: 第" << q.front() / 8 + 1 << "人出队." << endl;
			q.deQueue();
		}
	}
	cout << "\t\t该窗口排队人数已达到50人！请分流！" << endl; 
	cout << "\t队首人员于" << q.front() << "s入队" << endl; 
	cout << "\t队尾人员于" << q.back() << "s入队" << endl;
	Queue<int> q1(q), q2;
	q1.output();
	q2 = q1;
	q2.output();
	return 0;
}
