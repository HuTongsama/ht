#pragma once

//This queue will contain Customer items
class Customer
{
public:
	Customer() { arrive = processtime = 0; }
	~Customer() {}

	void set(long when);
	long when()const { return arrive; }
	int ptime()const { return processtime; }
private:
	long arrive;//arrival time for customer
	int processtime;//processing time for customer
};
typedef Customer Item;
class Queue
{
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull() const;
	int queuecount()const;
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
	void clear();
private:
	struct Node
	{
		Item item; 
		Node * next;
	};
	enum { Q_SIZE = 10 };

	Node *front;	//pointer to front of Queue
	Node *rear;		//pointer to rear of Queue
	int items;		//current number of items in Queue
	const int qsize;//maximum number of items in Queue

	//preemptive definitions to prevent public copying
	Queue(const Queue &q) :qsize(0) {}
	Queue &operator=(const Queue & q) { return *this; }
};
