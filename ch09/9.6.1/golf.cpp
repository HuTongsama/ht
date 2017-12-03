#include "golf.h"
#include<iostream>

using namespace std;

void setgolf(golf & g, const char * name, int hc)
{
	int count = 0;
	while (count < Len&&(*name) != '\0')
	{
		g.fullname[count] = *name;
		count++;
		name++;
	}
	if (count + 1 < Len)
		g.fullname[count + 1] = '\0';
	g.handicap = hc;

}

int setgolf(golf & g)
{
	cout << "Enter a name:\n";
	cin.getline(g.fullname, Len);
	if (g.fullname[0] == '\0')
		return 0;
	cout << "Enter the handicap:\n";
	(cin >> g.handicap).get();
	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << "Name: " << g.fullname << '\t';
	cout << "Handicap: " << g.handicap << endl;
}
