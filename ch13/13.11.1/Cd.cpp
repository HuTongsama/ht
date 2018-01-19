#include "Cd.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
Cd::Cd(char * s1, char * s2, int n, double x)
{
	if (strlen(s1) <= 49)
		strcpy(performers, s1);
	else
		cout << "Wrong string size!" << endl;
	if (strlen(s2) <= 19)
		strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "CD information: \n";
	cout << "Performer: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	strcpy(this->performers, d.performers);
	strcpy(this->label, d.label);
	this->selections = d.selections;
	this->playtime = d.playtime;
	
	return *this;
}

Classic::Classic(char * s1, char * s2, char * s3, int n, double x):Cd(s1,s2,n,x)
{
	if (strlen(s3) <= 19)
		strcpy(mainSong, s3);
	else
		cout << "Wrong string size!" << endl;
}

Classic::Classic(const Classic & c):Cd(c)
{
	strcpy(mainSong, c.mainSong);
}

Classic::Classic():Cd()
{
	mainSong[0] = '\0';
}

Classic::~Classic()
{
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Main Song: " << mainSong << endl;
}

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	strcpy(mainSong, c.mainSong);
	return *this;
}
