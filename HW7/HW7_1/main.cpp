#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cin;				using std::cout;
using std::endl;

int main () {
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << endl;
	Queue<int> q;
	for (int timer = 0, count = 0; !q.isFull(); ++timer) {
		if (timer % 8 == 0) {
			++count;
			q.enQueue(timer);
			cout << timer << "s: ��" << count << "�˽���." << endl;
		}
		if (timer % 25 == 0 && timer) {
			cout << "\t\t" << timer << "s: ��" << q.front() / 8 + 1 << "�˳���." << endl;
			q.deQueue();
		}
	}
	cout << "\t\t�ô����Ŷ������Ѵﵽ50�ˣ��������" << endl; 
	cout << "\t������Ա��" << q.front() << "s���" << endl; 
	cout << "\t��β��Ա��" << q.back() << "s���" << endl;
	Queue<int> q1(q), q2;
	q1.output();
	q2 = q1;
	q2.output();
	return 0;
}
