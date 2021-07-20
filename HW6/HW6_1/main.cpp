#include <iostream>
#include <stdexcept>
#include "Queue.h"

using std::cin;				using std::cout;
using std::endl;			using std::domain_error;

int main () {
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << endl;
	Queue QueueOfDine;
	for (int timer = 0, count = 0; !QueueOfDine.full(); ++timer) {
		if (timer % 8 == 0) {
			++count;
			QueueOfDine.push_back(count, timer);
			cout << timer << "s: ��" << count << "�˽���." << endl;
		}
		if (timer % 25 == 0 && timer) {
			try {
				cout << "\t\t" << timer << "s: ��" << QueueOfDine.front()->val << "�˳���." << endl;
				QueueOfDine.front_pop();
			}
			catch (domain_error e) {
				cout << e.what() << endl;
			}
		}
	}
	cout << "\t\t�ô����Ŷ������Ѵﵽ50�ˣ��������" << endl; 
	cout << "\t������Ա��" << QueueOfDine.front()->timer << "s���" << endl; 
	cout << "\t��β��Ա��" << QueueOfDine.back()->timer << "s���" << endl; 
	cout << endl << "������� output ����" << endl;
	QueueOfDine.output(); 
	return 0;
}
