#include "Queue.h"
#include <iostream>
#include <stdexcept>

using std::cin;			using std::cout;
using std::endl;		using std::domain_error;

Queue::Queue () : count(0), Front(nullptr), Back(nullptr) {}

void Queue::push_back (const int& num, const int& time) {
	//���FrontΪ��ָ�룬����ӵ�һ��Ԫ�� 
	if (Front == nullptr)
		Front = Back = new Node(num, time);
	else
		Back = Back->next = new Node(num, time);
	++count;
}

void Queue::front_pop () {
	//��ֹ����Ϊ�� 
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
			cout << "��" << temp->val << "����" << temp->timer << "s����" << endl;
			temp = temp->next;
		} while (temp != nullptr);
	}
}

