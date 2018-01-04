#pragma once
typedef unsigned long Item;
class myStack
{
private:
	enum { MAX = 10 };//constant specific to class
	Item *pitems;//holds stack items
	int size;//number of elements in stack
	int top;//index for top stack item
public:
	myStack(int n = MAX);//creates stack with n elements
	myStack(const myStack& s);
	~myStack();
	bool isempty()const;
	bool isfull()const;
	//push() returns false if stack already is full,true otherwise
	bool push(const Item &item);//add item to stack
	//pop() returns false if stack already is empty,true otherwise
	bool pop(Item & item);//pop top to item
	myStack & operator=(const myStack &s);
};
