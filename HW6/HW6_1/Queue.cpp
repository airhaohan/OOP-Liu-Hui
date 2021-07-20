#include "Queue.h"
#include <iostream>
#include <stdexcept>

using std::cin;			using std::cout;
using std::endl;		using std::domain_error;

Queue::Queue () : count(0), Front(nullptr), Back(nullptr) {}

void Queue::push_back (const int& num, const int& time) {
	//如果Front为空指针，则添加第一个元素 
	if (Front == nullptr)
		Front = Back = new Node(num, time);
	else
		Back = Back->next = new Node(num, time);
	++count;
}

void Queue::front_pop () {
	//防止队列为空 
	if (Front == nullptr)
		throw domain_error("The Queue is empty!");
	else {
		Node* temp = Front;
		Front = Front->next;
		delete temp;
		--count;
	}
}

void Queue::output () const {
	if (Front == nullptr)
		throw domain_error("The Queue is empty!");
	else {
		Node* temp = Front;
		do {
			cout << "第" << temp->val << "人于" << temp->timer << "s进队" << endl;
			temp = temp->next;
		} while (temp != nullptr);
	}
}

