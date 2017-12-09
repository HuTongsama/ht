#pragma once
#include<iostream>

class Plorg
{
public:
	Plorg(const char *name="Plorga",int ci=50);
	void resetCI(int ci);
	void show()const;
	~Plorg();

private:
	static const int Len = 20;
	char *_name = new char[Len];
	int CI;
};

Plorg::Plorg(const char *name,int ci)
{
	CI = ci;
	int i = 0;
	while (i < Len&&*name)
	{
		_name[i] = name[i];
		i++;
	}
	if (i < Len)
		for (int j = i; j < Len; j++)
			_name[j] = '\0';
	else
		_name[i - 1] = '\0';

}

inline void Plorg::resetCI(int ci)
{
	CI = ci;
}

inline void Plorg::show() const
{
	std::cout << "Name: " << _name << '\t';
	std::cout << "CI: " << CI << std::endl;
}

Plorg::~Plorg()
{
	delete[]_name;
	_name = nullptr;
}
