#ifndef GUARD_Queue_h
#define GUARD_Queue_h

#include <iostream>


template <class T>
class Queue
{
	struct node {
		T val;
		node* next;
		node (const int& v) : val(v), next(nullptr) {}	//constructor of node
	};
public:
	typedef size_t size_type;

	Queue () : head(nullptr), rear(nullptr) {	//default constructor
		std::cout << "default constructor called" << std::endl;
	}
	Queue (const Queue& q) {	//copy constructor
		copyLink(q.begin());
		std::cout << "copy constructor called" << std::endl;
	}
	~Queue () {		//destructor
		freeLink();
		std::cout << "destructor called" << std::endl;
	}

	Queue& operator=(const Queue&);		//赋值运算符的重载定义

	bool enQueue (T);		//进队
	bool deQueue ();		//出队

	T front () const { return head->val; }	//返回队首元素的值
	T back () const { return rear->val; }	//返回队尾元素的值

	size_type size () const;	//此处使用前面定义的类型size_type
	bool isEmpty (void) const { return head == nullptr; }	//判断队列是否为空 
	bool isFull (void) const { return size() == 50; } 		//判断队列是否已满

	void output (void) const;	//输出队列 
private:
	node *head, * rear;			//队列首尾元素指针

	//内存管理函数 
	void copyLink (node*);	//复制已有链表
	void freeLink ();		//释放已有链表所占空间
}; 


template <class T>
void Queue<T>::freeLink () {
	rear = nullptr;
	while (head != nullptr) {
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

template <class T>
void Queue<T>::copyLink (node* n) {
	if (n != head) {		//注意Queue的链表和被复制的链表是否是同一个链表 
		freeLink();
		node *temp1 = head = new node(n->val);
		node *temp2 = n;
		while (temp2->next != nullptr) {
			temp1->next = new node (temp2->next->val);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		rear = temp1;
	}
}

template <class T>
typename Queue<T>::size_type Queue<T>::size () const {
	if (head == nullptr)
		return 0;
	node *temp = head;
	Queue<T>::size_type count = 1;
	while (temp != rear) {
		++count;
		temp = temp->next;
	}
	return count;
}

template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T>& q) {
	if (&q != this) {
		freeLink();
		copyLink(q.head);
	}
	std::cout << "operator=() called" << std::endl;
	return *this;
}

template <class T>
bool Queue<T>::enQueue (T v) {
	if ((*this).isFull())
		return false;
	if (head == nullptr)
		head = rear = new node(v);
	else
		rear = rear->next = new node(v);
	return true;
}

template <class T>
bool Queue<T>::deQueue () {
	if (head == nullptr)
		return false;
	node *temp = head;
	head = head->next;
	delete temp;
	return true;
}

template <class T>
void Queue<T>::output (void) const {
	node *temp = head;
	int count = 0;
	while (temp != nullptr) {
		std::cout << temp->val << " ";
		++count;
		if (count % 10 == 0)
		std::cout << std::endl;
		temp = temp->next;
	}
	std::cout << std::endl;
}

#endif
#pragma once
