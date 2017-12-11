#pragma once
#include<iostream>
template<typename item>
class List
{
public:
	List(unsigned int n = 0);
	~List();
	void addData(item n);
	bool isEmpty();
	bool isFull();
	void visit(void(*pf)(item &));
private:
	unsigned int capacity;
	unsigned int count = 0;
	item *p;
};

template<typename item>
List<item>::List(unsigned int n)
{
	capacity = n;
	p = new item[capacity];
}
template<typename item>
List<item>::~List()
{
	delete[]p;
	p = nullptr;
}

template<typename item>
void List<item>::addData(item n)
{
	if (isFull())
	{
		std::cout << "Can't add more data!\n";
		return;
	}
	p[count] = n;
	count++;
}
template<typename item>
bool List<item>::isEmpty()
{
	return count == 0;
}
template<typename item>
bool List<item>::isFull()
{
	return count == capacity;
}
template<typename item>
void List<item>::visit(void(*pf)(item &))
{
	for (int i = 0; i < count; i++)
		pf(p[i]);
}
