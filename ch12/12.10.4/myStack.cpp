#include "myStack.h"


myStack::myStack(int n)
{
	size = n;
	pitems = new Item[size];
	top = -1;

}

myStack::myStack(const myStack & s)
{
	size = s.size;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = s.pitems[i];
	top = s.top;
}

myStack::~myStack()
{
	delete[]pitems;
}

bool myStack::isempty() const
{
	return top == -1;
}

bool myStack::isfull() const
{
	return top == (size - 1);
}

bool myStack::push(const Item & item)
{
	if (isfull())
		return false;
	top++;
	pitems[top] = item;
	return true;
}

bool myStack::pop(Item & item)
{
	if (isempty())
		return false;
	item = pitems[top];
	top--;
	return true;
}

myStack & myStack::operator=(const myStack & s)
{
	if (this == &s)
		return *this;
	delete[]pitems;
	size = s.size;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = s.pitems[i];
	top = s.top;
	return *this;
}
