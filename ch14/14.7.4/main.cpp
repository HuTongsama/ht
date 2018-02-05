#include<iostream>
#include"person.h"
const int SIZE = 5;

using namespace std;

int main() {
	
	srand(time(0));
	Person *lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "p:pokerplayer   g:gunslinger  "
			<< "b:baddude  q: quit\n";
		cin >> choice;
		while (strchr("pgbq", choice) == NULL)
		{
			cout << "Please enter a w,s,t,or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'p':
		{
			lolas[ct] = new PokerPlayer;
			break;
		}
		case 'g':
		{
			lolas[ct] = new Gunslinger;
			break;
		}
		case 'b':
		{
			lolas[ct] = new BadDude;
			
		}
		default:
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	for (int i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (int i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	
	system("pause");
}
