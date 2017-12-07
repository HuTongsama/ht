#pragma once
#include<iostream>
using namespace std;

class Golf
{
public:
	Golf(const char* name="",int hc=0);
	~Golf();
	//function solicits name and handicap from user
	//and sets the members of *this to the values 
	//entered returns 1 if name is entered,0 if
	//name  is empty string
	int setgolf();
	//function resets handicap to new value
	void setHandicap(int hc);
	//function displays contents of members
	void showgolf()const;

private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
};


inline Golf::Golf(const char * name, int hc)
{
	int i = 0;
	while (i < Len&&name[i])
	{
		fullname[i] = name[i];
		i++;
	}
	if (i < Len)
		for (int j = i; j < Len; j++)
			fullname[j] = '\0';
	else
		fullname[i - 1] = '\0';

	handicap = hc;
}



Golf::~Golf()
{
}

inline int Golf::setgolf()
{
	char *tempName = new char[Len];
	int tempHp;
	cout << "Enter a name: ";
	cin.getline(tempName, Len);
	if (tempName[0] == '\0')
		return 0;
	cout << "Enter the handicap: ";
	(cin >> tempHp).get();
	Golf tempGolf(tempName, tempHp);
	for (int i = 0; i < Len; i++)
		this->fullname[i] = tempGolf.fullname[i];
	this->handicap = tempGolf.handicap;
	delete[]tempName;
	tempName = nullptr;
	return 1;
}

inline void Golf::setHandicap(int hc)
{
	this->handicap = hc;
}

inline void Golf::showgolf() const
{
	if (fullname[0] == '\0')
		return;
	cout << "Name: " << this->fullname << '\t';
	cout << "Handicap: " << this->handicap << endl;
}
