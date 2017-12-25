#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<cstring>

class Cow
{
public:
	Cow();
	Cow(const char * nm, const char *ho, double wt);
	Cow(const Cow &c);
	~Cow();
	Cow &operator=(const Cow &c);

	void ShowCow()const;
private:
	char name[20];
	char *hobby;
	double weight;
};
