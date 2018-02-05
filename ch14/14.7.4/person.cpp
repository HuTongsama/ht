#include "person.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;
void Person::Show() const
{
	cout << "name: "
		<< fname << ',' << lname << endl;
}

void Person::Set()
{
	cout << "Enter first name: ";
	getline(cin, fname);
	cout << "Enter last name: ";
	getline(cin, lname);
	while (cin.get() != '\n')
		continue;
}

void Gunslinger::Show() const
{
	Person::Show();
	cout << "Gun_time: " << gtime << endl;
	cout << "nick: " << nick << endl;
}

void Gunslinger::Set()
{
	Person::Set();
	cout << "Enter the time of getting out a gun: ";
	cin >> gtime;
	cout << "Enter the number of nick: ";
	cin >> nick;
	while (cin.get() != '\n')
		continue;
}

void PokerPlayer::Show() const
{
	Person::Show();
	cout << "The number of the card: " <<Draw()<< endl;
}

int PokerPlayer::Draw()const
{
	return (rand() % 52 + 1);
}

double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Show() const
{
	Gunslinger::Show();
	cout << "The number of the card: " << Cdraw()<< endl;
}

void BadDude::Set()
{
	Gunslinger::Set();
}
