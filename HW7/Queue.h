template <class T>
class Queue
{
public:
	//�˴����size_type�����Ͷ���

	Queue();		//default constructor
	Queue(const Queue& q);	//copy constructor
	~Queue();		//destructor

	Queue& operator=(const Queue&);		//��ֵ����������ض���

	bool enQueue(T);	//����
	bool deQueue();		//����

	T front()const;	//���ض���Ԫ�ص�ֵ
	T back()const;	//���ض�βԪ�ص�ֵ

	size_type size()const;		//�˴�ʹ��ǰ�涨�������size_type
	bool isEmpty(void) const;	//�ж϶����Ƿ�Ϊ��
	bool isFull(void) const;	//�ж϶����Ƿ�����

	void output(void)const;		//�������
private:
	struct node{
		T val;
		node *next;
	}*head, *rear;	//������βԪ��ָ��

	//�ڴ������
	void copyLink(node *);	//������������
	void freeLink();		//�ͷ�����������ռ�ռ�
};
