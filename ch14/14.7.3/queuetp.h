#pragma once

template<typename T>
class QueueTp 
{
private:
	struct Node
	{
		T item;
		Node* next;
	};
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTp(const QueueTp & qt):qsize(0) {}
	QueueTp & operator=(const QueueTp & qt) { return *this; }
public:
	QueueTp(int qs = Q_SIZE);
	~QueueTp();
	bool isempty()const;
	bool isfull() const;
	int queuecount()const;
	bool enqueue(const T &item);
	bool dequeue(T &item);
	void clear();
	T operator[](int index);
};

template<typename T>
inline QueueTp<T>::QueueTp(int qs) :
	front(nullptr), rear(nullptr), items(0), qsize(qs)
{
}

template<typename T>
inline QueueTp<T>::~QueueTp()
{
	Node *temp = front;
	while (front != nullptr)
	{
		front = front->next;
		delete temp;
	}
}

template<typename T>
inline bool QueueTp<T>::isempty() const
{
	return items == 0;
}

template<typename T>
inline bool QueueTp<T>::isfull() const
{
	return items == qsize;
}

template<typename T>
inline int QueueTp<T>::queuecount() const
{
	return items;
}

template<typename T>
inline bool QueueTp<T>::enqueue(const T & item)
{
	if (isfull())
		return false;
	Node *add = new Node;
	add->item = item;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}
template<typename T>
inline bool QueueTp<T>::dequeue(T & item)
{
	if(isempty())
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

template<typename T>
inline void QueueTp<T>::clear()
{
	Node *temp = front;
	while (front != nullptr)
	{
		front = front->next;
		delete temp;
		items--;
	}
	rear = nullptr;
}

template<typename T>
inline T QueueTp<T>::operator[](int index)
{
	Node *temp = front;
	if (index < items)
	{
		for (int i = 0; i != index; i++)
		{
			temp = temp->next;
		}
		return temp->item;
	}
	else
		cout << "Wrong index!\n";
	return NULL;
}
