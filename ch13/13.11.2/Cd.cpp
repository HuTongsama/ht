#include "Cd.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
Cd::Cd(char * s1, char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete[]performers;
	delete[]label;
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
	delete[]performers;
	delete[]label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(this->performers, d.performers);
	strcpy(this->label, d.label);
	this->selections = d.selections;
	this->playtime = d.playtime;
	
	return *this;
}

Classic::Classic(char * s1, char * s2, char * s3, int n, double x):Cd(s1,s2,n,x)
{
	mainSong = new char[strlen(s3) + 1];
	strcpy(mainSong, s3);
}

Classic::Classic(const Classic & c):Cd(c)
{
	mainSong = new char[strlen(c.mainSong) + 1];
	strcpy(mainSong, c.mainSong);
}

Classic::Classic():Cd()
{
	mainSong = nullptr;
}

Classic::~Classic()
{
	delete[]mainSong;
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
	delete[]mainSong;
	mainSong = new char[strlen(c.mainSong) + 1];
	strcpy(mainSong, c.mainSong);
	return *this;
}
