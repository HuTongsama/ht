#include"string2.h"
#include<cstring>
#include<cctype>
using std::cin;
using std::cout;
String::String()
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

String::String(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

String::String(const String & s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	delete[]str;
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) && isupper(str[i]))
			str[i]=tolower(str[i]);
	}
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) && islower(str[i]))
			str[i]=toupper(str[i]);
	}
}

int String::has(char ch)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ch)
			count++;
	}
	return count;
}

String & String::operator=(const String & s)
{
	if (this == &s)
		return *this;
	delete[]str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;

}

String & String::operator=(const char *s)
{
	delete[]str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}

String String::operator+(const String & s) const
{
	char *add;
	int addLen = len + s.len;
	add = new char[addLen + 1];
	int pos = 0;
	while (str[pos])
	{
		add[pos] = str[pos];
		pos++;
	}
	while (s.str[pos-len])
	{
		add[pos] = s.str[pos - len];
		pos++;
	}
	add[pos] = '\0';
	String result(add);
	delete[]add;
	return result;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	return str[i];
}

String operator+(const char * s1, const String & s2)
{
	return String(s1) + s2;
}

bool operator<(const String & s1, const String & s2)
{
	return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String & s1, const String & s2)
{
	return (strcmp(s1.str, s2.str) > 0);
}

bool operator==(const String & s1, const String & s2)
{
	return (strcmp(s1.str, s2.str) == 0);
}

ostream & operator<<(ostream & os, const String & s)
{
	os << s.str;
	return os;
}

istream & operator>>(istream & is, String & s)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		s = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}
