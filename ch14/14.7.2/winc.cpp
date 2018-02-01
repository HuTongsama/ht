#include "winec.h"
#include<iostream>
Wine::Wine(const char * l, int y, const int yr[], const int bot[]):
	std::string(l),years(y)
{
	PairArray::first() = ArrayInt(yr, years);
	PairArray::second() = ArrayInt(bot, years);
}

Wine::Wine(const char * l, int y) :std::string(l), years(y)
{
	PairArray::first() = ArrayInt(years);
	PairArray::second() = ArrayInt(years);
}

int Wine::sum() const
{
	return PairArray::second().sum();
}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	cout << "Enter " << Label() << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> PairArray::first()[i];
		cout << "Enter bottles for that year: ";
		cin >> PairArray::second()[i];
	}
}

void Wine::Show()const
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Wine: " << Label() << endl;
	cout << "\tYear\tBottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << '\t' << PairArray::first()[i] << '\t' << PairArray::second()[i] << endl;
	}
}
