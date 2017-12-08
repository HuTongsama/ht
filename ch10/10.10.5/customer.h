#pragma once
struct customer
{
	char fullname[35];
	double payment;
};
template<typename item>
class Stack
{
public:
	Stack(unsigned int n=1);
	~Stack();
	void push(item e);
	item pop();
	

private:
	item *sp=nullptr;
	unsigned int capacity;
	unsigned int pos = 0;
};


template<typename item>
inline Stack<item>::Stack(unsigned int n)
{
	capacity = n;
	sp = new item[n];
}

template<typename item>
inline void Stack<item>::push(item e)
{
	*(sp + pos) = e;
	pos++;
}
template<typename item>
inline item Stack<item>::pop()
{
	item tmp = *(sp + pos-1);
	pos--;
	return tmp;
}
template<typename item>
inline Stack<item>::~Stack()
{
	delete[]sp;
	sp = nullptr;
}
