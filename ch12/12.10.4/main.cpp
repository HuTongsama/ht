#include<iostream>
#include"myStack.h"

using namespace std;

void Push(myStack &s)
{
	while (!s.isfull())
		s.push(rand());
}

void Pop(myStack s)
{
	Item tmp;
	while (!s.isempty())
	{
		s.pop(tmp);
		cout << tmp << '\t';
	}
}
int main() {
	myStack s1, s2(5),s3;
	srand(time(0));
	Push(s1);
	Push(s2);
	Push(s3);
	cout << "S1: ";
	Pop(s1);
	cout << endl;
	cout << "S2: ";
	Pop(s2);
	cout << endl;
	cout << "After S2=S3:\nS2: ";
	s2 = s3;
	Pop(s2);
	cout << endl;
	system("pause");
}
