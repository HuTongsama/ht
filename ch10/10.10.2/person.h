#pragma once
#include<string>
#include<iostream>

using namespace std;

class Person
{
public:
	Person() { lname = ""; fname[0] = '\0'; };//#1
	Person(const string &ln, const char * fn = "Heyyou");//#2
	~Person();

	//the following methods display lname and fname
	void show()const;//firstname lastname format
	void FormalShow()const;//lastname,firstname format

private:
	static const int LIMIT = 25;
	string lname;//Person's last name
	char fname[LIMIT];//Person's first name

};


inline Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	int i;
	for (i = 0; i < LIMIT&&fn[i]; i++)
		fname[i] = fn[i];

	if (i + 1 < LIMIT)
		for (int j = i + 1; j < LIMIT; j++)
			fname[i] = '\0';
	else
		fname[i - 1] = '\0';
}

Person::~Person()
{
}

inline void Person::show() const
{
	cout << fname << ' '<<lname << endl;
}

inline void Person::FormalShow() const
{
	cout << lname << ',' << fname << endl;
}
