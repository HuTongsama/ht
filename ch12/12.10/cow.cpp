#include"cow.h"

Cow::Cow():name(""),hobby(nullptr),weight(0.0)
{
}
Cow::Cow(const char * nm, const char *ho, double wt)
{
	int len = 0;
	for (; len < 20; len++)
	{
		if (nm[len])
			name[len] = nm[len];
		else
			break;
	}
	if (20 == len)
		name[19] = '\0';
	else
		name[len] = '\0';
	len = strlen(ho) + 1;
	hobby = new char[len];
	strcpy(hobby, ho);
	weight = wt;
}
Cow::Cow(const Cow &c)
{
	strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
Cow::~Cow()
{
	delete[]hobby;
	std::cout << name << " is destroyed!" << std::endl;
}
Cow &Cow::operator=(const Cow &c)
{
	if (this == &c)
		return *this;
	delete[]hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(name, c.name);
	strcpy(hobby, c.hobby);
	weight = c.weight;
}
void Cow::ShowCow()const
{
	if (name[0])
	{
		std::cout << "Name:" << name << '\n';
		std::cout << "Hobby:" << hobby << '\n';
		std::cout << "Weight:" << weight << std::endl;
	}
	else
		std::cout << "Missing information!" << std::endl;
}
