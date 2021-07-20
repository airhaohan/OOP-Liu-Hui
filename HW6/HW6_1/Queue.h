#ifndef GUARD_Queue_h
#define GUARD_Queue_h

struct Node {
	int val;	//��� 
	int timer;	//���ʱ�� 
	struct Node* next;
	Node (const int& num, const int& time) : val(num), timer(time), next(nullptr) {}
};

class Queue {
	public:
		Queue();	//constuctor
		
		//���Ӻͳ��� 
		void push_back (const int&, const int&);
		void front_pop();
		
		//���ʶ���ͷβԪ�� 
		Node* front() const { return Front; }
		Node* back() const { return Back; }
		
		//�ж϶��пպ��� 
		bool empty () const { return Front == nullptr; }
		bool full () const { return count == 50; }
		
		void output () const ; //������� 
		int size() const { return count; }	//��ȡ����Ԫ�ظ��� 
		
	private:
		int count;
		//��ͷ�ڵ㣬���з�ΧΪ[Front, Back]������ 
		Node *Front;
		Node *Back;
};

#endif
#pragma once
