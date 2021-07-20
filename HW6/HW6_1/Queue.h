#ifndef GUARD_Queue_h
#define GUARD_Queue_h

struct Node {
	int val;	//序号 
	int timer;	//入队时间 
	struct Node* next;
	Node (const int& num, const int& time) : val(num), timer(time), next(nullptr) {}
};

class Queue {
	public:
		Queue();	//constuctor
		
		//进队和出队 
		void push_back (const int&, const int&);
		void front_pop();
		
		//访问队列头尾元素 
		Node* front() const { return Front; }
		Node* back() const { return Back; }
		
		//判断队列空和满 
		bool empty () const { return Front == nullptr; }
		bool full () const { return count == 50; }
		
		void output () const ; //输出队列 
		int size() const { return count; }	//获取队列元素个数 
		
	private:
		int count;
		//无头节点，队列范围为[Front, Back]闭区间 
		Node *Front;
		Node *Back;
};

#endif
#pragma once
