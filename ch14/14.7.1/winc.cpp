#include "winec.h"
#include<iostream>
Wine::Wine(const char * l, int y, const int yr[], const int bot[]):
	name(l),years(y)
{
	p.first() = ArrayInt(yr,years);
	p.second() = ArrayInt(bot, years);
}

Wine::Wine(const char * l, int y) :name(l), years(y)
{
	p.first() = ArrayInt(years);
	p.second() = ArrayInt(years);
}

int Wine::sum() const
{
	return p.second().sum();
}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	cout << "Enter " << name << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> p.first()[i];
		cout << "Enter bottles for that year: ";
		cin >> p.second()[i];
	}
}

void Wine::Show()const
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Wine: " << name << endl;
	cout << "\tYear\tBottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << '\t' << p.first()[i] << '\t' << p.second()[i] << endl;
	}
}
