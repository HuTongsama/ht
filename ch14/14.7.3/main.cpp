#include"queuetp.h"
#include"workermi.h"
#include<iostream>

using namespace std;

const int SIZE = 5;

int main() {
	
	QueueTp<Worker *>qw(SIZE);
	Worker *lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s:singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w,s,t,or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
		{
			lolas[ct] = new Waiter;
			qw.enqueue(lolas[ct]);
			break;
		}
		case 's':
		{
			lolas[ct] = new Singer;
			qw.enqueue(lolas[ct]);
			break;
		}
		case 't':
		{
			lolas[ct] = new SingingWaiter;
			qw.enqueue(lolas[ct]);
		}
		default:
			break;
		}
		cin.get();
		qw[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	while (!qw.isempty())
	{
		Worker* temp;
		qw.dequeue(temp);
		cout << endl;
		temp->Show();
	}
	for (int i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";

	system("pause");
}
